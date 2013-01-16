#include "ImagePreviewWidget.h"
#include "gongJu.h"
#include "ui_ImagePreviewWidget.h"

ImagePreviewWidget::ImagePreviewWidget(QList<QImage> images, QWidget *parent)
    :QWidget(parent),
      ui_(new Ui::ImagePreviewWidget()){

    ui_->setupUi(this);
}

void ImagePreviewWidget::on_pushButton_append_clicked(){

    QList<QImage> loadedImages=loadImages(this);

     images_.append(loadedImages);

}

void ImagePreviewWidget::on_pushButton_clear_clicked(){
    images_.clear();
}

ImagePreviewWidget::~ImagePreviewWidget(){}

