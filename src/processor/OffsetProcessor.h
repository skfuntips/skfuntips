#ifndef OFFSET_PROCESSOR_H
#define OFFSET_PROCESSOR_H

#include "IProcessor.h"

class IntRangeParam;

class OffsetProcessor: public IProcessor{

    Q_OBJECT
public:

    OffsetProcessor();

    virtual QString name()const;

    virtual QString description()const;

    virtual ~OffsetProcessor (){}

    virtual Result process(const QStringList& ziFuChuan);

    virtual ResultType resultType()const{
        return STRING;
    }

    virtual ParamList paramList();

    void setOffset(int offset);

private:

    IntRangeParam *offset_;

};

#endif
