#include "FontWidget.h"


#include "ui_FontWidget.h"

#include "param/FontParam.h"

FontWidget::~FontWidget(){}

FontWidget::FontWidget(QWidget * parent)
     :ParamWidget(parent){
    ui_.reset(new Ui::FontWidget());

      ui_->setupUi(this);

      connect(ui_->spinBox_ziTiDaXiao,SIGNAL(valueChanged(int)),
		    this,SLOT(applyUi()));

      connect(ui_->fontComboBox,SIGNAL(currentFontChanged(const QFont&)),
		    this,SLOT(applyUi()));
     }

void FontWidget::applyUi(){
     FontParam* canShu=param<FontParam>();

     if (!canShu) {
	  return;
     }

     QFont ziTi=ui_->fontComboBox->currentFont();
     int chiCun=ui_->spinBox_ziTiDaXiao->value();

     ziTi.setPixelSize(chiCun);
     canShu->sheZhiZiTi(ziTi);

     ui_->plainTextEdit->document()->setDefaultFont(ziTi);
}


void FontWidget::applyParam(IParam *canShu){


     FontParam *fontParam=
         qobject_cast<FontParam*>(canShu);

     Q_ASSERT(fontParam);

     QFont ziTi=fontParam->ziTi();


     ui_->fontComboBox->setCurrentFont(ziTi.family());

     int chiCun=ziTi.pixelSize();

     ui_->spinBox_ziTiDaXiao->setMaximum(qMax<int>(ui_->spinBox_ziTiDaXiao->maximum(),chiCun));
     ui_->spinBox_ziTiDaXiao->setMinimum(qMin<int>(ui_->spinBox_ziTiDaXiao->minimum(),chiCun));
     ui_->spinBox_ziTiDaXiao->setValue(chiCun);

     setTitle(fontParam->name());

}


