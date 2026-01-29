#include "waiter.h"

Waiter::Waiter(){}

bool Waiter::wait(){
    QMutexLocker locker(&m_mutex);
    return m_wcond.wait(&m_mutex);
}

void Waiter::notifyOne(){
    m_wcond.notify_one();
}
