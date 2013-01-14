
#ifndef ZHENG_SHU_FAN_WEI_CAN_SHU_H

#define ZHENG_SHU_FAN_WEI_CAN_SHU_H

#include "IParam.h"

class IntRangeParam :public IParam{
    Q_OBJECT
public:

    IntRangeParam(QObject * suoYouZhe=0);

    virtual ~IntRangeParam (){}

    void sheZhiSuoYou(int shuZhiSheZhi,int xiaXianSheZhi,int shangXianSheZhi);

    void sheZhiShuZhi(int shuZhiSheZhi);

    int shuZhi()const{return shuZhi_;}
    int xiaXian()const{return xiaXian_;}
    int shangXian()const{return shangXian_;}


private:

    int xiaXian_;
    int shuZhi_;
    int shangXian_;
};


#endif /* end of include guard: ZHENG_SHU_FAN_WEI_CAN_SHU_H */
