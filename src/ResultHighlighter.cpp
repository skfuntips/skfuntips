#include "ResultHighlighter.h"
#include "KeywordsDB.h"
#include "HighlightDB.h"

ResultHighlighter::ResultHighlighter(QObject *fuDuiXiang)
    :QSyntaxHighlighter(fuDuiXiang){

    connect(&KeywordsDB::instance(),SIGNAL(chongZhi()),this,SLOT(rehighlight()));

    connect(&HighlightDB::instance(),SIGNAL(chongZhi()),this,SLOT(rehighlight()));

}

void ResultHighlighter::highlightBlock(const QString &text){

    QList<QRegExp> piPei=HighlightDB::instance().regexpList();
    piPei.push_back(KeywordsDB::instance().regexp());


        QTextCharFormat geShi;

        geShi.setForeground(Qt::darkMagenta);
        geShi.setUnderlineStyle(QTextCharFormat::WaveUnderline);
        geShi.setUnderlineColor(Qt::red);

        foreach(QRegExp expression,piPei){

            int index = text.indexOf(expression);

            while (index >= 0) {
                int length = expression.matchedLength();

                if(length==0){
                    break;
                }

                setFormat(index, length, geShi);
                index = text.indexOf(expression, index + length);
            }

        }

}
