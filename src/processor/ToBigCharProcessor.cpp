#include "ToBigCharProcessor.h"
#include "hangChuLi.h"
#include "SeedParam.h"
#include "FontParam.h"
#include "IntRangeParam.h"
#include "Result.h"

#include <limits>

#include <QStringList>
#include <QColor>
#include <QImage>

ToBigCharProcessor::ToBigCharProcessor():
zhongZi_(new SeedParam(this)),
  kongGe_(new SeedParam(this)){

    zhongZi_->setName(tr("soild fill char"));
    zhongZi_->setDescription(
                tr("char to fill soild pattern,dense char like '@' is recommended"));

    zhongZi_->sheZhiZiFuChuan(tr("@"));
    kongGe_->setName(tr("blank fill char"));
    kongGe_->setDescription(tr("char to fill blank pattern, sparse char like ' ' or '_' is recommended"));

    kongGe_->sheZhiZiFuChuan(tr(" "));

    QFont ziTi=fontParam()->ziTi();
    ziTi.setPixelSize(12);
    fontParam()->sheZhiZiTi(ziTi);

    kuanDu()->setName(tr("text length per line"));
    kuanDu()->sheZhiShuZhi(qMax<int>(kuanDu()->xiaXian(),40));
    kuanDu()->setDescription(tr("how many chars allowed per line.for wide char reason,this length may lead double English only char length"));
}

QString ToBigCharProcessor::name()const{
    return tr("ToBigCharProcessor");
}
    
Result ToBigCharProcessor::process(const QStringList& ziFuChuan){

    const int ziFuHangKuanDu=kuanDu()->shuZhi();

    QImage tuPian=FuLeiXing::process(ziFuChuan);

    const int gaoDu=tuPian.height();

    Q_ASSERT(tuPian.width()==ziFuHangKuanDu);

    QStringList result;

    int zuiDuo=std::numeric_limits<int>::max();

    for(int i=0;i<gaoDu;++i){

        emit processPercent(i/qreal(gaoDu)*100);

        result.push_back(QString(""));

        if(zuiDuo-ziFuHangKuanDu<0){
            return Result(QStringList(tr(
                            "result too height,try to reduce font size or splite origin to smaller segment")));
        }

        for(int j=0;j<ziFuHangKuanDu;++j){
            QColor yanSe=tuPian.pixel(j,i);

            if (yanSe.black()>0) {
                QChar tianChong=zhongZi_->suiJiZiFuChuan(1)[0];
                result.back().append(tianChong);

                if(tianChong.unicode()>255){
                    continue;
                }

                result.back().append(' ');
            }else{

                QChar kong=kongGe_->suiJiZiFuChuan(1)[0];
                result.back().append(kong);

                if(kong.unicode()<256){
                    result.back().append(kong);
                }

            }
        }
    }

    return result;
}

ParamList ToBigCharProcessor::paramList(){

    ParamList fanHuiZhi=FuLeiXing::paramList();

    fanHuiZhi.push_back(zhongZi_);
    fanHuiZhi.push_back(kongGe_);

    return fanHuiZhi;
}

QString ToBigCharProcessor::description()const{
    return tr("just like MATRIX,makes up a big char by many small char(depends on OS/Browser/Font,may looks wired in some situation)");
}

