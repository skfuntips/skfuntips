#include <utility>
#include <boost/shared_ptr.hpp>

class QString;
class QStringList;
class QFile;

void duiBiXieYinJieGuo(const QString& e,const QString&n);

std::pair<double,double> xiangSiDuHeChangYongDu(const QString& b,const QString&n);

boost::shared_ptr<QFile> jiaZaiWenJian(const char * const wenJianMing);

QStringList jiaZaiWenJianZiFuChuan(const char * const wenJianMing);

