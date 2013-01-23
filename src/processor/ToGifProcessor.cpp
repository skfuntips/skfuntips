#include "ToGifProcessor.h"
#include "param/IntRangeParam.h"
#include "param/FontParam.h"
#include "param/ImageListParam.h"

#include<QTextDocument>
#include<QDebug>
#include <QTextEdit>
#include <QPainter>


#include "Result.h"
#include "hangChuLi.h"
#include "GifSaver.h"


ToGifProcessor::ToGifProcessor():
    ziTi_(new FontParam(this)),
    kuan_(new IntRangeParam(this)),
    hang_(new IntRangeParam(this)),
    jianGe_(new IntRangeParam(this)),
    tuPian_(new ImageListParam(this))
{

    int ziTiKuan=ziTi_->ziTi().pixelSize();

    kuan_->setName(tr("image width"));
    kuan_->setDescription(tr("image width of gif (in pixel)"));
    kuan_->sheZhiSuoYou(ziTiKuan*10,ziTiKuan*1.5,qMax(ziTiKuan*50,1000));

    hang_->setName(tr("text lines"));
    hang_->setDescription(tr("how many text line will appear in a frame"));
    hang_->sheZhiSuoYou(4,1,9999);

    jianGe_->setName(tr("frame length"));
    jianGe_->sheZhiSuoYou(2,1,100);
    jianGe_->setDescription(tr("how many seconds a frame will stay"));

    tuPian_->setName(tr("insert image"));
    tuPian_->setDescription(tr("images to insert as frames"));
}

QString ToGifProcessor::description()const{
    return tr("turn text/image to loop animationed gif");
}


void ToGifProcessor::paramChanged(IParam *naYiGe){



    if(naYiGe==ziTi_){

        int ziTiKuan=ziTi_->ziTi().pixelSize();

        kuan_->sheZhiSuoYou(qMax<int>(kuan_->shuZhi(),ziTiKuan+10),ziTiKuan+10,kuan_->shangXian());

    }
}




QString ToGifProcessor::name()const{
    return tr("to gif process");
}

static QImage kongTuPian(int kuan,int gao){

    QImage fanHui(kuan,gao,QImage::Format_Mono);

    fanHui.fill(1);

    return fanHui;

}


Result ToGifProcessor::process(const QStringList& f){

    int kuan=(kuan_->shuZhi()/4+1)*4,
        hang=hang_->shuZhi();

    QTextDocument kongJian;

    kongJian.setDefaultFont(ziTi_->ziTi());

    kongJian.setTextWidth(kuan);


    tianChong(&kongJian,f);

    QStringList neiRong=kongJianWenBen(&kongJian);

    const int ye=neiRong.size()/hang+1;

    QString ceShiWenBen;
    for(int i=0;i<hang;++i){ceShiWenBen.append("A\n");}

    QTextDocument ceShiBuJu(ceShiWenBen);
    ceShiBuJu.setDefaultFont(ziTi_->ziTi());

    QSizeF chiCun=ceShiBuJu.size();

    int gao=chiCun.height();

    QImage moBan=kongTuPian(kuan,gao);


    GifSaver saver(kuan,gao);

    Segments segments=tuPian_->segments();

    int segmentNumber=segments.size();

    qreal segF=ye/qMax(1,segmentNumber);



    int segLength=1;

    if(segF<1){
        segLength=segmentNumber/ye+1;
    }

    int seg=qMax(int(segF),1);

    int imageIndex=0;

    for(int i=0;i<ye;++i){

        if(!segments.isEmpty()){
            if(i%seg==0){
                for(int j=0;j<segLength;++j){
                    if(imageIndex<segmentNumber){
                        saver.addFrameSegment(segments[imageIndex]);
                        ++imageIndex;
                    }
                }
            }
        }


        QTextDocument buJu(heBingDuoHang(neiRong,true,i*hang,(i+1)*hang));

        buJu.setDefaultFont(ziTi_->ziTi());
        buJu.setTextWidth(kuan);

        QImage zhen(moBan);

        QPainter huiZhi(&zhen);

        buJu.drawContents(&huiZhi);

        Q_ASSERT((zhen.width()==kuan) && (zhen.height()==gao));

        saver.addFrame(Frame(zhen,jianGe_->shuZhi()*1000));

        emit processPercent(i/qreal(ye)*100);

    }

    if(!segments.isEmpty()){
        saver.addFrame(segments[0].frames()[0]);
    }

    int jianGe=jianGe_->shuZhi();
    
    QByteArray erJinZhi=saver.save(jianGe*1000);

    return erJinZhi;

}

ParamList ToGifProcessor::paramList(){

    ParamList result;

    result.push_back(ziTi_);
    result.push_back(kuan_);
    result.push_back(hang_);
    result.push_back(jianGe_);
    result.push_back(tuPian_);

    return result;
}
