#include "StringParam.h"

#include <QRegExp>

StringParam::StringParam(QObject* parent)
    :IParam(parent){}


void StringParam::sheZhiZiFuChuan(const QString &ziFuChuan){
    ziFuChuan_=ziFuChuan;
}
