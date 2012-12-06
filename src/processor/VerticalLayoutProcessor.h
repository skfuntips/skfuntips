
#ifndef ZONG_HENG_CHU_LI_H

#define ZONG_HENG_CHU_LI_H

#include "LevelSeedProcessor.h"

class IntRangeParam;
class SeedParam;

class VerticalLayoutProcessor :public LevelSeedProcessor{
        Q_OBJECT
    public:

        typedef LevelSeedProcessor FuLeiXing;

        VerticalLayoutProcessor();

        virtual QString name()const;

        virtual QString description()const;

        virtual Result process(const QStringList& f);

        virtual ~VerticalLayoutProcessor (){}

        void sheZhiHangKuanDu(int hangKuanDuZhi);

        void sheZhiJianGe(int jianGeZhi);

        void sheZhiCuDu(int cuDuZhi);

        ParamList paramList();


        virtual ResultType resultLeiXing()const{
            return STRING;
        }

    protected:

        virtual void paramChanged(IParam* naYiGe);

    private:

        IntRangeParam *hangKuanDu_;

        IntRangeParam* cuDu_;

        IntRangeParam *jianGe_;


};

#endif /* end of include guard: ZONG_HENG_CHU_LI_H */
