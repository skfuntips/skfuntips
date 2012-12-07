#ifndef ZU_HE_ZI_YUAN_H
#define ZU_HE_ZI_YUAN_H

#include <QStringList>

class QFileSystemWatcher;
class QFile;

class CompositeResource:public QObject{

    Q_OBJECT

public:

    enum Type{INTERNAL,EXTERNAL,ALL};

    CompositeResource(const QString& moBan);

    virtual ~CompositeResource(){}

    const QStringList& type(Type leiXing)const{
        return contents_[leiXing];
    }



    void setType(Type leiXing){
        type_=leiXing;
        emit reset();
    }

    Type type()const{
        return type_;
    }

    const QString& internal()const{return internalFilename_;}

    const QString& external()const{return externalFilename_;}

signals:

    void reset();

protected slots:

    virtual void externalFileChanged();

private:

    QString internalFilename_;

    QString externalFilename_;

    QStringList contents_[3];

    QFileSystemWatcher *watcher_;

    Type type_;

    void processFile(QFile& file,Type type);
};

#endif//ZU_HE_ZI_YUAN_H
