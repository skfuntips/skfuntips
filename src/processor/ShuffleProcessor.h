
#ifndef PAI_LIE_CHU_LI_H
#define PAI_LIE_CHU_LI_H

#include "IProcessor.h"

class ShuffleProcessor :public IProcessor{
    Q_OBJECT
public:

     virtual QString name()const;

    virtual QString description()const;

     virtual Result process(const QStringList& ziFuChuan);

    virtual ParamList paramList(){return ParamList();}

     virtual ~ShuffleProcessor (){}


    virtual ResultType resultLeiXing()const{
        return STRING;
    }

};

#endif /* end of include guard */
