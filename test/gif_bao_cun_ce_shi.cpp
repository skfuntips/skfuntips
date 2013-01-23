
#include "GifSaver.h"
#include "Result.h"
#include "Frame.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QImage a1(100,100,QImage::Format_Mono),
           a2(100,100,QImage::Format_Mono);

    a1.fill(Qt::white);
    a2.fill(Qt::black);

    GifSaver baoCun(100,100);

    baoCun.addFrame(Frame(a1,STATIC_FRAME));
    baoCun.addFrame(Frame(a2,STATIC_FRAME));

    Result Result(baoCun.save(1000));

    Result.saveFile("gif.gif");
    
    return 0;
}
