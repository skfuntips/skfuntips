
#include <QApplication>

template <class T>
int jianLiCeShi(int& argc,char** argv){

    QApplication app(argc,argv);

    T t1,t2;

    t2.setSignalSource(false);

    typename T::ParamType canShu;

    t1.bindParam(&canShu);

    t2.bindParam(&canShu);

    t1.show();
    t2.show();

    return app.exec();
}
