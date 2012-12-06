#ifndef CHA_RU_CHU_LI_H
#define CHA_RU_CHU_LI_H

#include "LevelSeedProcessor.h"


class InsertProcessor :public LevelSeedProcessor{

    typedef LevelSeedProcessor FuLeiXing;

    Q_OBJECT

     public:

      InsertProcessor();

      virtual ~InsertProcessor (){}

	  virtual QString name()const;

      virtual QString description()const;

	  virtual Result process(const QStringList& f);

      virtual ResultType resultLeiXing()const{
          return STRING;
      }

      virtual ParamList paramList();

     protected:

      virtual void paramChanged(IParam *naYiGe);

     private:

      IntRangeParam *zuiDuo_;


};

#endif /* end of include guard */
