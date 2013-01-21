#ifndef FRAME_H
#define FRAME_H

#include <QImage>

class Frame{

public:

    bool isMulti()const{
        return microSecond_!=-1;
    }

    int microSecond()const{return microSecond_;}

    Frame(QImage image):microSecond_(-1){
        images_.append(image);
    }

    Frame(const QString& fileName);

    const QList<QImage>& images()const{return images_;}

    const QImage& image()const{return images_[0];}

private:

    int microSecond_;

    QList<QImage> images_;
};

#endif //FRAME_H
