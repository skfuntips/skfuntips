
#ifndef CAN_SHU_KONG_JIAN_H

#define CAN_SHU_KONG_JIAN_H

#include <QGroupBox>

class IParam ;

class ParamWidget:public QGroupBox{
    Q_OBJECT

    public:

        typedef void IParamLeiXing;

        ParamWidget(QWidget* parent=0);

        virtual ~ParamWidget(){}

        void bindParam(IParam* canShu);

        void setSignalSource(bool shi){
            xinHaoYuan_=shi;
        }

    protected:

	template<class T>
    T* param(){
	     return xinHaoYuan_?qobject_cast<T*>(bangDingCanShu_):
             NULL;
	}

    virtual void applyParam(IParam* canShu)=0;

    private:

        IParam *bangDingCanShu_;

        void connectSignal();

        bool xinHaoYuan_;

    private slots:

        void paramChanged(IParam* gaiBian);

        void disconnectSignal();

};


#endif /* end of include guard: CAN_SHU_KONG_JIAN_H */
