#ifndef FRAME_SEGMENT_H
#define FRAME_SEGMENT_H

#include "Frame.h"

#include <QList>

class FrameSegment{

public:



    FrameSegment(const QImage& image){
        frames_.append(Frame(image,STATIC_FRAME));
    }

    FrameSegment(const QString& gifFileName);

    const Frames& frames()const{
        return frames_;
    }

    bool isValid()const{
        return !frames_.isEmpty();
    }

private:

    Frames frames_;

};

typedef QList<FrameSegment> Segments;

#endif //FRAME_SEGMENT_H
