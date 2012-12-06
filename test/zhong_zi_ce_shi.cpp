#include "SeedParam.h"
#include "hangChuLi.h"
#include "test_function.h"


SeedParam SeedParam;

static bool hangCeShi(const QString& yiHang){
     SeedParam.sheZhiZiFuChuan(yiHang);
     int changDu=yiHang.size();

     for (int i = 0; i < 5; i++) {
	  QString jieGuo=SeedParam.suiJiZiFuChuan(changDu);
	  Q_ASSERT(jieGuo==yiHang);
     }

     return true;
}

int main(int argc, char const* argv[])
{
     
     boost::shared_ptr<QFile> wenJian=
	  jiaZaiWenJian(argv[argc-1]);

     hangChuLi(*wenJian,hangCeShi);

    return 0;
}

