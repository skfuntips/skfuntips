
#ifndef JIE_GUO_H
#define JIE_GUO_H

#include <boost/shared_ptr.hpp>

#include <QStringList>
#include <QImage>

#include "ResultType.h"



class QFile;

class Result{

    public:

    Result(const QStringList& string=QStringList());

        Result(const QByteArray& gifBinary);

        Result(const QImage& tuPian){
            image_=tuPian;
            type_=IMAGE;
        }

        ResultType type()const{return type_;}

        void setString(const QStringList& ziFuChuan){
            string_=ziFuChuan;
            type_=STRING;
        }

        void setImage(const QImage& tuPian){
            image_=tuPian;
            type_=IMAGE;
        }

    bool saveFile(const QString& wenJianMing);

    bool saveClipboard();

        operator QStringList ()const{return string_;}

        operator QImage ()const{return image_;}

    operator QByteArray()const{return gifBinary_;}

        const QStringList& string()const{return string_;}

        const QByteArray& gifBinary()const{return gifBinary_;}

        const QImage& image()const{return image_;}

    private:

        ResultType type_;

        QStringList string_;
        QImage image_;

        QByteArray gifBinary_;

};

#endif
