#ifndef FRAME_H
#define FRAME_H

#include <QPair>
#include <QImage>

static const int STATIC_FRAME=-1;

typedef QPair<QImage,int> Frame;

typedef QList<Frame> Frames;

#endif //FRAME_H
