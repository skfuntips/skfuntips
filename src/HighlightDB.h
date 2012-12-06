#ifndef GAO_LIANG_CI_KU_H
#define GAO_LIANG_CI_KU_H


#include "CompositeResource.h"

class HighlightDB:public CompositeResource{
    Q_OBJECT

public:

    static HighlightDB& instance(){
        static HighlightDB shiLi_;
        return shiLi_;
    }


    const QList<QRegExp>& regexpList()const{
        return regexpList_[type()];
    }

protected slots:

    virtual void externalFileChanged();


private:

    HighlightDB();

    QList<QRegExp> regexpList_[3];

    void processFile(Type type);
};


#endif//GAO_LIANG_CI_KU_H
