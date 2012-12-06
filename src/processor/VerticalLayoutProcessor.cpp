#include "VerticalLayoutProcessor.h"
#include "hangChuLi.h"
#include "SeedParam.h"
#include "IntRangeParam.h"
#include "Result.h"

#include <boost/bind.hpp>

#include <QStringList>

VerticalLayoutProcessor::VerticalLayoutProcessor():
    hangKuanDu_(new IntRangeParam(this)),
    cuDu_(new IntRangeParam(this)),
    jianGe_(new IntRangeParam(this))
    {
    jiBie()->sheZhiSuoYou(0,0,1);
    jiBie()->setName(tr("process type"));
    jiBie()->setDescription(tr("0:snake layout,1:up-down vertical layout"));

    zhongZi()->setDescription(tr("text to filling into vertical gap"));
    zhongZi()->sheZhiZiFuChuan(tr("|__|"));

    hangKuanDu_->setName(tr("line width"));
    hangKuanDu_->sheZhiSuoYou(30,2,INT_MAX);
    hangKuanDu_->setDescription(tr("width of result line(due to use of wide char,this value may leads double English only char width) "));

    jianGe_->setName(tr("insert number"));
    jianGe_->sheZhiSuoYou(4,1,hangKuanDu_->shuZhi());
    jianGe_->setDescription(tr("how many gap char will inserted"));

    cuDu_->setName(tr("origin width"));
    cuDu_->sheZhiSuoYou(1,1,hangKuanDu_->shuZhi());
    cuDu_->setDescription(tr("how many columns of origin will appear continus"));

}
QString VerticalLayoutProcessor::description()const{

    return tr("turn text into vertical layout");
}

Result VerticalLayoutProcessor::process(const QStringList &ziFuChuan){

    QString meiYouHuanHang=quChuHuanHang(heBingDuoHang(ziFuChuan));

    zhongZi()->chongZhiJiShuQi();

    int ziShu=meiYouHuanHang.count();

    int hangKuanDu=hangKuanDu_->shuZhi();

    int cuDu=cuDu_->shuZhi();

    int jianGe=jianGe_->shuZhi();

    int zuKuanDu=cuDu+jianGe;

    int zuShu=hangKuanDu/zuKuanDu;

    int shengYuYouXiao=qMin<int>(cuDu,hangKuanDu%zuKuanDu);

    int hangYouXiao=zuShu*cuDu+shengYuYouXiao;

    int hangShu=ziShu/hangYouXiao+1;

    bool sheXing=(jiBieZhi()==0);

    QStringList Result;

    for(int i=0;i<hangShu;++i){
        Result.push_back(QString(""));
    }

    Q_ASSERT(hangShu*hangYouXiao>ziShu);

    for(int j=0;j<hangKuanDu;++j){

        int zuYuShu=j%zuKuanDu;
        int zuShu=j/zuKuanDu;

        if(zuYuShu<cuDu){

            int wenZiLieShu=zuShu*cuDu+zuYuShu;

            bool jiShuLie=(wenZiLieShu%2!=0);

            int hangJiShuQi=0;
            int jiShuFangXiang=1;

            if(sheXing && jiShuLie){
                hangJiShuQi=hangShu-1;
                jiShuFangXiang=-1;
            }

            QString lie=meiYouHuanHang.mid(wenZiLieShu*hangShu,hangShu);

            foreach(QChar ziFu,lie){
                Result[hangJiShuQi].append(ziFu);
                if(ziFu.unicode()<256){
                    Result[hangJiShuQi].append(' ');
                }
                hangJiShuQi+=jiShuFangXiang;
            }
        }else{
            QChar ziFu=zhongZi()->suiJiZiFuChuan(1)[0];

            for(int k=0;k<hangShu;++k){
                Result[k].append(ziFu);
            }
        }

    }


    return Result;
}

QString VerticalLayoutProcessor::name()const{
    return tr("vertical layout process");
}

ParamList VerticalLayoutProcessor::paramList(){

    ParamList fanHuiZhi=FuLeiXing::paramList();

    fanHuiZhi.push_back(hangKuanDu_);
    fanHuiZhi.push_back(cuDu_);
    fanHuiZhi.push_back(jianGe_);



    return fanHuiZhi;
}

void VerticalLayoutProcessor::sheZhiCuDu(int cuDuZhi){
    cuDu_->sheZhiShuZhi(cuDuZhi);
}

void VerticalLayoutProcessor::sheZhiHangKuanDu(int hangKuanDuZhi){
    hangKuanDu_->sheZhiShuZhi(hangKuanDuZhi);
}

void VerticalLayoutProcessor::sheZhiJianGe(int jianGeZhi){

    jianGe_->sheZhiShuZhi(jianGeZhi);
}

void VerticalLayoutProcessor::paramChanged(IParam *naYiGe){

    if(naYiGe==hangKuanDu_){
        int hangKuanDu=hangKuanDu_->shuZhi();

        cuDu_->sheZhiSuoYou(qMax<int>(1,qMin<int>(cuDu_->shuZhi(),hangKuanDu)),
                    1,qMin<int>(hangKuanDu,cuDu_->shangXian()));

        jianGe_->sheZhiSuoYou(qMax<int>(1,qMin<int>(jianGe_->shuZhi(),hangKuanDu)),
                              1,qMin<int>(hangKuanDu,jianGe_->shangXian()));

    }

}

