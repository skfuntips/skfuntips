#ifndef DONG_HUA_CHU_LI_H
#define DONG_HUA_CHU_LI_H

#include "IProcessor.h"

class IntRangeParam;

class FontParam;

class ToGifProcessor:public IProcessor{

    Q_OBJECT

public:

    ToGifProcessor();

    virtual QString name()const;

    virtual QString description()const;

    virtual Result process(const QStringList& f);

    virtual ParamList paramList();

    virtual ~ToGifProcessor(){}

    virtual ResultType resultLeiXing()const{
        return GIF_ANIMATION;
    }

protected:

    virtual void paramChanged(IParam *naYiGe);

private:

    FontParam *ziTi_;

    IntRangeParam *kuan_;

    IntRangeParam *hang_;

    IntRangeParam *jianGe_;



};

#endif//DONG_HUA_CHU_LI_H
