#include "IntRangeWidget.h"
#include "IntRangeParam.h"
#include "ui_IntRangeWidget.h"


IntRangeWidget::~IntRangeWidget(){}

IntRangeWidget::IntRangeWidget(QWidget *parent)
:ParamWidget(parent){
    ui_.reset(new Ui::IntRangeWidget());

    ui_->setupUi(this);

    connect(ui_->spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(applyUi()));

}

void IntRangeWidget::applyParam(IParam* IParam){

    IntRangeParam *canShu=qobject_cast<IntRangeParam*>(IParam);

    Q_ASSERT(canShu);

   ui_-> spinBox->setMinimum(canShu->xiaXian());
   ui_-> spinBox->setMaximum(canShu->shangXian());
   ui_-> spinBox->setValue(canShu->shuZhi());

   ui_-> label_xiaXian->setText(QString::number(canShu->xiaXian()));
    ui_->label_shangXian->setText(QString::number(canShu->shangXian()));
    setTitle(canShu->name());
    ui_->label_shuoMing->setText(canShu->description());
}

void IntRangeWidget::applyUi(){
    IntRangeParam *canShu=param<IntRangeParam>();

    if (!canShu) {
        return;
    }

    canShu->sheZhiShuZhi(ui_->spinBox->value());

}

