#include "Result.h"

#include <QClipboard>
#include <QApplication>
#include <QTextStream>
#include <QMovie>
#include <QFile>

#include "Gif.h"
#include "hangChuLi.h"


Result::Result(const QStringList& ziFuChuan){

    type_=STRING;


        string_=ziFuChuan;
        return;

}
Result::Result(const QByteArray& erJinZhi){
    type_=GIF_ANIMATION;

    gifBinary_=erJinZhi;

}



bool Result::saveFile(const QString& wenJianMing){

        
    QString shiJi=wenJianMing;

    switch(type_) {

    case STRING:
    {

        if (!wenJianMing.endsWith(".txt",Qt::CaseInsensitive)) {
            shiJi.append(".txt");
        }

        QFile wenJian(shiJi);
        bool Result=wenJian.open(QIODevice::WriteOnly);

        if (!Result) {
            return false;
        }

        QTextStream wenJianLiu(&wenJian);
        wenJianLiu.setCodec("UTF-8");
        foreach(const QString& hang,string_){
            wenJianLiu<<hang<<'\n';
        }

        return true;

    }
    case IMAGE:{

        if (!((wenJianMing.endsWith(".bmp",Qt::CaseInsensitive))||
             (wenJianMing.endsWith(".jpg",Qt::CaseInsensitive)||
              (wenJianMing.endsWith(".png",Qt::CaseInsensitive))))) {
              shiJi.append(".jpg");
        }

        return image_.save(shiJi);
    }
    case GIF_ANIMATION:{


        if (!wenJianMing.endsWith(".gif",Qt::CaseInsensitive)){
            shiJi.append(".gif");
        }

        Q_ASSERT(!gifBinary_.isEmpty());

        if(QFile::exists(shiJi)){
            if (!QFile::remove(shiJi)){
                return false;
            }
        }

        QFile wenJian(shiJi);

        bool daKai=wenJian.open(QIODevice::WriteOnly);

        Q_ASSERT(daKai);

        int duoShao=wenJian.write(gifBinary_);

        Q_ASSERT(duoShao==gifBinary_.size());

        return true;
    }

    }

    return false;
}


bool Result::saveClipboard(){

    QClipboard * jianQieBan=QApplication::clipboard();

    if (type_==STRING) {
        jianQieBan->setText(heBingDuoHang(string_));
    }else if(type_==IMAGE){
        jianQieBan->setImage(image_);
    }else{
        return false;
    }

    return true;
}

