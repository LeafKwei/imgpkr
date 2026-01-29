#include "taskthread.h"
#include "taskthreadpool.h"

TaskThreadPool::TaskThreadPool(QObject *parent, int trdcnt)
    : QObject{parent}
{
    initThreads(trdcnt);
}

void TaskThreadPool::pushTask(Task *task){
    m_waiter.notifyOne();
}

void TaskThreadPool::initThreads(int trdcnt){
    for(int i = 0; i < trdcnt; i++){
        m_threads.push_back(new TaskThread(this, &m_taskqueue, &m_waiter));
    }
    
    auto size = m_threads.size();
    for(decltype(size) i = 0; i < size; i++){
        m_threads.at(i) -> start();
    }
}

void TaskThreadPool::atThreadTaskDone(int id){

}
