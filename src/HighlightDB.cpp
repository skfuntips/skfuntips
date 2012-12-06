#include "HighlightDB.h"

#include <boost/bind.hpp>

#include <QDebug>

#include "hangChuLi.h"

HighlightDB::HighlightDB():
    CompositeResource("HighlightDB.txt"){

    processFile(INTERNAL);

    externalFileChanged();
}

static bool tianJiaBiaoDaShi(const QString& hang,QList<QRegExp>& zhengZeLieBiao){

    QRegExp zhengZe(hang);

    if(zhengZe.isValid()){
        zhengZeLieBiao.push_back(zhengZe);
    }else{
        qDebug()<<QObject::tr("invalid regexp:")+hang;
    }

    return true;
}

void HighlightDB::processFile(Type chuLiLeiXing) {
    Q_ASSERT(chuLiLeiXing<2);
    regexpList_[chuLiLeiXing].clear();

    hangChuLi(type(chuLiLeiXing),boost::bind(tianJiaBiaoDaShi,_1,
                                             boost::ref(regexpList_[chuLiLeiXing])));

}

void HighlightDB::externalFileChanged(){

    CompositeResource::externalFileChanged();

    processFile(EXTERNAL);

    regexpList_[ALL]=regexpList_[INTERNAL];
    regexpList_[ALL]<<regexpList_[EXTERNAL];

    emit chongZhi();
}
