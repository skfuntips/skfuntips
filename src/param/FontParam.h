#ifndef ZI_TI_CAN_SHU_H
#define ZI_TI_CAN_SHU_H

#include "IParam.h"

#include <QFont>

class FontParam :public IParam{
    Q_OBJECT;

    public:

    FontParam(QObject * suoYouZhe=0);
    
    virtual QString zhuanHuanDaoZiFuChuan()const{
	 return ziTi_.toString();
    }

    virtual QString jieShou(const QString& ziFuChuan);

    const QFont& ziTi()const{
        return ziTi_;
    }

    void sheZhiZiTi(const QFont& ziTiSheZhi);

    private:

    QFont ziTi_;

};

#endif
