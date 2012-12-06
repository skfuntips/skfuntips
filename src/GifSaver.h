#ifndef GIF_BAO_CUN_H
#define GIF_BAO_CUN_H

#include <vector>
#include <QImage>


class GifSaver{
public:
  
  GifSaver(int kuan, int gao);

  void tianJiaYiZhen(const QImage& zhen);
  
  QByteArray baoCunLinShi(int haoMiao);

private:

  int kuan_;
  int gao_;

  std::vector<QImage> suoYouZhen_;

  
};

#endif//GIF_BAO_CUN_H
