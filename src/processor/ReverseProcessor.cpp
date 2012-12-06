#include "ReverseProcessor.h"
#include "hangChuLi.h"
#include "Result.h"
#include "IntRangeParam.h"

#include <algorithm>

#include <boost/bind.hpp>
#include <boost/foreach.hpp>

#include <QStringList>


ReverseProcessor::ReverseProcessor(){

    jiBie()->sheZhiSuoYou(0,0,1);
    jiBie()->setName(tr("level"));
    jiBie()->setDescription(tr("0:reverse per line,1: reverse all"));

}

QString ReverseProcessor::description()const{
    return tr("reverse text ,makes your text right to left");
}

Result ReverseProcessor::process(const QStringList& ziFuChuan){

    QStringList Result=ziFuChuan;

    BOOST_FOREACH(QString& hang,Result){
        std::reverse(hang.begin(), hang.end());
    }
    

    if (jiBieZhi()==1) {
        std::reverse(Result.begin(), Result.end());
    }	 

    return Result;
}

QString ReverseProcessor::name()const{
     return tr("reverse process");
}
