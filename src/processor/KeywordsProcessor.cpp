
#include "KeywordsProcessor.h"
#include "KeywordsDB.h"
#include "Result.h"

#include "InsertProcessor.h"
#include "IntRangeParam.h"
#include "SimilarProcessor.h"
#include "PinYinProcessor.h"
#include "ReverseProcessor.h"
#include "ShuffleProcessor.h"

#include <algorithm>

#include <boost/foreach.hpp>

#include <QDebug>


template<class T>
void KeywordsProcessor::chaRu(bool canShu){
    shiJi_.push_back(new T());

    if(!canShu){
        return;
    }

    connect(shiJi_.back(),SIGNAL(paramDirty()),this,SIGNAL(paramDirty()));

    BOOST_FOREACH(IParam* canShu,shiJi_.back()->paramList()){

        canShu->setName(shiJi_.back()->name()+":"+canShu->name());

        canShuLieBiao_.push_back(canShu);

    }

}

KeywordsProcessor::KeywordsProcessor(){

    jiBie()->setName(tr("process type"));
    jiBie()->setDescription(tr("-1:random select,0:insert process,1:similar process,2:pinyin process,3:shuffle process,4:reverse process"));
    jiBie()->sheZhiSuoYou(-1,-1,4);

    canShuLieBiao_.push_back(jiBie());

    baoZhang_=new InsertProcessor();

    chaRu<InsertProcessor>();
    chaRu<SimilarProcessor>();
    chaRu<PinYinProcessor>();
    chaRu<ShuffleProcessor>();
    chaRu<ReverseProcessor>(false);



}


Result KeywordsProcessor::process(const QStringList& ziFuChuan){

    const QRegExp& zhengZe=KeywordsDB::instance().regexp();
    QStringList Result;

    int xuanZe=jiBieZhi();

    foreach(const QString& hang,ziFuChuan){

        int qiShi=0;
        int dangQianWeiZhi=0;

        QString hangResult;

        while ((qiShi = zhengZe.indexIn
                    (hang,dangQianWeiZhi)) != -1) {

            int tiaoGuo=qiShi-dangQianWeiZhi;

            hangResult.append(hang.mid(dangQianWeiZhi,tiaoGuo));

            QString guanJianCi=zhengZe.cap();

            if(guanJianCi.isEmpty()){
                break;
            }

            int suiJi=(xuanZe==-1?
                           qrand()%shiJi_.size():
                           xuanZe);

            QStringList tiHuan=shiJi_[suiJi]->process(QStringList(guanJianCi));

            Q_ASSERT(tiHuan.size()==1);

            if (tiHuan[0]==guanJianCi) {
                tiHuan=baoZhang_->process(tiHuan).string();
            }

            Q_ASSERT(tiHuan.size()==1);

            Q_ASSERT(tiHuan[0]!=guanJianCi);

            hangResult.append(tiHuan[0]);

            dangQianWeiZhi=qiShi+guanJianCi.size();

        }

        hangResult.append(hang.mid(dangQianWeiZhi));

        Result.append(hangResult);
    }



    return Result;
}

QString KeywordsProcessor::name()const{
    return tr("keywords process");
}

QString KeywordsProcessor::description()const{
    return tr("process keywords by a selected method, hidden your true feeling into text (needs to config keywords DB)");
}
