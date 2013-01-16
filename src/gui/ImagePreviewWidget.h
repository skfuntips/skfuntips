#ifndef IMAGE_PREVIEW_WIDGET_H
#define IMAGE_PREVIEW_WIDGET_H

#include <boost/scoped_ptr.hpp>

#include <QWidget>

namespace Ui{
class ImagePreviewWidget;
}

class ImagePreviewWidget:public QWidget{
    Q_OBJECT

public:

    ImagePreviewWidget(QList<QImage> images=QList<QImage>(),QWidget* parent=0);

    ~ImagePreviewWidget();

    const QList<QImage>& images()const{
        return images_;
    }

private slots:

    void on_pushButton_append_clicked();

    void on_pushButton_clear_clicked();

    private:

    QList<QImage> images_;

    boost::scoped_ptr<Ui::ImagePreviewWidget> ui_;

};

#endif
