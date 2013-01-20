#include "FrameSegment.h"

#include <QDebug>
#include <QMovie>


FrameSegment::FrameSegment(const QString &gifFileName){


    Q_ASSERT(gifFileName.endsWith("gif"));


    QMovie gif(gifFileName);
    if(!gif.isValid()){
        return;
    }


    gif.start();
    gif.setPaused(true);

    for(int i=0,size=gif.frameCount();i<size;++i){

        QImage frame=gif.currentImage();

        Q_ASSERT(!frame.isNull());

        frames_.append(Frame(frame,gif.nextFrameDelay()));

        gif.jumpToNextFrame();

    }

    gif.stop();

}
