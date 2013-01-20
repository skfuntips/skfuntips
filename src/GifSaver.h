#ifndef GIF_BAO_CUN_H
#define GIF_BAO_CUN_H


#include <QImage>

#include "Frame.h"

class FrameSegment;

class GifSaver{
public:
  
  GifSaver(int kuan, int gao);

  void addFrame(const Frame& frame);

  void addFrameSegment(const FrameSegment& frameSegment);
  
  QByteArray save(int haoMiao);

private:

  int kuan_;
  int gao_;

  Frames frames_;

  QImage firstColorImage_;

  
};

#endif//GIF_BAO_CUN_H
