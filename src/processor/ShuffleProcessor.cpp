
#include "ShuffleProcessor.h"
#include "Result.h"

#include <algorithm>

QString ShuffleProcessor::name()const{
    return tr("shuffle process");
}

QString ShuffleProcessor::description()const{
    return tr("shuffle text to puzzle");
}

Result ShuffleProcessor::process(const QStringList& ziFuChuan){
    if (ziFuChuan.isEmpty()) {
        return ziFuChuan;
    }

    QStringList Result;

    foreach(const QString& hang,ziFuChuan){

        if (hang.isEmpty()) {
            Result.append(hang);
            continue;
        }

        if (hang.count(hang[0])==hang.size()) {
            Result.append(hang);
            continue;
        }

            
        QString hangResult(hang);

        for (int i = 0; i < 5; i++) {
            std::random_shuffle(hangResult.begin(),hangResult.end());

            if (hangResult==hang) {
                continue;
            }
        }
                
        Result.append(hangResult);
    }

    return Result;
}

