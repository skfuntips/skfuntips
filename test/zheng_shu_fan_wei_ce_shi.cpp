
#include "IntRangeParam.h"

#include <QDebug>

int main(int argc, char const* argv[])
{

    IntRangeParam zhengShuFanWei;

    zhengShuFanWei.sheZhiSuoYou(100,99,101);

    QString ziFuChuan=zhengShuFanWei.zhuanHuanDaoZiFuChuan();

    Q_ASSERT(ziFuChuan=="100");

    QString jieGuo=zhengShuFanWei.jieShou("100");

    Q_ASSERT(jieGuo.isEmpty());

    jieGuo=zhengShuFanWei.jieShou("80");

    Q_ASSERT(!jieGuo.isEmpty());

    Q_ASSERT(zhengShuFanWei.shuZhi()==100);
    
    jieGuo=zhengShuFanWei.jieShou("1000");

    Q_ASSERT(!jieGuo.isEmpty());

    Q_ASSERT(zhengShuFanWei.shuZhi()==100);
}
