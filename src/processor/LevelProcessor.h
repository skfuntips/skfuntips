#ifndef JI_BIE_CHU_LI_H
#define JI_BIE_CHU_LI_H

#include "IProcessor.h"
#include "SeedParam.h"


class IntRangeParam;

class LevelProcessor:public IProcessor {
    Q_OBJECT

     public:

     LevelProcessor();

     virtual ParamList paramList();

     virtual ~LevelProcessor(){}

     void sheZhiJiBie(int jiBie);

     int jiBieZhi()const;

    IntRangeParam *jiBie(){
	     return jiBie_;
	}

     private:

     IntRangeParam *jiBie_;

};

#endif /* end of include guard */
