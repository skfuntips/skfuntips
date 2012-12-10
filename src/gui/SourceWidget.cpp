#include "SourceWidget.h"

#include <QApplication>
#include <QTextStream>
#include <QDebug>
#include <QClipboard>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

#include "ui_SourceWidget.h"
#include "hangChuLi.h"
#include "gongJu.h"

SourceWidget::~SourceWidget(){}

SourceWidget::SourceWidget(QWidget *parent):
    QGroupBox(parent){

    ui_.reset(new Ui::SourceWidget());
     ui_->setupUi(this);

     adjustSize();


     ui_->textEdit_shuRu->setLineWrapMode(QTextEdit::WidgetWidth);

     zhongWenHangZiShu_=ui_->spinBox_huanHangZiFuShu->value();

     connect(ui_->textEdit_shuRu,SIGNAL(textChanged()),
             this,SIGNAL(contentsChanged()));

     connect(ui_->groupBox_huanHang,SIGNAL(toggled(bool)),
             this,SLOT(qieHuanHuanHang(bool)));

     connect(ui_->radioButton_ziFuShuHuanHang,SIGNAL(toggled(bool)),
             this,SLOT(qieHuanHuanHang()));

     connect(ui_->radioButton_xianShiKuanDuHuanHang,SIGNAL(toggled(bool)),
             this,SLOT(qieHuanHuanHang()));

     connect(ui_->spinBox_huanHangZiFuShu,SIGNAL(valueChanged(int)),
             this,SLOT(qieHuanHuanHang()));
}

void SourceWidget::on_pushButton_jiaZaiWenJian_clicked(){
    setContents(wenJianWenBen(this));
    
}

void SourceWidget::setContents(const QString& wenBen){

    if (wenBen.isNull()) {
        return;
    }

    ui_->textEdit_shuRu->setPlainText(wenBen);

}

void SourceWidget::on_pushButton_jianQieBan_clicked(){

    setContents(jianQieBanWenBen(this));

}


void SourceWidget::qieHuanHuanHang(bool kongZhi){

    QTextEdit::LineWrapMode yuanLai=ui_->textEdit_shuRu->lineWrapMode();

    bool gaiBian=false;

    if (!kongZhi) {
       ui_-> textEdit_shuRu->setLineWrapMode(QTextEdit::NoWrap);
    }else if (ui_->radioButton_xianShiKuanDuHuanHang->isChecked()) {
        ui_->textEdit_shuRu->setLineWrapMode(QTextEdit::WidgetWidth);
    }else{
        Q_ASSERT(ui_->radioButton_ziFuShuHuanHang->isChecked());

        int benCiZiShu=ui_->spinBox_huanHangZiFuShu->value();

        QFontMetrics ziTiCeLiang=fontMetrics();

        int xiangSuKuan=ziTiCeLiang.averageCharWidth()*(benCiZiShu*2+1);

        ui_->textEdit_shuRu->setLineWrapMode(QTextEdit::FixedPixelWidth);

        ui_->textEdit_shuRu->setLineWrapColumnOrWidth(xiangSuKuan);

        gaiBian=(benCiZiShu!=zhongWenHangZiShu_);

        zhongWenHangZiShu_=benCiZiShu;
    }

    QTextEdit::LineWrapMode xianZai=ui_->textEdit_shuRu->lineWrapMode();

    if (gaiBian || (yuanLai!=xianZai)) {
        emit contentsChanged();
    }
}

QStringList SourceWidget::contents(){
    return kongJianWenBen(ui_->textEdit_shuRu->document());
}

void SourceWidget::resizeEvent(QResizeEvent* ){

    if (ui_->textEdit_shuRu->lineWrapMode()==QTextEdit::WidgetWidth) {
        emit contentsChanged();
    }
}

