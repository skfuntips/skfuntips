#ifndef HANG_CHU_LI_H

#define HANG_CHU_LI_H

#include <boost/function.hpp>

class QString;
class QStringList;
class QTextEdit;
class QPlainTextEdit;
class QTextDocument;

typedef boost::function<bool(const QString&)> ChuLiHanShu;

class QFile;

void hangChuLi(QFile& wenJian,ChuLiHanShu chuLiHanShu);

void hangChuLi(const QString& ziFuChuan,ChuLiHanShu chuLiHanShu);

void hangChuLi(const QStringList& ziFuChuan,ChuLiHanShu chuLiHanShu);

QString heBingDuoHang(const QStringList& duoHang,bool addLineBreak=true,int qiShi=-1,int jieShu=-1);

QString quChuHuanHang(const QString& duoHang);

QStringList hangDuanKai(const QString& ziFuChuan,int hangKuanDu);

QStringList kongJianWenBen(QTextDocument* wenDang);

void tianChong(QTextDocument *buJu,const QStringList& neiRong);

#endif /* end of include guard: HANG_CHU_LI_H */
