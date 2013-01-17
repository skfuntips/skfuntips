#ifndef IMAGE_PREVIEW_DIALOG_H
#define IMAGE_PREVIEW_DIALOG_H

#include <boost/scoped_ptr.hpp>

#include <QDialog>

namespace Ui{
class ImagePreviewDialog;
}

class ImagePreviewDialog:public QDialog{
    Q_OBJECT

public:

    ImagePreviewDialog(const QList<QImage>& images=QList<QImage>(),QWidget* parent=0);

    ~ImagePreviewDialog();

    const QList<QImage>& images()const{
        return images_;
    }

private slots:

    void on_pushButton_append_clicked();

    void on_pushButton_clear_clicked();

    private:

    QList<QImage> images_;

    boost::scoped_ptr<Ui::ImagePreviewDialog> ui_;

    void append(const QList<QImage>& images);

};

#endif
