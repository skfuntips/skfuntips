#include "ImageListWidget.h"

#include <QFileDialog>
#include <QMessageBox>

#include "ui_ImageListWidget.h"

#include "param/ImageListParam.h"
#include "FrameSegment.h"
#include "gongJu.h"
#include "ImagePreviewDialog.h"

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

     ui_->pushButton_view->setText(tr("view")+
                                   QString::number(imageListParam->segments().size())
                                   +tr("picture(s)"));

     setTitle(imageListParam->name());

     ui_->label->setText(canShu->description());

}


void ImageListWidget::on_pushButton_append_clicked(){

    ImageListParam *imageListParam=
        param<ImageListParam>();

    if(!imageListParam){
        return;
    }



    Segments loadedImages=loadImages(this);

    imageListParam->append(loadedImages);

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

void ImageListWidget::on_pushButton_view_clicked(){


    ImageListParam *imageListParam=
        param<ImageListParam>();

    if(!imageListParam){
        return;
    }

    ImagePreviewDialog dialog(imageListParam->segments(),this);

    dialog.exec();

    Segments images=dialog.segments();

    imageListParam->setImages(images);

}
