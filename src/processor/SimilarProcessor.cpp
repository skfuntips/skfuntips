#include "SimilarProcessor.h"
#include "PinYinDB.h"
#include "SeedParam.h"
#include "IntRangeParam.h"
#include "Result.h"

#include <iostream>

#include <QDebug>

SimilarProcessor::SimilarProcessor(){
    jiBie()->sheZhiSuoYou(0,0,1);
    jiBie()->setName(tr("level"));
    jiBie()->setDescription(tr("0:simple similar char,1:all similar char"));

}

QString SimilarProcessor::description()const{
    return tr("use similar char to replace origin");
}

QString SimilarProcessor::name()const{
     return tr("similar process");
}

Result SimilarProcessor::process(const QStringList& ziFuChuan){

    if (ziFuChuan.isEmpty()) {
        return ziFuChuan;
    }

    QStringList fanHuiZhi;

    foreach(const QString& hang,ziFuChuan){

        if (hang.isEmpty()) {
            fanHuiZhi.append(hang);
            continue;
        }

        QString shangCiResult;

        QString hangResult;

        for(int i=0;i<100;++i){

            foreach(const QChar& zi,hang){

                QChar tongYin;

                for(int j=0;j<100;++j){

                    if (jiBieZhi()<1) {
                        tongYin=PinYinDB::shiLi().tongYinZiChangYong(zi);
                    }else{
                        tongYin=PinYinDB::shiLi().tongYinZiSuoYou(zi);
                    }

                    if ((jiBieZhi()>=1)&&(tongYin==zi)){
                        continue;
                    }else{
                        break;
                    }
                }

                hangResult.push_back(tongYin);
            }



            if (hang==hangResult) {
                shangCiResult=hangResult;
                hangResult.clear();
                continue;
            }

            Q_ASSERT(hangResult.size()==hang.size());
            shangCiResult=hangResult;
            break;
        }

        Q_ASSERT(shangCiResult.size()==hang.size());
        fanHuiZhi.append(shangCiResult);

    }

    Q_ASSERT(fanHuiZhi.size()==ziFuChuan.size());
    return fanHuiZhi;
}

