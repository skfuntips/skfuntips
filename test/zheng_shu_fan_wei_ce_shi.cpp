
#include "IntRangeParam.h"

#include <QDebug>

int main(int argc, char const* argv[])
{

    IntRangeParam zhengShuFanWei;

    zhengShuFanWei.sheZhiSuoYou(100,99,101);


    Q_ASSERT(zhengShuFanWei.shuZhi()==100);



}
