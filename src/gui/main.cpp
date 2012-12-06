#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QDir>

#include "MainFrame.h"

int main(int argc, char * argv[])
{
     QApplication app(argc,argv);

     app.addLibraryPath(QApplication::applicationDirPath()+QDir::separator()+"plugins");

     QString locale = QLocale::system().name();

     QTranslator translator;
     translator.load(locale);
     app.installTranslator(&translator);

     MainFrame MainFrame;

     MainFrame.show();
	
     return app.exec();
}
