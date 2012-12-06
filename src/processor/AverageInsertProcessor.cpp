#include "AverageInsertProcessor.h"
#include "IntRangeParam.h"

#include "Result.h"

AverageInsertProcessor::AverageInsertProcessor():
    yuanShiKuanDu_(new IntRangeParam(this)){
    jiBie()->setName(tr("insert number"));
    jiBie()->setDescription(tr("length of inserted filling text in result"));
    jiBie()->sheZhiSuoYou(2,1,INT_MAX);

    yuanShiKuanDu_->setName(tr("continus origin text length"));
    yuanShiKuanDu_->setDescription(tr("length of continus origin text appears in result"));
    yuanShiKuanDu_->sheZhiSuoYou(5,1,INT_MAX);

    zhongZi()->sheZhiZiFuChuan(tr("]["));

}

Result AverageInsertProcessor::process(const QStringList& ziFuChuan){


     QStringList Result;

     zhongZi()->chongZhiJiShuQi();

     int chaRu=jiBieZhi(),
         yuanShi=yuanShiKuanDu_->shuZhi();

         foreach(const QString& hang,ziFuChuan){

             int ziShu=hang.size();

             QString hangResult;

             for(int dangQian=0;dangQian<ziShu;dangQian+=yuanShi){
                 hangResult.append(hang.mid(dangQian,yuanShi)).
                     append(zhongZi()->suiJiZiFuChuan(chaRu));
             }
             Result.append(hangResult);
         }

     return Result;

}

QString AverageInsertProcessor::name()const{
     return tr("average insert process");
}

ParamList AverageInsertProcessor::paramList(){

    ParamList fanHuiZhi=LevelSeedProcessor::paramList();

    fanHuiZhi.push_back(yuanShiKuanDu_);

    return fanHuiZhi;
}

QString AverageInsertProcessor::description()const{
    return tr("insert some text per segment in origin text");
}
