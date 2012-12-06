#include "ParamWidget.h"
#include "IParam.h"


ParamWidget::ParamWidget(QWidget* parent)
    :QGroupBox(parent),bangDingCanShu_(NULL){
        xinHaoYuan_=true;
    }

void ParamWidget::bindParam(IParam* canShu){

    if (bangDingCanShu_!=NULL) {
        disconnectSignal();
    }

    if (!canShu) {
        return;
    }

    if (canShu==bangDingCanShu_) {
        return;
    }


    applyParam(canShu);

    bangDingCanShu_=canShu;

    connectSignal();

}

void ParamWidget::connectSignal(){

    Q_ASSERT(bangDingCanShu_);

    connect(bangDingCanShu_,SIGNAL(destroyed()),
            this,SLOT(disconnectSignal()));

    connect(bangDingCanShu_,SIGNAL(valueChanged(IParam*)),
            this,SLOT(paramChanged(IParam*)));

}

        
void ParamWidget::paramChanged(IParam* gaiBian){

    Q_ASSERT(gaiBian==bangDingCanShu_);

    applyParam(bangDingCanShu_);
}

void ParamWidget::disconnectSignal(){

    Q_ASSERT(bangDingCanShu_);

    disconnect(bangDingCanShu_,0,this,0);
    disconnect(this,0,bangDingCanShu_,0);

    bangDingCanShu_=NULL;

}

