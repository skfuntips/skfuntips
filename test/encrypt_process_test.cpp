#include "processor/EncryptProcessor.h"
#include "processor/DeEncryptProcessor.h"
#include "Result.h"

#include <QDebug>
#include <QStringList>


int main(int argc,char** argv){

    EncryptProcessor enc;
    DeEncryptProcessor deEnc;

    for(int i=0;i<65536;++i){

        QChar originChar(i);
        QStringList input;
        input.append(QString(originChar));

        Result result=enc.process(input);

        Result dec=deEnc.process(result.string());

        Q_ASSERT(input==dec.string());

    }


}
