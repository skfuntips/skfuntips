#include "ImagePreviewDialog.h"
#include "gongJu.h"
#include "ui_ImagePreviewDialog.h"


void ImagePreviewDialog::append(const QList<QImage>& list){
    foreach(QImage image,list){
        QListWidgetItem *item=new QListWidgetItem(ui_->listWidget);
        item->setIcon(QIcon(QPixmap::fromImage(image)));
    }
}

ImagePreviewDialog::ImagePreviewDialog(const QList<QImage>& images, QWidget *parent)
    :QDialog(parent),
      images_(images),
      ui_(new Ui::ImagePreviewDialog()){

    ui_->setupUi(this);

    ui_->listWidget->setIconSize(QSize(100,100));

    append(images_);

}

void ImagePreviewDialog::on_pushButton_append_clicked(){

    QList<QImage> loadedImages=loadImages(this);

    images_.append(loadedImages);

    append(loadedImages);

}

void ImagePreviewDialog::on_pushButton_clear_clicked(){
    images_.clear();
    ui_->listWidget->clear();
}

ImagePreviewDialog::~ImagePreviewDialog(){}

