#include "SeedParam.h"

static QChar suiJiZiFu(int qiangDu){

    while(true){
        int asciiMa=std::rand()%128;
        QChar c(asciiMa);

        if (qiangDu==0) {
            if (c.isSymbol()) {
                return c;
            }
        }

        if (qiangDu==1) {
            if (c.isLetterOrNumber()) {
                return c;
            }
        }

        if (c.isPrint()) {
            return c;
        }
    }
}

SeedParam::SeedParam(QObject * suoYouZhe):
    IParam(suoYouZhe){
    ziFuChuan_=QString("~!@#$%^&*()_+|");

    ziFuChuanWeiZhi_=0;
    setDescription(tr("text to fill"));
    setName(tr("text to fill"));

}

void SeedParam::sheZhiZiFuChuan(const QString& ziFuChuan){
    if (ziFuChuan!=ziFuChuan_) {
        ziFuChuan_=ziFuChuan;
        ziFuChuanWeiZhi_=0;
        emit valueChanged(this);
    }
    ziFuChuanWeiZhi_=0;
}


QString SeedParam::suiJiZiFuChuan(int changDu){

    Q_ASSERT(changDu>=1);

    if (ziFuChuan_.isEmpty()) {
        return QString(changDu,suiJiZiFu(changDu%3));
    }

    if (ziFuChuan_.size()==1) {
        return QString(changDu,ziFuChuan_[0]);
    }

    QString fanHuiZhi;

    int shengYu=changDu;

    while(shengYu!=0){

        int benCiFuZhi=qMin(ziFuChuan_.size()-ziFuChuanWeiZhi_,shengYu);
        shengYu-=benCiFuZhi;
        fanHuiZhi.append(ziFuChuan_.mid(ziFuChuanWeiZhi_,benCiFuZhi));
        ziFuChuanWeiZhi_+=benCiFuZhi;

        ziFuChuanWeiZhi_%=ziFuChuan_.size();
    }

    return fanHuiZhi;

}


