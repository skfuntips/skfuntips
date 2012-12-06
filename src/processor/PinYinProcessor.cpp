#include "PinYinProcessor.h"
#include "PinYinDB.h"
#include "Result.h"
#include <QStringList>

Result PinYinProcessor::process(const QStringList &f){

    QStringList fanHuiZhi;

    int jiShu=0,
            zongShu=f.size();

    foreach(const QString& hang,f){

        QString hangResult;

        foreach(QChar ziFu,hang){

            if(ziFu.unicode()>=256){
                hangResult.append(
                            PinYinDB::shiLi().pinYin(ziFu)).
                        append(' ');
            }else{
                hangResult.append(ziFu);
            }

            ++jiShu;
            emit processPercent(jiShu/qreal(zongShu)*100);
        }

        fanHuiZhi.append(hangResult);
    }
    
    return fanHuiZhi;

}

QString PinYinProcessor::description()const{
    return QString::fromUtf8("用拼音替代文字（多音字可能有误）");
}


QString PinYinProcessor::name()const{
    return QString::fromUtf8("变拼音处理");
}


ParamList PinYinProcessor::paramList(){
    return ParamList();
}
