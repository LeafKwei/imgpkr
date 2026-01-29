#ifndef WAITER_H
#define WAITER_H

#include <QMutex>
#include <QWaitCondition>

class Waiter
{
public:
    explicit Waiter();
    bool wait();
    void notifyOne();
    
private:
    QMutex m_mutex;
    QWaitCondition m_wcond;
};

#endif // WAITER_H
