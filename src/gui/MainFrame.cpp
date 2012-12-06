#include "MainFrame.h"
#include "ui_MainFrame.h"
#include "IProcessor.h"
#include "hangChuLi.h"
#include "gui/SourceWidget.h"
#include "gui/ResultWidget.h"
#include "ProcessWidget.h"
#include "ParamListWidget.h"
#include "KeywordsDB.h"
#include "HighlightDB.h"
#include "ui_AboutDialog.h"
#include "CompositeResourceWidget.h"
#include "ProcessThread.h"

#include <QDesktopServices>
#include <QApplication>
#include <QDir>
#include <QUrl>
#include <QMessageBox>


MainFrame::~MainFrame(){}

MainFrame::MainFrame(QWidget* parent)
    :QMainWindow(parent),
      SourceWidget_(new SourceWidget(this)),
      ResultWidget_(new ResultWidget(this)),
      ProcessWidget_(new ProcessWidget(this)),
      ParamListWidget_(new ParamListWidget(this)),
      keywordsCompositeResourceWidget_(new CompositeResourceWidget(&KeywordsDB::instance(),this)),
      highlightCompositeResourceWidget_(new CompositeResourceWidget(&HighlightDB::instance(),this)),
      shareString_(tr("\nSkFunTips"))
      {

    ui_.reset(new Ui::MainFrame());

    ui_->setupUi(this);

    ui_->verticalLayout->insertWidget(0,ParamListWidget_);
    ui_->verticalLayout->insertWidget(0,ProcessWidget_);


    keywordsCompositeResourceWidget_->setDescription(tr("keywords list,one keyword per line\nkeywords process will replace these words with random method\nthat hide your truely speaking int text"));
    highlightCompositeResourceWidget_->setDescription(tr("highlight regexp list\none regexp per line\nwill used to highlight result to warn unwanted word"));

    connect(
                ProcessWidget_,SIGNAL(chuLiGaiBian(ParamList)),
                ParamListWidget_,SLOT(canShuLieBiaoGaiBian(ParamList)));


    ui_->horizontalLayout_zhuYao->insertWidget(0,SourceWidget_);
    ui_->horizontalLayout_zhuYao->addWidget(ResultWidget_);

    ProcessWidget_->on_comboBox_currentIndexChanged(0);

    connect(SourceWidget_,SIGNAL(neiRongBianHua()),
            ProcessWidget_,SLOT(yuanGaiBian()));

    connect(ProcessWidget_,SIGNAL(yingGaiChuLi()),
            this,SLOT(executeProcess()));

    connect(&KeywordsDB::instance(),SIGNAL(chongZhi()),this,SLOT(executeProcess()));

    connect(ui_->action_tuiChu,SIGNAL(triggered()),this,SLOT(close()));

    connect(ui_->pushButton_gaoLiangCiKu,SIGNAL(clicked()),highlightCompositeResourceWidget_,SLOT(show()));

    connect(ui_->pushButton_guanJianCiKu,SIGNAL(clicked()),keywordsCompositeResourceWidget_,SLOT(show()));

    foreach(IProcessor *chuLi,ProcessWidget_->processorContainer()){
        connect(chuLi,SIGNAL(processPercent(int)),ui_->progressBar,SLOT(setValue(int)));
    }

    executeProcess();

}

void MainFrame::executeProcess(){

    bool tuiGuang=ui_->checkBox_tuiGuang->isChecked();

    IProcessor* dangQianChuLi=ProcessWidget_->dangQian();

    ResultType leiXing=dangQianChuLi->resultLeiXing();


    QStringList yuan=SourceWidget_->neiRong();


    if(tuiGuang && (leiXing!=STRING)){
        yuan.append(shareString_);
    }

    if(ProcessThread_ && ProcessThread_->isRunning()){
        return;
    }

    ProcessThread_.reset(new ProcessThread(yuan,dangQianChuLi));

    connect(ProcessThread_.get(),SIGNAL(finished()),this,SLOT(processFinished()));

    setEnabled(false);

    ProcessThread_->start();


}

void MainFrame::on_action_guanYu_triggered(){

    QDialog linShi(this);

    Ui::AboutDialog ui;
    ui.setupUi(&linShi);

    linShi.exec();

}

void MainFrame::on_pushButton_zaiCi_clicked(){

    SourceWidget_->sheZhiWenBen(ResultWidget_->kongJianWenBen());
}

void MainFrame::processFinished(){

    bool tuiGuang=ui_->checkBox_tuiGuang->isChecked();

    Result result=ProcessThread_->result();

    if(tuiGuang && (ProcessWidget_->dangQian()->resultLeiXing()==STRING)){
        QStringList linShi=result.string();
        linShi.append(shareString_);
        result.setString(linShi);
    }

    ResultWidget_->sheZhiResult(result);

    ui_->progressBar->setValue(0);

    setEnabled(true);
}

void MainFrame::on_action_bangZhu_triggered(){

    QString bangZhuLuJing=QApplication::instance()->applicationDirPath()
            +QDir::separator()+"bangZhu.html";

    if(!QFile::exists(bangZhuLuJing)){
        QMessageBox::critical(this,
                                     tr("help file bangZhu.html not exists"),
                                     tr("help file bangZhu.html not exists"));
        return;
    }

    bool Result=QDesktopServices::openUrl(QUrl("file:///"+bangZhuLuJing,QUrl::TolerantMode));

    if(!Result){

        QMessageBox::critical(this,
                              tr("open help failed"),
                              tr("open help failed"));
    }

}
