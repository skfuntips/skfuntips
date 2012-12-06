#include "CompositeResource.h"

#include <boost/bind.hpp>

#include <QFileSystemWatcher>
#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFile>

#include "hangChuLi.h"
#include "QtResource.h"

static bool fuJia(const QString& hang,QStringList& Result){

    Result.push_back(hang.trimmed());

    return true;
}


static QString zuHeWaiZhi(const QString& moBan){

    QString path=QApplication::instance()->applicationDirPath()+QDir::separator();
    return path+moBan;
}

CompositeResource::CompositeResource(const QString &moBan):
    watcher_(new QFileSystemWatcher(this)){

    QtResource::instance();

    type_=ALL;

    internalFilename_=":/"+moBan;

    externalFilename_=zuHeWaiZhi(moBan);

    watcher_->addPath(externalFilename_);

    connect(watcher_,SIGNAL(fileChanged(const QString&)),
            this,SLOT(externalFileChanged()));



    QFile neiZhi(internalFilename_);

    if(neiZhi.exists()){
        processFile(neiZhi,INTERNAL);
    }else{
        Q_ASSERT(false);
    }



    CompositeResource::externalFileChanged();

}


void CompositeResource::externalFileChanged(){

    QFile waiZhi(externalFilename_);

    contents_[ALL]=contents_[INTERNAL];

    if(waiZhi.exists()){
        processFile(waiZhi,EXTERNAL);
    }

    contents_[ALL]<<contents_[EXTERNAL];


}

void CompositeResource::processFile(QFile& file,Type leiXing){

    contents_[leiXing].clear();

    hangChuLi(file,boost::bind(fuJia,_1,boost::ref(contents_[leiXing])));
}
