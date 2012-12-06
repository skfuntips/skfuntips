
#ifndef XIE_YIN_CHU_LI_H

#define XIE_YIN_CHU_LI_H

#include "LevelProcessor.h"

class IntRangeParam;

class SimilarProcessor :public LevelProcessor{
    Q_OBJECT

    public:

    SimilarProcessor();

    virtual QString name()const;
    
    virtual Result process(const QStringList& );

    virtual QString description()const;

    virtual ~SimilarProcessor(){}


    virtual ResultType resultLeiXing()const{
        return STRING;
    }

};


#endif /* end of include guard: XIE_YIN_CHU_LI_H */
