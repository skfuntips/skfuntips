
#ifndef WAI_BAO_CHU_LI_H

#define WAI_BAO_CHU_LI_H

#include "LevelProcessor.h"


class Processor;

class KeywordsProcessor :public LevelProcessor{

        Q_OBJECT

    public:

    KeywordsProcessor();

        virtual ~KeywordsProcessor (){}

        virtual QString name()const;

        virtual Result process(const QStringList& ziFuChuan);

    virtual QString description()const;


    virtual ParamList paramList(){
        return canShuLieBiao_;
    }


    virtual ResultType resultType()const{
        return STRING;
    }

    private:

    QList<IProcessor*> shiJi_;

    IProcessor* baoZhang_;

    ParamList canShuLieBiao_;

    template <class T>
    void chaRu(bool canShu=true);


};

#endif /* end of include guard: WAI_BAO_CHU_LI_H */
