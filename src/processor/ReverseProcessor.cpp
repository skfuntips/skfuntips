#include "ReverseProcessor.h"
#include "hangChuLi.h"
#include "Result.h"
#include "IntRangeParam.h"

#include <algorithm>

#include <boost/bind.hpp>
#include <boost/foreach.hpp>

#include <QStringList>
#include <QDebug>


ReverseProcessor::ReverseProcessor(){

    jiBie()->sheZhiSuoYou(1,0,999);
    jiBie()->setName(tr("level"));
    jiBie()->setDescription(tr("0:reverse per line,1: reverse all,>=2: reverse per N char"));

}

QString ReverseProcessor::description()const{
    return tr("reverse text ,makes your text right to left");
}

Result ReverseProcessor::simpleProcess(const QStringList &ziFuChuan){
    QStringList result=ziFuChuan;

    BOOST_FOREACH(QString& hang,result){
        std::reverse(hang.begin(), hang.end());
    }


    if (jiBieZhi()==1) {
        std::reverse(result.begin(), result.end());
    }

    return result;
}

Result ReverseProcessor::process(const QStringList& ziFuChuan){


    if (jiBieZhi()<=1) {
        return simpleProcess(ziFuChuan);
    }	 

    return complexProcess(ziFuChuan);
}

Result ReverseProcessor::complexProcess(const QStringList &ziFuChuan){

    QString heBing=heBingDuoHang(ziFuChuan,false);

    int segment=jiBieZhi();

    QString lineResult;

    for(int beginIndex=0;beginIndex<heBing.size();beginIndex+=segment){

        QString toReverse=heBing.mid(beginIndex,segment);

        std::reverse(toReverse.begin(),toReverse.end());

        lineResult.append(toReverse);
    }

    qDebug()<<lineResult;

    QStringList result;

    int beginIndex=0;

    for(int i=0;i<ziFuChuan.size();++i){

        int lineSize=ziFuChuan[i].size();
        result.append(lineResult.mid(beginIndex,lineSize));
        beginIndex+=lineSize;
    }

    return result;

}

QString ReverseProcessor::name()const{
     return tr("reverse process");
}
