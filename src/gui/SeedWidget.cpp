
#include "gongJu.h"
#include "hangChuLi.h"
#include "SeedWidget.h"
#include "SeedParam.h"
#include "ui_SeedWidget.h"

SeedWidget::~SeedWidget (){}

SeedWidget::SeedWidget(QWidget* parent)
    :ParamWidget(parent){
    ui_.reset(new Ui::SeedWidget());
        ui_->setupUi(this);

    connect(ui_->plainTextEdit,SIGNAL(textChanged()),this,SLOT(applyUi()));
    }

void SeedWidget::setString(const QString& wenBen){
    if (wenBen.isNull()) {
            return;
        }

       ui_-> plainTextEdit->setPlainText
            (quChuHuanHang(wenBen));
}

void SeedWidget::
    on_pushButton_jiaZaiWenJian_clicked(){

        setString(wenJianWenBen(this));
    }

void SeedWidget::
    on_pushButton_jianQieBan_clicked(){

        setString(jianQieBanWenBen(this));

    }

void SeedWidget::applyUi(){
     SeedParam* canShu=param<SeedParam>();

     if(!canShu){
	  return;
     }

     canShu->sheZhiZiFuChuan(ui_->plainTextEdit->toPlainText());

}

void SeedWidget::applyParam(IParam* IParam){

     SeedParam* canShu=qobject_cast<SeedParam*>(IParam);
     Q_ASSERT(canShu);

     setTitle(canShu->name());
     ui_->label_shuoMing->setText(canShu->description());

     if (ui_->plainTextEdit->toPlainText()!=canShu->ziFuChuan()) {
         ui_->plainTextEdit->setPlainText(canShu->ziFuChuan());
     }

}

