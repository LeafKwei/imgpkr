#ifndef UTILITY_H
#define UTILITY_H

#include <QRandomGenerator>
#include <QTime>

inline int makeRandomID(int limit){
    static QRandomGenerator randgen(QTime::currentTime().msec());
    return randgen.bounded(limit);
}

#endif // UTILITY_H
