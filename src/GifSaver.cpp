#include "GifSaver.h"

#include "FrameSegment.h"

#include <cstddef>
#include <algorithm>

#include <gif_lib.h>

#include <QBuffer>
#include <QPainter>
#include <QDebug>

using namespace std;






GifSaver::GifSaver(int kuan, int gao){
    kuan_=kuan;
    gao_=gao;

}

void GifSaver::addFrameSegment(const FrameSegment& segment){

    foreach(const Frame& frame,segment.frames()){
        addFrame(frame);
    }

}


void GifSaver::addFrame(const Frame& frame){

    QImage zhen=frame.first;

    if((zhen.width()!=kuan_)||(zhen.height()!=gao_)
            ||(zhen.format()!=QImage::Format_Mono)){


        QImage scaled=zhen.scaled(kuan_,gao_,Qt::KeepAspectRatio);

        zhen=QImage(kuan_,gao_,QImage::Format_RGB32);

        QPainter painter(&zhen);

        painter.eraseRect(0,0,kuan_,gao_);

        painter.drawImage((kuan_-scaled.width())/2,
                          (gao_-scaled.height())/2,scaled);

    }

    Q_ASSERT(zhen.width()==kuan_);
    Q_ASSERT(zhen.height()==gao_);

    Q_ASSERT((zhen.format()==QImage::Format_RGB32)
             || (zhen.format()==QImage::Format_Mono));


    if((zhen.format()!=QImage::Format_Mono)&&firstColorImage_.isNull()){
        firstColorImage_=zhen;
    }

    frames_.append(Frame(zhen,frame.second));

}

static bool tianJiaXunHuan(GifFileType *gf){
  
   int loop_count;
   loop_count=0;
   {

     char nsle[12] = "NETSCAPE2.0";
     char subblock[3];
     if(EGifPutExtensionLeader(gf,APPLICATION_EXT_FUNC_CODE) == GIF_ERROR ){
         Q_ASSERT(false);
         return false;
     }

     if (EGifPutExtensionBlock(gf,11, nsle) == GIF_ERROR) {
         Q_ASSERT(false);
       return false;
     }
     subblock[0] = 1;
     subblock[2] = loop_count % 256;
     subblock[1] = loop_count / 256;
     if (EGifPutExtensionBlock(gf, 3, subblock) == GIF_ERROR) {
         Q_ASSERT(false);
       return false;
     }

     if(EGifPutExtensionTrailer(gf) == GIF_ERROR){
         Q_ASSERT(false);
         return false;
     }

    }
    return true;
}

static int xieWenJian(GifFileType* gf,const GifByteType* shuJu,int duoShao){

    QIODevice * huanChong=(QBuffer*)(gf->UserData);

    huanChong->write((const char *)shuJu,duoShao);

    return duoShao;

}

static const int POWER_TABLE[]={1,2,4,8,16,32,64,128,256};
static const int POWER_NUMBER = 9;

QByteArray GifSaver::save(int haoMiao){


    QVector<QRgb> colorTable;

    if(!firstColorImage_.isNull()){
        QImage indexedImage=firstColorImage_.convertToFormat(QImage::Format_Indexed8);

        int colorNumber=indexedImage.colorCount();

        std::pair<const int*,const int*> range=std::equal_range(
                    POWER_TABLE,POWER_TABLE+POWER_NUMBER,colorNumber);

        int finalColorNumber=colorNumber;

        if(colorNumber!=*range.first){
            Q_ASSERT(colorNumber<=*range.second);
            finalColorNumber=*range.second;
        }

        finalColorNumber=qMax(finalColorNumber,2);

        indexedImage.setColorCount(finalColorNumber);

        colorTable=indexedImage.colorTable();

    }else{
        colorTable.push_back(QColor(Qt::black).rgb());
        colorTable.push_back(QColor(Qt::white).rgb());
    }


    ColorMapObject* tiaoSeBan= GifMakeMapObject(colorTable.size(), NULL);

    for(int i=0,size=colorTable.size();i<size;++i){
        QRgb rgb=colorTable[i];


        (tiaoSeBan->Colors)[i].Red=qRed(rgb);
        (tiaoSeBan->Colors)[i].Green=qGreen(rgb);
        (tiaoSeBan->Colors)[i].Blue=qBlue(rgb);

    }


    QByteArray fanHui;

    QBuffer huanChong(&fanHui);

    int daKai=huanChong.open(QIODevice::WriteOnly);

    Q_ASSERT(daKai);

    int err=GIF_OK;

    GifFileType *GifFile = EGifOpen(&huanChong,xieWenJian,&err);

    Q_ASSERT(err==GIF_OK);

    Q_ASSERT(GifFile);

    int errCode=EGifPutScreenDesc(
            GifFile,
            kuan_, gao_, 1, 0,
            tiaoSeBan
            ) ;

    Q_ASSERT(errCode!=GIF_ERROR);

    bool chengGong=tianJiaXunHuan(GifFile);

    Q_ASSERT(chengGong);

    for (int zhenShu=0,daXiao=frames_.size(); zhenShu<daXiao; ++zhenShu) {

        static unsigned char
            ExtStr[4] = { 0x04, 0x00, 0x00, 0xff };


        const Frame& frame=frames_[zhenShu];


        ExtStr[0] = (false) ? 0x06 : 0x04;

        float finalMs=(frame.second==STATIC_FRAME?
                           haoMiao:frame.second);

        ExtStr[1] = int(finalMs/1000*100) % 256;
        ExtStr[2] = int(finalMs/1000*100) / 256;

        /* Dump graphics control block. */
        EGifPutExtension(GifFile, GRAPHICS_EXT_FUNC_CODE, 4, ExtStr);


        errCode=EGifPutImageDesc(
                GifFile,
                0, 0, kuan_, gao_, false, NULL
                ) ;

        Q_ASSERT(errCode!=GIF_ERROR);


        QImage zhen;

        if(frame.first.format()==QImage::Format_RGB32){
            zhen=frame.first.convertToFormat(
                    QImage::Format_Indexed8,colorTable);
        }else{
            Q_ASSERT(frame.first.format()==QImage::Format_Mono);
            zhen=frame.first.convertToFormat(QImage::Format_RGB32);
            zhen=zhen.convertToFormat(QImage::Format_Indexed8,colorTable);
        }


        for (int y = 0 ; y < gao_; y++) {

            errCode=EGifPutLine(GifFile, zhen.scanLine(y), kuan_);

            Q_ASSERT(errCode!=GIF_ERROR);
        }
    }

    errCode=EGifCloseFile(GifFile);

    Q_ASSERT(fanHui.size()>0);

    Q_ASSERT(errCode== GIF_OK);

    return fanHui;

}


  
