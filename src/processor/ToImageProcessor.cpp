#include "ToImageProcessor.h"
#include "Result.h"
#include "IntRangeParam.h"
#include "hangChuLi.h"
#include "FontParam.h"

#include <QTextDocument>
#include <QImage>
#include <QPainter>


ToImageProcessor::ToImageProcessor():
    kuanDu_(new IntRangeParam(this)),
    ziTi_(new FontParam(this)){

        paramChanged(ziTi_);
        kuanDu_->setName(tr("image width"));
        kuanDu_->setDescription(tr("width of generated image (in pixel)"));

        kuanDu_->sheZhiShuZhi(qMax<int>(640,kuanDu_->xiaXian()));

}

QString ToImageProcessor::name()const{
    return tr("to image process");
}

Result ToImageProcessor::process(const QStringList& ziFuChuan){

    QTextDocument buJu;

    tianChong(&buJu,ziFuChuan);

    buJu.setDefaultFont(ziTi_->ziTi());

    buJu.setTextWidth(kuanDu_->shuZhi());

     QSize daXiao=buJu.size().toSize();

     if(daXiao.height()>65500){
         return ToImageProcessor::process(QStringList(
                     tr("result too height,try to increase width or use smaller text segments multi-times")));
     }

     daXiao.setWidth(kuanDu_->shuZhi());

     QImage tuPian(daXiao,QImage::Format_Mono);

     QRgb tianChong=qRgb(255,255,255);
     tuPian.fill(tianChong);

     QPainter huiZhi(&tuPian);

     buJu.drawContents(&huiZhi);

     emit processPercent(100);

     return tuPian;
}

ParamList ToImageProcessor::paramList(){
    ParamList fanHuiZhi;

    fanHuiZhi.push_back(kuanDu_);
    fanHuiZhi.push_back(ziTi_);

    return fanHuiZhi;
}

void ToImageProcessor::sheZhiKuanDu(int kuanDuSheZhi){
    kuanDu_->sheZhiShuZhi(kuanDuSheZhi);
}

void ToImageProcessor::sheZhiZiTi(const QFont& ziTiSheZhi){
    ziTi_->sheZhiZiTi(ziTiSheZhi);
}


void ToImageProcessor::paramChanged(IParam *naYiGe){
    if(naYiGe==ziTi_){

        int zuiXiao=ziTi_->ziTi().pixelSize()+10;

        kuanDu_->sheZhiSuoYou(qMax<int>(kuanDu_->shuZhi(),zuiXiao),
                              zuiXiao,
                              qMin<int>(qMax<int>(zuiXiao+10,kuanDu_->shangXian()),65500));

    }

}

QString ToImageProcessor::description()const{
    return tr("turn text into a image (if result too big ,may fail)");
}
