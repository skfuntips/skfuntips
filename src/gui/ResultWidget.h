#ifndef JIE_GUO_KONG_JIAN_H

#define JIE_GUO_KONG_JIAN_H


#include <boost/scoped_ptr.hpp>
#include <QGroupBox>
#include "Result.h"

class Gif;

namespace Ui {
class ResultWidget;
}

class ResultWidget:public  QGroupBox {

     Q_OBJECT
     public:
	  ResultWidget(QWidget* parent=0);

      void setResult(const Result& ResultSheZhi);

      QString contents();

      virtual ~ResultWidget();

     private slots:

      void on_pushButton_saveToFile_clicked();
          void on_pushButton_saveToClipboard_clicked();

     private:

          boost::scoped_ptr<Ui::ResultWidget> ui_;

	  Result Result_;

      boost::scoped_ptr<Gif> dongHua_;

};


#endif /* end of include guard: JIE_GUO_KONG_JIAN_H */
