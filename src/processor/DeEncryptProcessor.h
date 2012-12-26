#ifndef DE_ENCRYPT_PROCESSOR_H
#define DE_ENCRYPT_PROCESSOR_H

#include "IProcessor.h"

class StringParam;

class DeEncryptProcessor: public IProcessor{

    Q_OBJECT
public:

    DeEncryptProcessor();

    virtual QString name()const;

    virtual QString description()const;

    virtual ~DeEncryptProcessor (){}

    virtual Result process(const QStringList& ziFuChuan);

    virtual ResultType resultType()const{
        return STRING;
    }

    virtual ParamList paramList();


private:

    StringParam *string_;

};

#endif
