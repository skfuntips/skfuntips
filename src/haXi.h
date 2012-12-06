
#ifndef HA_XI_H
#define HA_XI_H

#include <boost/functional/hash.hpp>

#include <QString>

std::size_t hash_value(QChar const& sl){
    return boost::hash<ushort>()(sl.unicode());
}


std::size_t hash_value(QString const& sl){
    return boost::hash_range(sl.constBegin(),sl.constEnd());
}


#endif
