
#ifndef PI_PEI_QI_H

#define PI_PEI_QI_H

#include <QRegExp>

#include "CompositeResource.h"

class KeywordsDB :public CompositeResource{
    Q_OBJECT
public:

    static KeywordsDB& instance(){
        static KeywordsDB shiLi_;
        return shiLi_;
    }

    const QRegExp& regexp(){return regexp_[type()];}

protected slots:

    virtual void externalFileChanged();

private:

    KeywordsDB();

    QRegExp regexp_[3];

    QString pattern_[3];

};

#endif /* end of include guard: PI_PEI_QI_H */
