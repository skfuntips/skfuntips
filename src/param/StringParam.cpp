#include "StringParam.h"

#include <QRegExp>

StringParam::StringParam(QObject* parent)
    :IParam(parent){}

QString StringParam::jieShou(const QString &ziFuChuan){

    ziFuChuan_=ziFuChuan;

    return QString();
}

void StringParam::sheZhiZiFuChuan(const QString &ziFuChuan){
    ziFuChuan_=ziFuChuan;
}
