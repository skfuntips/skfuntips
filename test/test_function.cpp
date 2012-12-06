#include "test_function.h"
#include "PinYinDB.h"

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>

std::pair<double,double> xiangSiDuHeChangYongDu(const QString& yuanShi,const QString& jieGuo){

    Q_ASSERT(yuanShi.size()==jieGuo.size());

    int xiangTong=0;
    int changJian=0;
    for(int i=0;i<yuanShi.size();++i){
        if (yuanShi[i]==jieGuo[i]) {
            ++xiangTong;
        }

        if (PinYinDB::shiLi().shiChangYong(jieGuo[i])) {
            ++changJian;
        }
    }

    return std::pair<double,double>(
            xiangTong/double(yuanShi.size()),
            changJian/double(yuanShi.size()));
}


void duiBiXieYinJieGuo(const QString& w,const QString& n){
    if (w!=n) {
        return;
    }

    foreach(const QChar& x,w){
        Q_ASSERT(PinYinDB::shiLi().meiYouTongYin(x));
    }
}

boost::shared_ptr<QFile> jiaZaiWenJian(const char * const wenJianMing){

    QTextCodec* wenBenBianMa=QTextCodec::codecForName("UTF-8");

    QTextCodec::setCodecForCStrings(wenBenBianMa);

    boost::shared_ptr<QFile> wenJian(new QFile(wenJianMing));

    Q_ASSERT(wenJian->exists());

    bool jieGuo=wenJian->open(QIODevice::ReadOnly);

    Q_ASSERT(jieGuo);

    return wenJian;

}
QStringList jiaZaiWenJianZiFuChuan(const char * const wenJianMing){
     boost::shared_ptr<QFile> wenJian=jiaZaiWenJian(wenJianMing);
     QTextStream wenJianLiu(wenJian.get());

     QTextCodec* wenBenBianMa=QTextCodec::codecForName("UTF-8");

     wenJianLiu.setCodec(wenBenBianMa);

    QTextCodec::setCodecForCStrings(wenBenBianMa);

    QStringList jieGuo;
    while(true){
    
        QString hang=wenJianLiu.readLine();
        if (hang.isNull()) {
            break;
        }

        jieGuo.append(hang);

    }

     return jieGuo;
}

