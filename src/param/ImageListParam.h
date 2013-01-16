#ifndef IMAGE_LIST_PARAM

#include "IParam.h"

#include <QImage>


class ImageListParam :public IParam{
    Q_OBJECT

    public:

    ImageListParam(QObject * suoYouZhe=0);

    void append(const QImage& picture){
        images_.append(picture);
        emit valueChanged(this);
    }

    public slots:

    void clear(){
        images_.clear();
        emit valueChanged(this);
    }

    const QList<QImage> images()const{return images_;}


    private:

    QList<QImage> images_;


};

#endif//IMAGE_LIST_PARAM
