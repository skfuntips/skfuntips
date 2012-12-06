
#include "InsertProcessor.h"
#include "IntRangeParam.h"
#include "SeedParam.h"
#include "Result.h"

InsertProcessor::InsertProcessor():
    zuiDuo_(new IntRangeParam(this))
    {
    jiBie()->setName(tr("inserted length at least"));
    jiBie()->sheZhiSuoYou(1,1,999);
    jiBie()->setDescription(tr("text length inserted between char at least"));

    zhongZi()->sheZhiZiFuChuan(tr("!"));

    zuiDuo_->setName(tr("inserted length at most"));
    zuiDuo_->sheZhiSuoYou(5,1,999);
    zuiDuo_->setDescription
        (tr("text length inserted between char at most"));


    }

QString InsertProcessor::name()const{
     return tr("insert process");
}

QString InsertProcessor::description()const{
    return tr("insert text between chars, makes text wonderful");
}


Result InsertProcessor::process(const QStringList& ziFuChuan){

     const int zhiShao=jiBieZhi();

     QStringList fanHuiZhi;

     int jiShu=0;
     int zongShu=ziFuChuan.size();

     const int zuiDuo=zuiDuo_->shuZhi();

     Q_ASSERT(zuiDuo>=zhiShao);

     foreach(const QString& hang,ziFuChuan){
         QString ResultHang;
         foreach(QChar yuanLai,hang){

             int suiJi=qMax<int>(std::rand()%zuiDuo,zhiShao);

             ResultHang.append(yuanLai).append(zhongZi()->suiJiZiFuChuan(suiJi));
             ++jiShu;
             emit processPercent(jiShu/qreal(zongShu)*100);

         }

         fanHuiZhi.append(ResultHang);
     }

     return fanHuiZhi;
}

void InsertProcessor::paramChanged(IParam *naYiGe){
    if (naYiGe==jiBie()) {
        zuiDuo_->sheZhiShuZhi(qMax<int>(jiBieZhi(),zuiDuo_->shuZhi()));
    }else if(naYiGe==zuiDuo_){

        sheZhiJiBie(qMin<int>(zuiDuo_->shuZhi(),jiBieZhi()));
    }
}

ParamList InsertProcessor::paramList(){
    ParamList fanHui=FuLeiXing::paramList();
    fanHui.push_back(zuiDuo_);
    return fanHui;
}
