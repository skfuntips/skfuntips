#ifndef ZHENG_SHU_FAN_WEI_KONG_JIAN_H

#define ZHENG_SHU_FAN_WEI_KONG_JIAN_H


#include <boost/scoped_ptr.hpp>

#include "ParamWidget.h"

class IntRangeParam;

namespace Ui{
class IntRangeWidget;
}

class IntRangeWidget :public ParamWidget{
        Q_OBJECT
    public:

        typedef IntRangeParam ParamType;

        IntRangeWidget (QWidget* parent=0);
        virtual ~IntRangeWidget ();

    protected:

        virtual void applyParam(IParam* canShu);


    private slots:

        void applyUi();

private:

        boost::scoped_ptr<Ui::IntRangeWidget> ui_;
};


#endif /* end of include guard: ZHENG_SHU_FAN_WEI_KONG_JIAN_H */
