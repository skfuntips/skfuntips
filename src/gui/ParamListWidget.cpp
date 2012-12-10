#include "ParamListWidget.h"

#include "param/IntRangeParam.h"
#include "param/SeedParam.h"
#include "param/FontParam.h"
#include "ui_ParamListWidget.h"
#include "IntRangeWidget.h"
#include "FontWidget.h"
#include "SeedWidget.h"
#include "IProcessor.h"




static ParamWidget* yiGe(IParam* IParam){

    ParamWidget *fanHuiZhi=NULL;

    if(qobject_cast<IntRangeParam*>(IParam)){
        fanHuiZhi=new IntRangeWidget();
    }else if(qobject_cast<SeedParam*>(IParam)){
        fanHuiZhi=new SeedWidget();
    }else if(qobject_cast<FontParam*>(IParam)){
        fanHuiZhi=new FontWidget();
    }

    fanHuiZhi->bindParam(IParam);

    Q_ASSERT(fanHuiZhi);

    return fanHuiZhi;

}

ParamListWidget::ParamListWidget(QWidget *parent)
    :QGroupBox(parent){
    ui_.reset(new Ui::ParamListWidget());
    ui_->setupUi(this);
}

ParamListWidget::~ParamListWidget(){}

void ParamListWidget::paramListChanged(ParamList xinLieBiao){

    qDeleteAll(ParamWidgetLieBiao_);
    ParamWidgetLieBiao_.clear();

    foreach(IParam* IParam,xinLieBiao){
        ParamWidget* zheGe=yiGe(IParam);
        ParamWidgetLieBiao_.push_back(zheGe);
        ui_->verticalLayout_canShuLieBiao->addWidget(zheGe);
    }

}
