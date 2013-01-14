#include "FontParam.h"

#include <QApplication>
#include <QFontDatabase>
#include <QStringList>

FontParam::FontParam(QObject* suoYouZhe):
     IParam(suoYouZhe){

	  Q_ASSERT_X(QApplication::instance(),"FontParam::FontParam","没有构建QApplication");

	  QFontDatabase ziTiKu;

	  QStringList ziTiLieBiao=ziTiKu.families(QFontDatabase::SimplifiedChinese);

	  ziTi_=QFont(ziTiLieBiao.front());

      ziTi_.setPixelSize(15);

      setDescription(tr("select font"));

      setName(tr("select font"));
     }





void FontParam::sheZhiZiTi(const QFont &ziTiSheZhi){
    if (ziTiSheZhi!=ziTi_) {
 
        ziTi_=ziTiSheZhi;

        if (ziTi_.pixelSize()==-1) {
            ziTi_.setPixelSize(15);
        }

        emit valueChanged(this);
    }
}


