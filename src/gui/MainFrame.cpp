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


    keywordsCompositeResourceWidget_->setWindowTitle(tr("confit keywords db"));
    keywordsCompositeResourceWidget_->setDescription(tr("keywords list,one keyword per line. keywords process will replace these words with random method that hide your truely speaking int text"));
    highlightCompositeResourceWidget_->setWindowTitle(tr("confit highlight db"));
    highlightCompositeResourceWidget_->setDescription(tr("highlight regexp list, one regexp per line .will used to highlight result to warn unwanted word"));

    connect(
                ProcessWidget_,SIGNAL(processorChanged(ParamList)),
                ParamListWidget_,SLOT(paramListChanged(ParamList)));


    ui_->horizontalLayout_zhuYao->insertWidget(0,SourceWidget_);
    ui_->horizontalLayout_zhuYao->addWidget(ResultWidget_);

    ProcessWidget_->on_comboBox_currentIndexChanged(0);

    connect(SourceWidget_,SIGNAL(contentsChanged()),
            ProcessWidget_,SLOT(yuanGaiBian()));

    connect(ProcessWidget_,SIGNAL(yingGaiChuLi()),
            this,SLOT(executeProcess()));

    connect(&KeywordsDB::instance(),SIGNAL(reset()),this,SLOT(executeProcess()));

    connect(ui_->action_quit,SIGNAL(triggered()),this,SLOT(close()));

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

    ResultType leiXing=dangQianChuLi->resultType();


    QStringList yuan=SourceWidget_->contents();


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

void MainFrame::on_action_about_triggered(){

    QDialog linShi(this);

    Ui::AboutDialog ui;
    ui.setupUi(&linShi);

    linShi.exec();

}

void MainFrame::on_pushButton_again_clicked(){

    SourceWidget_->setContents(ResultWidget_->contents());
}

void MainFrame::processFinished(){

    bool tuiGuang=ui_->checkBox_tuiGuang->isChecked();

    Result result=ProcessThread_->result();

    bool stringResult=(ProcessWidget_->dangQian()->resultType()==STRING);

    if(tuiGuang && stringResult){
        QStringList linShi=result.string();
        linShi.append(shareString_);
        result.setString(linShi);
    }

    ui_->pushButton_again->setEnabled(stringResult);

    ResultWidget_->setResult(result);

    ui_->progressBar->setValue(0);

    setEnabled(true);
}

void MainFrame::on_action_help_triggered(){

    QString bangZhuLuJing=QApplication::instance()->applicationDirPath()
            +QDir::separator()+"help.html";

    if(!QFile::exists(bangZhuLuJing)){
        QMessageBox::critical(this,
                                     tr("help file help.html not exists"),
                                     tr("help file help.html not exists"));
        return;
    }

    bool Result=QDesktopServices::openUrl(QUrl("file:///"+bangZhuLuJing,QUrl::TolerantMode));

    if(!Result){

        QMessageBox::critical(this,
                              tr("open help failed"),
                              tr("open help failed"));
    }

}
