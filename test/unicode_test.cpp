#include <QApplication>
#include <QDebug>
#include <QChar>


int main(int argc,char** argv){

    QApplication app(argc,argv);

    QTextStream output(stdout);


    for(int i=0;i<65536;++i){
        ushort unicode=i;

        QChar one(unicode);

        output<<one<<' '<<unicode<<'\n';
    }


}
