#include <QMutexLocker>
#include "utility/taskqueue.h"

TaskQueue::TaskQueue()
{}

void TaskQueue::addTask(TaskPtr tp){
    QMutexLocker locker(&m_mutex);
    m_tasks.push_back(tp);
    m_cond_hastask.notify_one();
}

TaskPtr TaskQueue::takeTask(){
    QMutexLocker locker(&m_mutex);
    while(m_tasks.empty()){
        m_cond_hastask.wait(&m_mutex);
    }
    
    auto tp = m_tasks.first();
    m_tasks.pop_front();
    return tp;
}