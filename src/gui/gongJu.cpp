#include "gongJu.h"

#include <QFileDialog>
#include <QApplication>
#include <QDebug>
#include <QMovie>
#include <QClipboard>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QString>


QString wenJianWenBen(QWidget* parent){

     QString wenJianMing=QFileDialog::getOpenFileName
         (parent,QObject::tr("open file"),QString(),"*.txt");

     if (wenJianMing.isNull()) {
         return QString();
     }

     QFile wenJian(wenJianMing);

     bool Result=wenJian.open(QIODevice::ReadOnly);

     if(!Result){
         QMessageBox::critical(parent,QObject::tr("unable to open file"),
                 QObject::tr("file open failed"));
         return QString();
     }

     QTextStream wenJianLiu(&wenJian);

     wenJianLiu.setCodec("UTF-8");

     return wenJianLiu.readAll();
}

QString jianQieBanWenBen(QWidget* parent){

    QClipboard *jianQieBan=QApplication::clipboard();

    QString zhanTie=jianQieBan->text();

    if (zhanTie.isEmpty()) {
        QMessageBox::information(parent,QObject::tr("warning"),
                QObject::tr("no text content in clipboard"));
        return QString();
    }

    return zhanTie;
}

static QList<QImage> loadGif(const QString& fileName){

    QList<QImage> ret;

    QMovie gif(fileName);
    if(!gif.isValid()){
        return ret;
    }

    gif.start();
    gif.setPaused(true);

    for(int i=0,size=gif.frameCount();i<size;++i){

        QImage frame=gif.currentImage();

        Q_ASSERT(!frame.isNull());

        ret.append(frame);
        gif.jumpToNextFrame();

    }

    return ret;

}

QList<QImage> loadImages(QWidget* parent){
    QStringList fileNames=QFileDialog::getOpenFileNames
        (parent,QObject::tr("open file"),QString(),"*.bmp *.jpg *.png *.gif");

    QList<QImage> ret;

    foreach(const QString& fileName,fileNames){

        if(fileName.endsWith("gif")){
            ret.append(loadGif(fileName));
            continue;
        }

        QImage image(fileName);
        if(!image.isNull()){
            ret.append(image);
        }
    }

    return ret;

}
