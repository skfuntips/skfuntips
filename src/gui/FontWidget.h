#ifndef ZI_TI_KONG_JIAN_H

#define ZI_TI_KONG_JIAN_H

#include <boost/scoped_ptr.hpp>

#include "ParamWidget.h"

class FontParam;

namespace Ui{
class FontWidget;
}

class FontWidget :public ParamWidget{
     Q_OBJECT

     public :

     typedef FontParam ParamType;

        FontWidget(QWidget *parent=0);

    virtual ~FontWidget();

    protected:

    virtual void applyParam(IParam *canShu);

    private slots:

     void applyUi();

private:

     boost::scoped_ptr<Ui::FontWidget> ui_;

};


#endif /* end of include guard: ZI_TI_KONG_JIAN_H */

