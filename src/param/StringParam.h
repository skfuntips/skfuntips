#ifndef STRING_PARAM_H
#define STRING_PARAM_H

#include "IParam.h"

class StringParam :public IParam{

    Q_OBJECT
public:

    StringParam(QObject * suoYouZhe=NULL);

    virtual ~StringParam(){}

    const QString& ziFuChuan()const{return ziFuChuan_;}

public slots:

    void sheZhiZiFuChuan(const QString& ziFuChuan);

private:

    QString ziFuChuan_;


};

#endif//STRING_PARAM_H
