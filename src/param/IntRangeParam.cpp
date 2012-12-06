#include "IntRangeParam.h"

#include <limits>

IntRangeParam::IntRangeParam(QObject * suoYouZhe)
    :IParam(suoYouZhe){
    sheZhiSuoYou(0,
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::max());
    setName(tr("int range param"));
}
	
QString IntRangeParam::jieShou(const QString& ziFuChuan){

    bool Result=false;

    int linShi=ziFuChuan.toInt(&Result);
    
    if (!Result) {
        return "参数:\""+ziFuChuan+"\"无法转换为整数";
    }

    if (linShi<xiaXian_) {
        return "参数"+QString::number(shuZhi_)+"小于下限"+xiaXian_;
    }

    if (linShi>shangXian_) {
        return "参数"+QString::number(shuZhi_)+"大于上限"+shangXian_;
    }

    shuZhi_=linShi;

    return QString();
}

void IntRangeParam::sheZhiSuoYou(
        int shuZhiSheZhi, int xiaXianSheZhi, int shangXianSheZhi){

    Q_ASSERT_X(shuZhiSheZhi>=xiaXianSheZhi,
            "ZhengShuFanWeiCanShu::sheZhiSuoYou","shuZhi < xiaXian");
    Q_ASSERT_X(shuZhiSheZhi<=shangXianSheZhi,
            "ZhengShuFanWeiCanShu::sheZhiSuoYou","shuZhi > shangXian");

    bool gaiBian=((xiaXian_!=xiaXianSheZhi)||
                  (shangXian_!=shangXianSheZhi)||
                  (shuZhi_!=shuZhiSheZhi));

    shuZhi_=shuZhiSheZhi;
    xiaXian_=xiaXianSheZhi;
    shangXian_=shangXianSheZhi;

    if (gaiBian) {
        emit valueChanged(this);
    }

}

void IntRangeParam::sheZhiShuZhi(int shuZhiSheZhi){
    sheZhiSuoYou(shuZhiSheZhi,xiaXian_,shangXian_);
}


