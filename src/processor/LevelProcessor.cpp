
#include "LevelProcessor.h"
#include "IntRangeParam.h"

LevelProcessor::LevelProcessor():
    jiBie_(new IntRangeParam(this)){

    }

ParamList LevelProcessor::paramList(){

    ParamList fanHuiZhi;
    fanHuiZhi.push_back(jiBie_);
    return fanHuiZhi;
}


int LevelProcessor::jiBieZhi()const{
     return jiBie_->shuZhi();
}

void LevelProcessor::sheZhiJiBie(int jiBie){
     return jiBie_->sheZhiShuZhi(jiBie);
}

