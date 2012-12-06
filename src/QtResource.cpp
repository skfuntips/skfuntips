
#include "QtResource.h"

#include <cstdlib>

#include <QDir>
#include <QTime>

QtResource::QtResource(){
    QTime v=QTime::currentTime();

    std::srand(v.msec());

    Q_INIT_RESOURCE(r);
}

QtResource::~QtResource(){
    Q_CLEANUP_RESOURCE(r);
}

