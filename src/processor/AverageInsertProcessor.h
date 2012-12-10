
#ifndef PING_JUN_CHA_R_CH_LI_H
#define PING_JUN_CHA_R_CH_LI_H

#include "LevelSeedProcessor.h"

class AverageInsertProcessor :public LevelSeedProcessor{
    Q_OBJECT

     public:
         AverageInsertProcessor();

	  virtual QString name()const;

         virtual QString description()const;

      virtual Result process(const QStringList& ziFuChuan);

      virtual ~AverageInsertProcessor (){}

      virtual ParamList paramList();


         virtual ResultType resultType()const{
             return STRING;
         }

     private:

      IntRangeParam *yuanShiKuanDu_;
};

#endif /* end of include guard */
