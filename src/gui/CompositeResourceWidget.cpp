#include "CompositeResourceWidget.h"
#include "ui_CompositeResourceWidget.h"
#include "CompositeResource.h"
#include "hangChuLi.h"

#include <QTextStream>
#include <QFile>

CompositeResourceWidget::~CompositeResourceWidget(){}



CompositeResourceWidget::CompositeResourceWidget(CompositeResource* ziYuan,QWidget *parent):
    QDialog(parent){

    ui_.reset(new Ui::CompositeResourceWidget());
    ui_->setupUi(this);

    Q_ASSERT(ziYuan);

    ziYuan_=ziYuan;

    connect(ui_->buttonBox_ok,SIGNAL(accepted()),this,SLOT(saveFile()));

    connect(ui_->radioButton_neiZhi,SIGNAL(toggled(bool)),this,SLOT(togglePart()));

    connect(ui_->radioButton_waiZhi,SIGNAL(toggled(bool)),this,SLOT(togglePart()));

    loadFile();

}


void CompositeResourceWidget::loadFile(){

    ui_->plainTextEdit_waiZhi->clear();

    tianChong(ui_->plainTextEdit_waiZhi->document(),ziYuan_->content(CompositeResource::EXTERNAL));

}

void CompositeResourceWidget::saveFile(){

    QFile wenJian(ziYuan_->external());

    bool Result=wenJian.open(QIODevice::WriteOnly);

    Q_ASSERT(Result);

    QTextStream ziFuLiu(&wenJian);

    ziFuLiu.setCodec("UTF-8");

    QStringList neiRong=kongJianWenBen(ui_->plainTextEdit_waiZhi->document());

    foreach(const QString& hang,neiRong){

        ziFuLiu<<hang<<'\n';
    }

}

void CompositeResourceWidget::showEvent(QShowEvent *e){
    loadFile();
    QDialog::showEvent(e);
}

void CompositeResourceWidget::togglePart(){
    if(ui_->radioButton_neiZhi->isChecked()){
        ziYuan_->setType(CompositeResource::INTERNAL);
    }else{
        Q_ASSERT(ui_->radioButton_waiZhi->isChecked());
        ziYuan_->setType(CompositeResource::EXTERNAL);
    }
}


void CompositeResourceWidget::on_groupBox_toggled(bool xuanZhong){

    if(xuanZhong){
        togglePart();
    }else{
        ziYuan_->setType(CompositeResource::ALL);
    }
}

void CompositeResourceWidget::setDescription(const QString &shuoMing){
    ui_->label->setText(shuoMing);
}
