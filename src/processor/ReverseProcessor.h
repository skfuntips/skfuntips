
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

    virtual ResultType resultLeiXing()const{
        return STRING;
    }


};

#endif /* end of include guard: FAN_ZHUAN_CHU_LI_H */
