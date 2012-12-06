#include "haXi.h"

#include <boost/unordered_set.hpp>

#include <QRegExp>
#include <QDebug>
#include <QStringList>
#include <QTextStream>
#include <QTextCodec>

typedef QPair<QChar,QString> BD;

std::size_t hash_value(BD const& sl){
    std::size_t bn=0;
    boost::hash_combine(bn,sl.first);
    boost::hash_combine(bn,sl.second);
    return bn;
}



int main(int argc, char const* argv[])
{

    QTextCodec *ca= QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(ca);


    QTextStream i(stdin);

    i.setCodec(ca);

    QRegExp dxb("\\d");

    QTextStream bnn(stdout);
    bnn.setCodec(ca);

    boost::unordered_set<BD> mb;

    while(true){

        QString l=i.readLine();

        if (l.isNull()) {
            break;
        }

        if (l.isEmpty()) {
            continue;
        }

        QTextStream ls(&l);


        QString t,g,p;

        ls>>t>>g>>p;

        Q_ASSERT((!t.isEmpty())&&(!t.isNull()));
        Q_ASSERT((!p.isEmpty())&&(!p.isNull()));


        QStringList lbn=p.split(dxb);

        foreach(const QChar& c,t){

            foreach(const QString& w,lbn){

                if (w.isEmpty()) {
                    continue;
                }

                if(mb.count(BD(c,w))!=0){
                    continue;
                }

                mb.insert(BD(c,w));

            }

        }

    }

    foreach(const BD& o,mb){

        bnn<<o.first<<' '<<o.second<<'\n';
    }
    
}
