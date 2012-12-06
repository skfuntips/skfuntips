#include <cstddef>
#include <algorithm>

#include <gif_lib.h>

#include <QBuffer>
#include <QDebug>

using namespace std;


#include "GifSaver.h"



GifSaver::GifSaver(int kuan, int gao){
    kuan_=kuan;
    gao_=gao;

}

static QVector<QRgb> chuShiHua(){

    QVector<QRgb> fanHui;

    fanHui.push_back(Qt::black);
    fanHui.push_back(Qt::white);


    return fanHui;

}


void GifSaver::tianJiaYiZhen(const QImage &zhen){

    Q_ASSERT(kuan_==zhen.width());
    Q_ASSERT(gao_==zhen.height());

    Q_ASSERT(zhen.format()==QImage::Format_Mono);


    static QVector<QRgb> biao=chuShiHua();

    QImage zhuanHuan=zhen.convertToFormat(QImage::Format_Indexed8,biao);

    suoYouZhen_.push_back(zhuanHuan);
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


QByteArray GifSaver::baoCunLinShi(int haoMiao){


    ColorMapObject* tiaoSeBan= GifMakeMapObject(2, NULL);

    std::fill_n((GifByteType*)(tiaoSeBan->Colors), 3, 0);

    std::fill_n((GifByteType*)(tiaoSeBan->Colors)+3, 3, 255);


    QByteArray fanHui;

    QBuffer huanChong(&fanHui);

    int daKai=huanChong.open(QIODevice::WriteOnly);

    Q_ASSERT(daKai);

    int err=GIF_OK;

    GifFileType *GifFile = EGifOpen(&huanChong,xieWenJian,&err);

    Q_ASSERT(err==GIF_OK);

    Q_ASSERT(GifFile);

    int Result=EGifPutScreenDesc(
            GifFile,
            kuan_, gao_, 1, 0,
            tiaoSeBan
            ) ;

    Q_ASSERT(Result!=GIF_ERROR);

    bool chengGong=tianJiaXunHuan(GifFile);

    Q_ASSERT(chengGong);

    for (int zhenShu=0,daXiao=suoYouZhen_.size(); zhenShu<daXiao; ++zhenShu) {

        static unsigned char
            ExtStr[4] = { 0x04, 0x00, 0x00, 0xff };


        ExtStr[0] = (false) ? 0x06 : 0x04;
        ExtStr[1] = haoMiao*100 % 256;
        ExtStr[2] = haoMiao*100 / 256;

        /* Dump graphics control block. */
        EGifPutExtension(GifFile, GRAPHICS_EXT_FUNC_CODE, 4, ExtStr);


        Result=EGifPutImageDesc(
                GifFile,
                0, 0, kuan_, gao_, false, NULL
                ) ;

        Q_ASSERT(Result!=GIF_ERROR);


        QImage zhen=suoYouZhen_[zhenShu];


        for (int y = 0 ; y < gao_; y++) {

            Result=EGifPutLine(GifFile, zhen.scanLine(y), kuan_);
            Q_ASSERT(Result!=GIF_ERROR);
        }
    }

    Result=EGifCloseFile(GifFile);

    Q_ASSERT(fanHui.size()>0);

    Q_ASSERT(Result== GIF_OK); 

    return fanHui;

}


  
