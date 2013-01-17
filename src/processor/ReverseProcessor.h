
#ifndef FAN_ZHUAN_CHU_LI_H

#define FAN_ZHUAN_CHU_LI_H


#include "LevelProcessor.h"

class ReverseProcessor:public LevelProcessor{
    Q_OBJECT;

    public:

    ReverseProcessor();

    virtual ~ReverseProcessor(){}

    virtual QString name()const;

    virtual QString description()const;

    virtual Result process(const QStringList& ziFuChuan);

    virtual ResultType resultType()const{
        return STRING;
    }

private:

    Result simpleProcess(const QStringList& ziFuChuan);

    Result complexProcess(const QStringList& ziFuChuan);


};

#endif /* end of include guard: FAN_ZHUAN_CHU_LI_H */
