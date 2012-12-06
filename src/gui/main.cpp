#include <QApplication>
#include <QTranslator>
#include <QLocale>

#include "MainFrame.h"

int main(int argc, char * argv[])
{
     QApplication app(argc,argv);

     QString locale = QLocale::system().name();

     QTranslator translator;
     translator.load(locale);
     app.installTranslator(&translator);

     MainFrame MainFrame;

     MainFrame.show();
	
     return app.exec();
}
