#include "ProcessWidget.h"
#include "ui_ProcessWidget.h"
#include "IProcessor.h"


ProcessWidget::~ProcessWidget(){}

ProcessWidget::ProcessWidget(QWidget *parent)
    :QGroupBox(parent){

    ui_.reset(new Ui::ProcessWidget());

    ui_->setupUi(this);


    foreach(IProcessor *chuLi,chuLiRongQi_){
        ui_->comboBox->addItem(chuLi->name());

        connect(chuLi,SIGNAL(paramDirty()),
                this,SLOT(canShuGaiBian()));
    }

    connect(ui_->checkBox_yuanShiShi,SIGNAL(stateChanged(int)),
            this,SLOT(yuanGaiBian()));

    connect(ui_->checkBox_canShuShiShi,SIGNAL(stateChanged(int)),
            this,SLOT(canShuGaiBian()));

    connect(ui_->pushButton_chuLi,SIGNAL(clicked(bool)),
            this,SIGNAL(yingGaiChuLi()));

}

void ProcessWidget::on_comboBox_currentIndexChanged(int suoYin){

    if(suoYin==-1){
        return;
    }

    Q_ASSERT(suoYin<int(chuLiRongQi_.size()));

    IProcessor *chuLi=chuLiRongQi_[suoYin];

    ui_->label->setText(chuLi->description());

    emit processorChanged(chuLi->paramList());

    emit yingGaiChuLi();
}

void ProcessWidget::canShuGaiBian(){
    bool shiShiYuLan=
        (ui_->checkBox_canShuShiShi->checkState()==Qt::Checked);

    if (shiShiYuLan) {
        emit yingGaiChuLi();
    }

}

void ProcessWidget::yuanGaiBian(){
    
    if (ui_->checkBox_yuanShiShi->checkState()==Qt::Checked) {
        emit yingGaiChuLi();
    }
}

IProcessor* ProcessWidget::dangQian(){
    int suoYin=ui_->comboBox->currentIndex();

    Q_ASSERT(suoYin>=0 && suoYin<int(chuLiRongQi_.size()));

    return chuLiRongQi_[suoYin];

}

void ProcessWidget::kongZhiAnNiu(){
    bool b1=(ui_->checkBox_yuanShiShi->checkState()==Qt::Checked),
         b2=(ui_->checkBox_canShuShiShi->checkState()==Qt::Checked);

    ui_->pushButton_chuLi->setEnabled(!(b1&&b2));
}

