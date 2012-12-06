#include "Gif.h"

#include <QMovie>
#include <QDebug>
#include <QBuffer>



Gif::Gif(const QByteArray& erJinZhi){

    erJinZhi_=erJinZhi;


    huanChong_.reset(new QBuffer(&erJinZhi_));

    bool daKai=huanChong_->open(QIODevice::ReadOnly);

    Q_ASSERT(daKai);

    dongHua_.reset(new QMovie(huanChong_.get(),QByteArray(),0));

    Q_ASSERT(dongHua_->isValid());

}
