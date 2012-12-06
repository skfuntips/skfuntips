
#include "GifSaver.h"
#include "Result.h"

#include <QImage>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QImage a1(100,100,QImage::Format_Mono),
           a2(100,100,QImage::Format_Mono);

    a1.fill(Qt::white);
    a2.fill(Qt::black);

    GifSaver baoCun(100,100);

    baoCun.tianJiaYiZhen(a1);
    baoCun.tianJiaYiZhen(a2);

    Result Result(baoCun.baoCunLinShi(1));

    Result.saveFile("gif.gif");
    
    return 0;
}
