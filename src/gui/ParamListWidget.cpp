#include "ParamListWidget.h"

#include "param/IntRangeParam.h"
#include "param/SeedParam.h"
#include "param/FontParam.h"
#include "param/StringParam.h"
#include "param/ImageListParam.h"

#include "ui_ParamListWidget.h"
#include "IntRangeWidget.h"
#include "FontWidget.h"
#include "SeedWidget.h"
#include "StringWidget.h"
#include "ImageListWidget.h"

#include "IProcessor.h"




static ParamWidget* yiGe(IParam* param){

    ParamWidget *fanHuiZhi=NULL;

    if(qobject_cast<IntRangeParam*>(param)){
        fanHuiZhi=new IntRangeWidget();
    }else if(qobject_cast<SeedParam*>(param)){
        fanHuiZhi=new SeedWidget();
    }else if(qobject_cast<FontParam*>(param)){
        fanHuiZhi=new FontWidget();
    }else if(qobject_cast<StringParam*>(param)){
        fanHuiZhi=new StringWidget();
    }else if(qobject_cast<ImageListParam*>(param)){
        fanHuiZhi=new ImageListWidget();
    }

    fanHuiZhi->bindParam(param);

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
