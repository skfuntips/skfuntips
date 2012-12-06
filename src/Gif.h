#ifndef GIF_H
#define GIF_H

#include <boost/shared_ptr.hpp>

#include <QByteArray>

class QMovie;
class QIODevice;

class Gif{

public:

    Gif(const QByteArray& erJinZhi);

    QMovie *dongHua(){
        return dongHua_.get();
    }

    const QByteArray& erJinZhi()const{
        return erJinZhi_;
    }

private:

    boost::shared_ptr<QMovie> dongHua_;

    QByteArray erJinZhi_;

    boost::shared_ptr<QIODevice> huanChong_;
};

#endif//GIF_H
