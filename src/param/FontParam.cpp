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

QString FontParam::jieShou(const QString& ziFuChuan){

    QFont xin;

    bool Result=xin.fromString(ziFuChuan);

    if(!Result){
        return tr("unable to load front from desc");
    }

    sheZhiZiTi(xin);
   

/*
    QFontDatabase ziTiKu;

    QList<QFontDatabase::WritingSystem> zhiChiYuYan=ziTiKu.writingSystems(ziTi_.family());

    if (zhiChiYuYan.indexOf(QFontDatabase::SimplifiedChinese)==-1) {
	 ziTi_=yuanLai;
	 return " 此字体不支持中文显示";
    }
    */

    return QString();

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


