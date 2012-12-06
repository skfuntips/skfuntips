#include "PinYinDB.h"
#include "haXi.h"
#include "hangChuLi.h"
#include "QtResource.h"

#include <boost/foreach.hpp>
#include <boost/bimap.hpp>
#include <boost/unordered_set.hpp>
#include <boost/bimap/unordered_multiset_of.hpp>

#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QTextStream>


typedef boost::bimap<boost::bimaps::unordered_multiset_of<QChar>, 
        boost::bimaps::unordered_multiset_of<QString> > ZiFuDuiPinYinMap;

typedef ZiFuDuiPinYinMap::left_map::iterator ZiFuDuiPinYinDieDaiQi;

typedef ZiFuDuiPinYinMap::left_value_type ZiFuDuiPinYinZhiLeiXing;

std::size_t hash_value(const ZiFuDuiPinYinZhiLeiXing& tl){

    std::size_t bbd=0;
    boost::hash_combine(bbd,tl.first);
    boost::hash_combine(bbd,tl.second);
    return bbd;
}


static ZiFuDuiPinYinMap SUO_YOU_ZI_FU_DUI_PIN_YIN;

static ZiFuDuiPinYinMap CHANG_JIAN_ZI_FU_DUI_PIN_YIN;


typedef boost::unordered_set<ZiFuDuiPinYinZhiLeiXing> ZiFuPinYinJianChaBiao;

static bool jianChaPinYinDB(const ZiFuDuiPinYinMap& yingShe){


    ZiFuPinYinJianChaBiao jianChaBiao;


    BOOST_FOREACH(const ZiFuDuiPinYinZhiLeiXing& ziFuPinYin,yingShe.left){

        Q_ASSERT(jianChaBiao.count(ziFuPinYin)==0);

        jianChaBiao.insert(ziFuPinYin);

    }

    return true;
}

static bool duQuPinYinBiao(const QString& yiHang){

    QTextStream hangZiFuLiu(yiHang.toUtf8());

    hangZiFuLiu.setCodec("UTF-8");

    QChar hanZi;
    hangZiFuLiu>>hanZi;

    QString pinYin;
    hangZiFuLiu>>pinYin;

    SUO_YOU_ZI_FU_DUI_PIN_YIN.left.insert
        (ZiFuDuiPinYinZhiLeiXing(hanZi,pinYin));

    return true;
}


static ZiFuPinYinJianChaBiao changJianJianChaBiao;


bool duQuChangJian(const QString& ziFuChuan){

    foreach(QChar ziFu,ziFuChuan){
        if (ziFu.isSymbol()||
                ziFu.isNumber()||
                ziFu.isSpace()) {
            continue;
        }


        std::pair<ZiFuDuiPinYinDieDaiQi, ZiFuDuiPinYinDieDaiQi> 
            weiZhi=SUO_YOU_ZI_FU_DUI_PIN_YIN.left.equal_range(ziFu);


        for(ZiFuDuiPinYinDieDaiQi dieDaiQi=weiZhi.first;dieDaiQi!=weiZhi.second;++dieDaiQi){

            if(changJianJianChaBiao.count
                    (ZiFuDuiPinYinZhiLeiXing(ziFu,dieDaiQi->second))!=0){
                continue;
            }

            CHANG_JIAN_ZI_FU_DUI_PIN_YIN.left.insert
                (ZiFuDuiPinYinZhiLeiXing(ziFu,dieDaiQi->second));
                changJianJianChaBiao.insert(ZiFuDuiPinYinZhiLeiXing(ziFu,dieDaiQi->second));
            }
        }
    return true;
}

PinYinDB::PinYinDB(){

    QtResource::instance();

    QFile pinYinBiao(":/PinYinDB.txt");

    hangChuLi(pinYinBiao,duQuPinYinBiao);



    QFile changJianLieBiao(":/ChangJianDB.txt");

    hangChuLi(changJianLieBiao,duQuChangJian);

    Q_ASSERT(jianChaPinYinDB(SUO_YOU_ZI_FU_DUI_PIN_YIN));
    Q_ASSERT(jianChaPinYinDB(CHANG_JIAN_ZI_FU_DUI_PIN_YIN));
}


static QChar tongYinZi(ZiFuDuiPinYinMap& yingShe,QChar xuZhao){

    ZiFuDuiPinYinDieDaiQi dieDaiQi=yingShe.left.find(xuZhao);

    if (dieDaiQi==yingShe.left.end()) {
        return xuZhao;
    }

    const QString& pinYin=dieDaiQi->second;

    typedef ZiFuDuiPinYinMap::right_map::iterator YouDieDaiQi;

    std::pair<YouDieDaiQi,YouDieDaiQi> weiZhi=yingShe.right.equal_range(pinYin);

    std::advance(weiZhi.first, std::rand()%yingShe.right.count(pinYin));
    
    return weiZhi.first->second;
}

QChar PinYinDB::tongYinZiSuoYou(QChar m){

    return tongYinZi(SUO_YOU_ZI_FU_DUI_PIN_YIN,m);
}

QChar PinYinDB::tongYinZiChangYong(QChar xz){
    return tongYinZi(CHANG_JIAN_ZI_FU_DUI_PIN_YIN,xz);
}

        

bool PinYinDB::shiChangYong(QChar panDuan){
    return CHANG_JIAN_ZI_FU_DUI_PIN_YIN.left.find(panDuan)
        !=CHANG_JIAN_ZI_FU_DUI_PIN_YIN.left.end();
}


void PinYinDB::xieChuChangJian(){

    QTextStream shuChu(stdout);

    shuChu.setCodec("UTF-8");

        
    BOOST_FOREACH(ZiFuDuiPinYinZhiLeiXing& ziFuPinYin, CHANG_JIAN_ZI_FU_DUI_PIN_YIN.left){

        shuChu<<ziFuPinYin.first<<' '<<ziFuPinYin.second<<'\n';
    }

}

bool PinYinDB::meiYouTongYin(QChar ziFu){

    std::pair<ZiFuDuiPinYinDieDaiQi, ZiFuDuiPinYinDieDaiQi> 
        weiZhi=SUO_YOU_ZI_FU_DUI_PIN_YIN.left.equal_range(ziFu);


    for(ZiFuDuiPinYinDieDaiQi dieDaiQi=weiZhi.first;
            dieDaiQi!=weiZhi.second;++dieDaiQi){

        if (SUO_YOU_ZI_FU_DUI_PIN_YIN.right.find(dieDaiQi->second)
                ==SUO_YOU_ZI_FU_DUI_PIN_YIN.right.end()) {
            continue;
        }

        return false;
    }

    return true;

}

QString PinYinDB::pinYin(QChar chaZhao){

    ZiFuDuiPinYinDieDaiQi dieDaiQi=CHANG_JIAN_ZI_FU_DUI_PIN_YIN.left.find(chaZhao);

    if (dieDaiQi==CHANG_JIAN_ZI_FU_DUI_PIN_YIN.left.end()) {
        return chaZhao;
    }

    QString pinYin=dieDaiQi->second;

    pinYin[0]=pinYin[0].toUpper();

    return pinYin;
}

