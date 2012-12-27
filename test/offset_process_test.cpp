#include "processor/OffsetProcessor.h"
#include "Result.h"

#include <QDebug>


int main(int argc,char** argv){

    OffsetProcessor enc,deEnc;


    for(int i=0;i<65536;++i){


        for(int j=-65535;j<65536;++j){

            enc.setOffset(j);
            deEnc.setOffset(-j);

            QChar originChar(i);
            QStringList input;
            input.append(QString(originChar));

            Result result=enc.process(input);

            Result dec=deEnc.process(result.string());

            Q_ASSERT(input==dec.string());

        }


    }


}
