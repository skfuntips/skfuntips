
#include "KeywordsDB.h"
#include "QtResource.h"
#include "hangChuLi.h"

#include <boost/bind.hpp>
#include <boost/foreach.hpp>

#include <QDebug>




static bool zuHeBiaoDaShi(const QString& yiHang,QString& Result){
    Result.append(yiHang.trimmed()).append('|');
    return true;
}



void KeywordsDB::externalFileChanged(){
    CompositeResource::externalFileChanged();

    pattern_[EXTERNAL].clear();
    hangChuLi(type(EXTERNAL),
              boost::bind(zuHeBiaoDaShi,_1,boost::ref(pattern_[EXTERNAL])));
    pattern_[EXTERNAL].resize(qMax((pattern_[EXTERNAL].size()-1),0));


    pattern_[ALL]=pattern_[INTERNAL];

    if(!pattern_[ALL].isEmpty() && !pattern_[EXTERNAL].isEmpty()){

        pattern_[ALL].append('|').append(pattern_[EXTERNAL]);

   }

   regexp_[EXTERNAL].setPattern(pattern_[EXTERNAL]);
   regexp_[ALL].setPattern(pattern_[ALL]);

   emit chongZhi();

}

KeywordsDB::KeywordsDB():
    CompositeResource("KeywordsDB.txt"){



    BOOST_FOREACH(QString& ziFuChuan,pattern_){
        ziFuChuan="";
    }


     hangChuLi(type(INTERNAL),
               boost::bind(zuHeBiaoDaShi,_1,boost::ref(pattern_[INTERNAL])));

     pattern_[INTERNAL].resize(qMax((pattern_[INTERNAL].size()-1),0));

    regexp_[INTERNAL].setPattern(pattern_[INTERNAL]);

    externalFileChanged();

}


