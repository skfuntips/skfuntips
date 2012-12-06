#ifndef BIAN_TU_PIAN_CHU_LI_H
#define BIAN_TU_PIAN_CHU_LI_H

#include "IProcessor.h"

class IntRangeParam;
class FontParam;

class QFont;

class ToImageProcessor:public IProcessor{

        Q_OBJECT

    public:

        ToImageProcessor();

        virtual QString name()const;

        virtual QString description()const;

        virtual Result process(const QStringList& ziFuChuan);

        virtual ParamList paramList();

        void sheZhiKuanDu(int kuanDu);

        void sheZhiZiTi(const QFont& ziTiSheZhi);

        virtual ResultType resultLeiXing()const{
            return IMAGE;
        }

        FontParam* fontParam(){
            return ziTi_;
        }

        IntRangeParam * kuanDu(){
            return kuanDu_;
        }

protected:

        virtual void paramChanged(IParam*);

    private:

        IntRangeParam *kuanDu_;

        FontParam *ziTi_;

};

#endif

