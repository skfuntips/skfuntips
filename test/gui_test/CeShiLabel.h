#ifndef CE_SHI_LABEL_H

#define CE_SHI_LABEL_H

#include <QLabel>

class CanShuJieKou;


class CeShiLabel:public QLabel{

    Q_OBJECT;
    public:

    CeShiLabel(CanShuJieKou* canShu){
        canShu_=canShu;

        connect(canShu,SIGNAL(zhiGaiBian(CanShuJieKou*)),
                this,SLOT(canShuGaiBian(CanShuJieKou*)));

        canShuGaiBian(canShu_);
    }

    private slots:

        void canShuGaiBian(CanShuJieKou* canShu){
            Q_ASSERT(canShu_==canShu);
            this->setText(canShu_->zhuanHuanDaoZiFuChuan());
        }

    private:

    CanShuJieKou *canShu_;

};


#endif /* end of include guard: CE_SHI_LABEL_H */
