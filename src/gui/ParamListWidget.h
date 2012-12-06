#ifndef CAN_SHU_LIE_BIAO_KONG_JIAN_H
#define CAN_SHU_LIE_BIAO_KONG_JIAN_H

#include "def.h"

#include <QGroupBox>

#include <boost/scoped_ptr.hpp>

class ParamWidget;

namespace Ui{
class ParamListWidget;
}

class ParamListWidget:public QGroupBox{
    Q_OBJECT

public:

    ParamListWidget(QWidget *parent=NULL);

    virtual ~ParamListWidget();

public slots:

    void canShuLieBiaoGaiBian(ParamList xinLieBiao);

private:

    boost::scoped_ptr<Ui::ParamListWidget> ui_;

    QList<ParamWidget*> ParamWidgetLieBiao_;


};


#endif//CAN_SHU_LIE_BIAO_KONG_JIAN_H
