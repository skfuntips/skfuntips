#ifndef STRING_PARAM_H
#define STRING_PARAM_H

#include "IParam.h"

class StringParam :public IParam{

    Q_OBJECT
public:

    StringParam(QObject * suoYouZhe=NULL);

    virtual ~StringParam(){}

    virtual QString zhuanHuanDaoZiFuChuan()const{
        return ziFuChuan_;
    }

    virtual QString jieShou(const QString& ziFuChuan);

    const QString& ziFuChuan()const{return ziFuChuan_;}

public slots:

    void sheZhiZiFuChuan(const QString& ziFuChuan);

private:

    QString ziFuChuan_;


};

#endif//STRING_PARAM_H
