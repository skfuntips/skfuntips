#include "hangChuLi.h"

#include <boost/bind.hpp>

#include <QDebug>
#include <QStringList>


static bool ceShiHangShu(int hangKuanDu,const QString& yiHang){
    Q_ASSERT(yiHang.size()<=hangKuanDu);
    return true;
}

int main(int argc,char ** argv){

    QString duoHang("1234567890\nabcdefghijklmn\nABCDEFGHIJKLMN");

    for(int i=1;i<30;++i){
        QStringList jieGuo=hangDuanKai(duoHang,i);

        hangChuLi(jieGuo,boost::bind(ceShiHangShu,i,_1));

    }
}

