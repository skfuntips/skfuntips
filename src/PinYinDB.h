
#ifndef PIN_YIN_KU_H

#define PIN_YIN_KU_H

#include <QChar>


class PinYinDB {
public:

    static PinYinDB shiLi(){
        static PinYinDB shiLi_;
        return shiLi_;
    }

    QChar tongYinZiChangYong(QChar chaZhao);

    QChar tongYinZiSuoYou(QChar chaZhao);

    QString pinYin(QChar chaZhao);

    void xieChuChangJian();

    bool shiChangYong(QChar jianCha);

    bool meiYouTongYin(QChar jianCha);

private:

    PinYinDB();

};

#endif /* end of include guard: PIN_YIN_KU_H */
