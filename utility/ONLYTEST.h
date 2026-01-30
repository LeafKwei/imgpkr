#ifndef ONLYTEST_H
#define ONLYTEST_H

#include <QThread>
#include <QtDebug>

#if 1
#define SHOWTEXT(str) (qDebug() << str)
#endif

#endif
