#include "ImageListWidget.h"

#include <QFileDialog>
#include <QMessageBox>

#include "ui_ImageListWidget.h"

#include "param/ImageListParam.h"

ImageListWidget::~ImageListWidget(){}

ImageListWidget::ImageListWidget(QWidget * parent)
     :ParamWidget(parent){
    ui_.reset(new Ui::ImageListWidget());

      ui_->setupUi(this);

     }



void ImageListWidget::applyParam(IParam *canShu){


     ImageListParam *imageListParam=
         qobject_cast<ImageListParam*>(canShu);

     Q_ASSERT(imageListParam);

     ui_->label->setText(QString::number(imageListParam->images().size()));

     setTitle(imageListParam->name());

}


void ImageListWidget::on_pushButton_append_clicked(){

    ImageListParam *imageListParam=
        param<ImageListParam>();

    if(!imageListParam){
        return;
    }


    QString wenJianMing=QFileDialog::getOpenFileName
        (this,QObject::tr("open file"),QString(),"*.bmp *.jpg *.png");

    if(wenJianMing.isNull()){
        return;
    }

    QImage image(wenJianMing);

    if(image.isNull()){
        QMessageBox::critical(this,QObject::tr("unable to open file")+wenJianMing,
                QObject::tr("file open failed"));
        return;
    }

    imageListParam->append(image);

    applyParam(param<IParam>());

}

void ImageListWidget::on_pushButton_clear_clicked(){

    ImageListParam *imageListParam=
        param<ImageListParam>();

    if(!imageListParam){
        return;
    }

    imageListParam->clear();
    applyParam(param<IParam>());

}
