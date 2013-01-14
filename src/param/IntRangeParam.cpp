#include "IntRangeParam.h"

#include <limits>

IntRangeParam::IntRangeParam(QObject * suoYouZhe)
    :IParam(suoYouZhe){
    sheZhiSuoYou(0,
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::max());
    setName(tr("int range param"));
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


