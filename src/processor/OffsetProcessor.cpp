#include "OffsetProcessor.h"
#include "IntRangeParam.h"
#include "Result.h"


OffsetProcessor::OffsetProcessor():
    offset_(new IntRangeParam(this)){

    offset_->setName(tr("offset"));
    offset_->setDescription(tr("offset value of char"));
    offset_->sheZhiSuoYou(1,-65535,65535);

}

QString OffsetProcessor::name()const{
    return tr("offset process");
}

QString OffsetProcessor::description()const{
    return tr("offset char unicode value");
}


Result OffsetProcessor::process(const QStringList& ziFuChuan){

    int offset=offset_->shuZhi();

    QStringList ret;

    for(int i=0,size=ziFuChuan.size();i<size;++i){

        emit processPercent(i/qreal(size));

        QString resultLine;

        foreach(QChar one,ziFuChuan[i]){

            int unicode=(int(one.unicode())+offset+65536)%65536;

            QChar resultChar(unicode);

            resultLine.append(resultChar);
        }
        ret.append(resultLine);

    }

    emit processPercent(1);


    return ret;

}

ParamList OffsetProcessor::paramList(){
    ParamList ret;
    ret.push_back(offset_);
    return ret;
}

void OffsetProcessor::setOffset(int offset){
    offset_->sheZhiShuZhi(offset);
}
