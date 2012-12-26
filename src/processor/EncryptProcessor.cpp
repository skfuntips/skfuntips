#include "EncryptProcessor.h"
#include "StringParam.h"
#include "Result.h"


EncryptProcessor::EncryptProcessor():
    string_(new StringParam(this)){

    string_->setName(tr("password"));
    string_->setDescription(tr("16 char password"));
    string_->sheZhiZiFuChuan(tr("abcd efgh ijkl mnop"));

}

QString EncryptProcessor::name()const{
    return tr("encrypt process");
}

QString EncryptProcessor::description()const{
    return tr("use 16 char to encrypt origin text");
}


Result EncryptProcessor::process(const QStringList& ziFuChuan){

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

    QStringList ret;

    for(int i=0,size=ziFuChuan.size();i<size;++i){

        emit processPercent(i/qreal(size));

        QString resultLine;

        foreach(QChar one,ziFuChuan[i]){
            uint8_t cell=one.cell(),
                    row=one.row();

            QString temp;

            temp
                    .append(password[cell&15])
                    .append(password[(cell&(15<<4))>>4])
                    .append(password[row&15])
                    .append(password[(row&(15<<4))>>4]);

            resultLine.append(temp);
        }
        ret.append(resultLine);

    }

    emit processPercent(1);


    return ret;

}

ParamList EncryptProcessor::paramList(){
    ParamList ret;
    ret.push_back(string_);
    return ret;
}
