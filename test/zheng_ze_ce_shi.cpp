#include "KeywordsDB.h"

#include <QDebug>
#include <QFile>
#include <QApplication>

#include "hangChuLi.h"

QRegExp p;

bool test(const QString& yiHang){
     Q_ASSERT(yiHang.indexOf(p)!=-1);
     return true;
}

int main(int argc, char * argv[])
{
    QApplication app(argc,argv);

     QString ceShi("原子弹");

     p=KeywordsDB::instance().regexp();

     QFile file(":/KeywordsDB.txt");

     Q_ASSERT(file.exists());

     hangChuLi(file,test);

     return 0;
}
