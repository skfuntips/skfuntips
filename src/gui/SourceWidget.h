#ifndef SHU_RU_KONG_JIAN_H

#define SHU_RU_KONG_JIAN_H

#include <boost/scoped_ptr.hpp>
#include <QGroupBox>

namespace Ui{

class SourceWidget;

}

class SourceWidget :public QGroupBox{
    Q_OBJECT
public:
	SourceWidget (QWidget *parent=0);

    virtual ~SourceWidget ();

    QStringList neiRong();

    void sheZhiWenBen(const QString& wenBen);

signals:

    void neiRongBianHua();

protected:

    virtual void resizeEvent(QResizeEvent* );

private slots:

     void on_pushButton_jiaZaiWenJian_clicked();
     
     void on_pushButton_jianQieBan_clicked();

     void qieHuanHuanHang(bool kongZhi=true);

private:

     boost::scoped_ptr<Ui::SourceWidget> ui_;

     int zhongWenHangZiShu_;


};


#endif /* end of include guard: SHU_RU_KONG_JIAN_H */
