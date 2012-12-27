#include "StringWidget.h"


#include "ui_StringWidget.h"

#include "param/StringParam.h"

StringWidget::~StringWidget(){}

StringWidget::StringWidget(QWidget * parent)
     :ParamWidget(parent){
    ui_.reset(new Ui::StringWidget());

      ui_->setupUi(this);

      connect(ui_->lineEdit,SIGNAL(textChanged(QString)),
		    this,SLOT(applyUi()));

     }

void StringWidget::applyUi(){
     StringParam* canShu=param<StringParam>();

     if (!canShu) {
	  return;
     }

     canShu->sheZhiZiFuChuan(ui_->lineEdit->text());


}


void StringWidget::applyParam(IParam *canShu){


     StringParam *stringParam=
         qobject_cast<StringParam*>(canShu);

     Q_ASSERT(stringParam);

     setTitle(canShu->name());
     ui_->label_shuoMing->setText(canShu->description());

     ui_->lineEdit->setText(stringParam->ziFuChuan());

     setTitle(stringParam->name());

}


