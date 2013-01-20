#include "ImagePreviewDialog.h"
#include "gongJu.h"
#include "ui_ImagePreviewDialog.h"


void ImagePreviewDialog::append(const Segments& segemnts){
    foreach(FrameSegment segment,segemnts){
        QListWidgetItem *item=new QListWidgetItem(ui_->listWidget);
        item->setIcon(QIcon(QPixmap::fromImage(segment.frames()[0].first)));
    }
}

ImagePreviewDialog::ImagePreviewDialog(const Segments& segments, QWidget *parent)
    :QDialog(parent),
      segments_(segments),
      ui_(new Ui::ImagePreviewDialog()){

    ui_->setupUi(this);

    ui_->listWidget->setIconSize(QSize(100,100));

    append(segments_);

}

void ImagePreviewDialog::on_pushButton_append_clicked(){

    Segments loadedImages=loadImages(this);

    segments_.append(loadedImages);

    append(loadedImages);

}

void ImagePreviewDialog::on_pushButton_clear_clicked(){
    segments_.clear();
    ui_->listWidget->clear();
}

ImagePreviewDialog::~ImagePreviewDialog(){}

