#ifndef IMAGE_LIST_WIDGET_H

#define IMAGE_LIST_WIDGET_H

#include <boost/scoped_ptr.hpp>

#include "ParamWidget.h"

class ImageListParam;

namespace Ui{
class ImageListWidget;
}

class ImageListWidget :public ParamWidget{
     Q_OBJECT

     public :

     typedef ImageListParam ParamType;

        ImageListWidget(QWidget *parent=0);

    virtual ~ImageListWidget();

    protected:

    virtual void applyParam(IParam *canShu);

    private slots:

        void on_pushButton_append_clicked();

        void on_pushButton_clear_clicked();

private:

     boost::scoped_ptr<Ui::ImageListWidget> ui_;

};


#endif /* end of include guard: IMAGE_LIST_WIDGET_H */

