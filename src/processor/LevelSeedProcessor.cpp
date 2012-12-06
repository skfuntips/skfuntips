
#include "LevelSeedProcessor.h"
#include "SeedParam.h"

LevelSeedProcessor::LevelSeedProcessor()
     :zhongZi_(new SeedParam(this)){

     }

ParamList LevelSeedProcessor::paramList(){
     ParamList Result=LevelProcessor::paramList();
     Result.push_back(zhongZi_);
     return Result;
}

void LevelSeedProcessor::sheZhiZiFuChuan(const QString& ziFuChuan){
    zhongZi_->sheZhiZiFuChuan(ziFuChuan);
}
