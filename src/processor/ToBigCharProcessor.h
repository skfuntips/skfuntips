
#ifndef BIAN_DA_ZI_CHU_LI
#define BIAN_DA_ZI_CHU_LI

#include "ToImageProcessor.h"


class ToBigCharProcessor :public ToImageProcessor{

    Q_OBJECT

public:

    typedef ToImageProcessor FuLeiXing;

    ToBigCharProcessor();

    virtual QString name()const;

    virtual Result process(const QStringList& ziFuChuan);

    virtual ~ToBigCharProcessor (){}

    virtual QString description()const;

    virtual ParamList paramList();

    virtual ResultType resultLeiXing()const{
        return STRING;
    }

    SeedParam* zhongZi(){
	 return zhongZi_;}

private:

    SeedParam *zhongZi_;

    SeedParam *kongGe_;

};

#endif /* end of include guard */
