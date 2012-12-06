#ifndef GAO_LIANG_QI_H
#define GAO_LIANG_QI_H

#include <QSyntaxHighlighter>


class ResultHighlighter:public QSyntaxHighlighter{
    Q_OBJECT

public:

    ResultHighlighter(QObject* fuDuiXiang=0);

protected:

    virtual void highlightBlock(const QString &text);

};

#endif//GAO_LIANG_QI_H
