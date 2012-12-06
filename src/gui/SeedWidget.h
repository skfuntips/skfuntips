#ifndef ZHONG_ZI_KONG_JIAN_H

#define ZHONG_ZI_KONG_JIAN_H

#include "ParamWidget.h"
#include <boost/scoped_ptr.hpp>


class SeedParam;

namespace Ui {
class SeedWidget;

}

class SeedWidget :public ParamWidget{
    Q_OBJECT
public:
        typedef SeedParam ParamType;
    SeedWidget (QWidget* parent=0);

    virtual ~SeedWidget ();

protected:

   virtual void applyParam(IParam *canShu);

private:

   void setString(const QString& wenBen);

private slots:

   void applyUi();

    void on_pushButton_jiaZaiWenJian_clicked();
    void on_pushButton_jianQieBan_clicked();

private:
    boost::scoped_ptr<Ui::SeedWidget> ui_;
};


#endif /* end of include guard: ZHONG_ZI_KONG_JIAN_H */
