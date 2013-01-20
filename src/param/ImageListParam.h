#ifndef IMAGE_LIST_PARAM

#include "IParam.h"

#include "FrameSegment.h"

typedef QList<FrameSegment> Segments;

class ImageListParam :public IParam{
    Q_OBJECT

    public:

    ImageListParam(QObject * suoYouZhe=0);

    void append(const FrameSegment& segment){
        segments_.append(segment);
        emit valueChanged(this);
    }

    void append(const Segments& segments){

        segments_.append(segments);

        emit valueChanged(this);
    }

    public slots:

    void clear(){
        segments_.clear();
        emit valueChanged(this);
    }

    void setImages(const Segments& segments){
        segments_=segments;
        emit valueChanged(this);
    }

    const QList<FrameSegment>& segments()const{return segments_;}

    private:

    Segments segments_;


};

#endif//IMAGE_LIST_PARAM
