#ifndef CHU_LI_KONG_JIAN_H
#define CHU_LI_KONG_JIAN_H


#include <boost/scoped_ptr.hpp>
#include <QGroupBox>

#include "ProcessorContainer.h"
#include "def.h"

namespace Ui {
class ProcessWidget;

}

class ProcessWidget:public QGroupBox {
    Q_OBJECT

public:

    ProcessWidget(QWidget *parent=NULL);

    virtual ~ProcessWidget();

    IProcessor* dangQian();

    ProcessorContainer processorContainer(){
        return chuLiRongQi_;
    }

    bool realtimePreview()const;

signals:

    void processorChanged(ParamList canShuLieBiao);

    void yingGaiChuLi();

public slots:

    void on_comboBox_currentIndexChanged(int suoYin);

    void yuanGaiBian();

private slots:

    void canShuGaiBian();

private:

    boost::scoped_ptr<Ui::ProcessWidget> ui_;

    ProcessorContainer chuLiRongQi_;

    void kongZhiAnNiu();

};

#endif//CHU_LI_KONG_JIAN_H
