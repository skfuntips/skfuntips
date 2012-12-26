#ifndef ENCRYPT_PROCESSOR_H
#define ENCRYPT_PROCESSOR_H

#include "IProcessor.h"

class StringParam;

class EncryptProcessor: public IProcessor{

    Q_OBJECT
public:

    EncryptProcessor();

    virtual QString name()const;

    virtual QString description()const;

    virtual ~EncryptProcessor (){}

    virtual Result process(const QStringList& ziFuChuan);

    virtual ResultType resultType()const{
        return STRING;
    }

    virtual ParamList paramList();


private:

    StringParam *string_;

};

#endif
