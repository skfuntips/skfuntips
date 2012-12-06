#ifndef CHU_LI_XIAN_CHENG_H
#define CHU_LI_XIAN_CHENG_H

#include <QThread>
#include <QStringList>

#include "IProcessor.h"
#include "hangChuLi.h"
#include "Result.h"

class ProcessThread :public QThread{

    Q_OBJECT

public:

    ProcessThread(QStringList shuRu,IProcessor* jieKou){
        shuRu_=shuRu;
        jieKou_=jieKou;
    }

    Result result(){
        return result_;
    }

    virtual ~ProcessThread(){}

protected:

    virtual void run(){
        result_=jieKou_->process(shuRu_);
    }

private:

    QStringList shuRu_;

    IProcessor *jieKou_;

    Result result_;
};

#endif
