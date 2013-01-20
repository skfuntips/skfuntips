#ifndef IMAGE_PREVIEW_DIALOG_H
#define IMAGE_PREVIEW_DIALOG_H

#include <boost/scoped_ptr.hpp>

#include <QDialog>

#include "FrameSegment.h"

namespace Ui{
class ImagePreviewDialog;
}

class ImagePreviewDialog:public QDialog{
    Q_OBJECT

public:

    ImagePreviewDialog(const Segments& images=Segments(),QWidget* parent=0);

    ~ImagePreviewDialog();

    const Segments& segments()const{
        return segments_;
    }

private slots:

    void on_pushButton_append_clicked();

    void on_pushButton_clear_clicked();

private:

    Segments segments_;

    boost::scoped_ptr<Ui::ImagePreviewDialog> ui_;

    void append(const Segments& segments);

};

#endif
