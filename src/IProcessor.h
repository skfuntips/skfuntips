#ifndef CHU_LI_JIE_KOU_H
#define CHU_LI_JIE_KOU_H

#include "def.h"
#include "ResultType.h"

#include <boost/shared_ptr.hpp>

#include <QObject>

class QStringList;

class SeedParam;

class Result;


class IProcessor :public QObject{

        Q_OBJECT

    public:

        virtual QString name()const=0;

        virtual QString description()const {return name();}

        virtual Result process(const QStringList& shuRu)=0;

        virtual ParamList paramList()=0;

        virtual ResultType resultLeiXing()const=0;

        virtual ~IProcessor(){}

    signals:

        void paramDirty();

        void processPercent(int processPercent);

    protected slots:

        virtual void paramChanged(IParam*){}

};


#endif /* end of include guard */
