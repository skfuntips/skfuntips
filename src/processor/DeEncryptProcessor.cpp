#include "DeEncryptProcessor.h"
#include "StringParam.h"
#include "Result.h"

#include <QMap>


DeEncryptProcessor::DeEncryptProcessor():
    string_(new StringParam(this)){

    string_->setName(tr("password"));
    string_->setDescription(tr("16 char password"));
    string_->sheZhiZiFuChuan(tr("abcd efgh ijkl mnop"));

}

QString DeEncryptProcessor::name()const{
    return tr("de-encrypt process");
}

QString DeEncryptProcessor::description()const{
    return tr("use 16 char to de-encrypt origin text");
}


Result DeEncryptProcessor::process(const QStringList& ziFuChuan){

    QString password=string_->ziFuChuan();

    password.remove(QRegExp("\\s"));

    if(password.size()!=16){
        return QStringList(tr("password is not 16 length"));
    }

    for(int i=0;i<16;++i){
        if(password.indexOf(password[i],i+1)!=-1){
            return QStringList(tr("password can not contains duplicate char")+password[i]);
        }
    }


    QMap<QChar,uchar> map;

    for(int i=0;i<16;++i){
        map[password[i]]=i;
    }

    QStringList ret;


    QString notFill;

    for(int i=0,size=ziFuChuan.size();i<size;++i){

        emit processPercent(i/qreal(size));

        QString thisLine=notFill+ziFuChuan[i];

        thisLine.replace(QRegExp("\\s"),QString(""));

        foreach(QChar thisChar,thisLine){
            if(!map.contains(thisChar)){
                return QStringList(tr("unable to de-encrypt ,wrong password?"));
            }
        }

        const int number=thisLine.size()/4;

        int mod=thisLine.size()%4;

        notFill=thisLine.right(mod);

        QString resultLine;

        for(int j=0;j<number;++j){
            int base=j*4;
            uchar cellLow=map[thisLine[base]],
                    cellHigh=map[thisLine[base+1]],
                    rowLow=map[thisLine[base+2]],
                    rowHigh=map[thisLine[base+3]];

            uchar cell=cellLow+(cellHigh<<4),
                    row=rowLow+(rowHigh<<4);

            QChar thisChar(cell,row);

            resultLine.append(thisChar);

        }

        ret.append(resultLine);

        emit processPercent(qreal(i)/size);

    }

    emit processPercent(1);


    return ret;

}

ParamList DeEncryptProcessor::paramList(){
    ParamList ret;
    ret.push_back(string_);
    return ret;
}
