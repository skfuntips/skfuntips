#include "gongJu.h"

#include <QFileDialog>
#include <QApplication>
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


QList<QImage> loadImages(QWidget* parent){
    QStringList fileNames=QFileDialog::getOpenFileNames
        (parent,QObject::tr("open file"),QString(),"*.bmp *.jpg *.png");

    QList<QImage> ret;

    foreach(const QString& fileName,fileNames){

        QImage image(fileName);
        if(!image.isNull()){
            ret.append(image);
        }
    }

    return ret;

}
