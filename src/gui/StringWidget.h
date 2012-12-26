#ifndef STRING_WIDGET_H

#define STRING_WIDGET_H

#include <boost/scoped_ptr.hpp>

#include "ParamWidget.h"

class StringParam;

namespace Ui{
class StringWidget;
}

class StringWidget :public ParamWidget{
     Q_OBJECT

     public :

     typedef StringParam ParamType;

        StringWidget(QWidget *parent=0);

    virtual ~StringWidget();

    protected:

    virtual void applyParam(IParam *canShu);

    private slots:

     void applyUi();

private:

     boost::scoped_ptr<Ui::StringWidget> ui_;

};


#endif /* end of include guard: STRING_WIDGET_H */

