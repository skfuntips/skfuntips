
#ifndef JI_BIE_ZHONG_ZI_CHU_LI_H
#define JI_BIE_ZHONG_ZI_CHU_LI_H

#include "LevelProcessor.h"

class SeedParam;

class LevelSeedProcessor :public LevelProcessor{
     Q_OBJECT
public:
    LevelSeedProcessor();

    virtual ~LevelSeedProcessor(){}

	void sheZhiZiFuChuan(const QString& ziFuChuan);
      
	virtual ParamList paramList();
protected:

    SeedParam *zhongZi(){
	     return zhongZi_;
	}
private:

    SeedParam *zhongZi_;
};

#endif /* end of include guard */
