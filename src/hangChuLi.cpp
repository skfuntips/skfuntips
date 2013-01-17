#include "hangChuLi.h"

#include <boost/bind.hpp>

#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QTextBlock>
#include <QPainter>
#include <QTextLayout>
#include <QScrollBar>
#include <QTextStream>
#include <QTextEdit>
#include <QPlainTextEdit>

#include "encdet.h"

static void hangChuLi(QTextStream& ziFuLiu,ChuLiHanShu chuLiHanShu){

    while(true){
        QString benHang=ziFuLiu.readLine();
        if (benHang.isNull()) {
            return;
        }

        if (benHang.isEmpty()) {
            continue;
        }

        bool chengGong=chuLiHanShu(benHang);

        if (chengGong) {
            continue;
        }

        return;

    }

}

void hangChuLi(const QStringList& duoHang,ChuLiHanShu chuLiHanShu){

    foreach(const QString& yiHang,duoHang){

        bool Result=chuLiHanShu(yiHang);
        if(!Result){
            return;
        }

    }

}

void hangChuLi(QFile& wenJian,ChuLiHanShu chuLiHanShu){

    Q_ASSERT(wenJian.exists());

    if (!wenJian.isOpen()) {
	 bool chengGong=wenJian.open(QIODevice::ReadOnly);
	 Q_ASSERT(chengGong);
    }

    const QByteArray erJinZhi=wenJian.readAll();

    encdet_t cai=encdet_new(ENCDET_CHINESE);

    int rc = encdet_handle_data(cai,erJinZhi.data(),erJinZhi.size());

    QString bianMa("UTF-8");

    if(!rc){
        encdet_data_end(cai);
        bianMa=encdet_get_result(cai);
    }


    encdet_destroy(cai);

    QTextStream ziFuLiu(erJinZhi);
    ziFuLiu.setCodec(bianMa.toUtf8().constData());

    hangChuLi(ziFuLiu,chuLiHanShu);
}

void hangChuLi(const QString& ziFuChuan,ChuLiHanShu chuLiHanShu){

    QString linShi=ziFuChuan;

    QTextStream ziFuLiu(&linShi,QIODevice::ReadOnly);

    hangChuLi(ziFuLiu,chuLiHanShu);
}

QString heBingDuoHang(const QStringList& duoHang,bool addLineBreak,int qiShi,int jieShu){

    QString fanHuiZhi;

    if(qiShi==-1){
        qiShi=0;
    }


    if(jieShu==-1){
        jieShu=duoHang.size();
    }
    jieShu=qMin<int>(jieShu,duoHang.size());

    Q_ASSERT(qiShi<=jieShu);

    bool hasBreak=false;

    for(int i=qiShi;i<jieShu;++i){
        fanHuiZhi.append(duoHang[i]);
        if(addLineBreak){
            fanHuiZhi.append('\n');
            hasBreak=true;
        }
    }

    if(hasBreak){
        Q_ASSERT(fanHuiZhi.endsWith('\n'));
        fanHuiZhi.resize(fanHuiZhi.size()-1);
    }

    return fanHuiZhi;
}


static bool heBing(QString& heBing,const QString& tianJia){
    heBing.append(tianJia);
    return true;
}

QString quChuHuanHang(const QString& duoHang){

    QString linShi=duoHang;

    QTextStream ziFuLiu(&linShi,QIODevice::WriteOnly);

    QString Result;

    hangChuLi(ziFuLiu,boost::bind(heBing,boost::ref(Result),_1));

    return Result;
}

static bool duanKai(QStringList& Result,int hangKuanDu,const QString& yiHang){

    int dangQianWeiZhi=0;


    do{

        int shengYu=yiHang.size()-dangQianWeiZhi;

        if(shengYu==0){
            break;
        }

        Q_ASSERT(shengYu>0);

        int benCiChangDu=qMin<int>(shengYu,hangKuanDu);

        Result.push_back(yiHang.mid(dangQianWeiZhi,benCiChangDu));

        dangQianWeiZhi+=benCiChangDu;

        Q_ASSERT(dangQianWeiZhi<=yiHang.size());
    
    }while(true);

    return true;

}

QStringList hangDuanKai(const QString& ziFuChuan,int hangKuanDu){

    QStringList Result;

    hangChuLi(ziFuChuan,boost::bind(
                duanKai,boost::ref(Result),hangKuanDu,_1));

    return Result;
}

QStringList kongJianWenBen(QTextDocument* wenDang){

    QSizeF size=wenDang->size();

    QImage linShi(size.toSize(),QImage::Format_Mono);

    QPainter huiZhi(&linShi);

    wenDang->drawContents(&huiZhi);


    QTextBlock kuai=wenDang->firstBlock();

    QStringList neiRong;

    while(kuai.isValid()){

        QTextLayout *buJu=kuai.layout();

        Q_ASSERT(buJu);

        QString wenBen=kuai.text();


        bool zhiShao=false;

        for(int i=0,hangShu=buJu->lineCount();i<hangShu;++i){

            QTextLine wenBenHang=buJu->lineAt(i);

            QString hang=wenBen.mid(wenBenHang.textStart(),wenBenHang.textLength());
            neiRong.push_back(hang);

            zhiShao=true;

        }

        Q_ASSERT(zhiShao);

        kuai=kuai.next();
    }

    return neiRong;
}

void tianChong(QTextDocument *buJu, const QStringList &neiRong){

    Q_ASSERT(buJu);

    QTextCursor guangBiao(buJu);

    foreach(const QString& hang,neiRong){
        guangBiao.insertText(hang);
        guangBiao.insertText("\n");
    }



}
