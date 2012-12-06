#ifndef CI_KU_KONG_JIAN_H
#define CI_KU_KONG_JIAN_H

#include <QDialog>

#include <boost/shared_ptr.hpp>

namespace Ui{
class CompositeResourceWidget;

}

class CompositeResource;

class CompositeResourceWidget:public QDialog{

    Q_OBJECT

public :

    CompositeResourceWidget(CompositeResource * zuHe,QWidget* parent=0);

    void setDescription(const QString& shuoMing);

    virtual ~CompositeResourceWidget();

protected:

    void showEvent(QShowEvent* e);

private slots:

   void saveFile();

   void on_groupBox_toggled(bool xuanZhong);

   void togglePart();

private:

    boost::shared_ptr<Ui::CompositeResourceWidget> ui_;

    CompositeResource * ziYuan_;

    void zaiRuWenJian();

};

#endif
