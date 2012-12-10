#include <QApplication>
#include <QMessageBox>

#include "gui/SourceWidget.h"

int main(int argc, char * argv[])
{
    QApplication app(argc,argv);

    SourceWidget kongJian;

    QMessageBox tiShi(QMessageBox::Information,
            "info","text changed",QMessageBox::Ok);


    QObject::connect(
            &kongJian,SIGNAL(contentsChanged()),
            &tiShi,SLOT(show()));

    kongJian.show();
    
    return app.exec();
}
