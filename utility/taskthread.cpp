#include <QtDebug>
#include "taskthread.h"

TaskThread::TaskThread(QObject *parent, TaskQueue *tskque, Waiter *cond_hastask)
    : QThread{parent}
    , m_tskque(tskque)
    , m_cond_hastask(cond_hastask) 
{}

void TaskThread::run(){
    while(1){
        qDebug() << "Running...";
        m_cond_hastask -> wait();
        qDebug() << "Running2...";
    }
}