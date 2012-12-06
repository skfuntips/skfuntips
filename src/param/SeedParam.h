
#ifndef ZHONG_ZI_CAN_SHU_H

#define ZHONG_ZI_CAN_SHU_H

#include "IParam.h"

#include <QString>
#include <boost/shared_ptr.hpp>
#include <vector>


class SeedParam :public IParam{
        Q_OBJECT;
    public:

        SeedParam(QObject * suoYouZhe=NULL);

        virtual ~SeedParam(){}

        virtual QString zhuanHuanDaoZiFuChuan()const{
            return ziFuChuan_;
        }

        virtual QString jieShou(const QString& ziFuChuan){
            sheZhiZiFuChuan(ziFuChuan);
            return QString();
        }

        void chongZhiJiShuQi(){
            ziFuChuanWeiZhi_=0;
        }

        QString suiJiZiFuChuan(int changDu);

	const QString& ziFuChuan()const{return ziFuChuan_;}

    public slots:

        void sheZhiZiFuChuan(const QString& ziFuChuan);

    private:

        QString ziFuChuan_;

        int ziFuChuanWeiZhi_;



};

#endif /* end of include guard: ZHONG_ZI_CAN_SHU_H */
