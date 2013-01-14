
#ifndef CAN_SHU_JIE_KOU_H
#define CAN_SHU_JIE_KOU_H

#include <QObject>
#include <QString>


class IParam :public QObject{

    Q_OBJECT

public:

    IParam(QObject* suoYouZhe=NULL){
	 if (suoYouZhe) {
          connect(this,SIGNAL(valueChanged(IParam*)),
                suoYouZhe,SLOT(paramChanged(IParam*)));
          connect(this,SIGNAL(valueChanged(IParam*)),
                  suoYouZhe,SIGNAL(paramDirty()));
	 }
    }

    virtual ~IParam (){}

    QString name()const{
        return name_;
    }

    QString description()const{
        return description_;
    }


    void setDescription(const QString& shuoMing){
        description_=shuoMing;
    }

    void setName(const QString& mingZi){
        name_=mingZi;
    }

signals:

    void valueChanged(IParam* naYiGe);

private:

    IParam(const IParam&){}
    IParam& operator=(const IParam&);

    QString name_;
    QString description_;
};

#endif /* end of include guard */
