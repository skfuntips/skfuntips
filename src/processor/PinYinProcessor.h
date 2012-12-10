
#ifndef BIAN_PIN_YIN_CHU_LI

#define BIAN_PIN_YIN_CHU_LI

#include "IProcessor.h"

class PinYinProcessor :public IProcessor{
    Q_OBJECT
public:

    virtual QString name()const;

    virtual QString description()const;

    virtual ~PinYinProcessor (){}

    virtual Result process(const QStringList& ziFuChuan);

    virtual ResultType resultType()const{
        return STRING;
    }

    virtual ParamList paramList();
};

#endif /* end of include guard: BIAN_PIN_YIN_CHU_LI */
