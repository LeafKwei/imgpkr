#include "taskthread.h"
#include "taskthreadpool.h"

TaskThreadPool::TaskThreadPool(QObject *parent, int trdcnt, TaskQueue *tskque)
    : QObject{parent}
    , m_tskque(tskque)
{
    initThreads(trdcnt);
}

void TaskThreadPool::initThreads(int trdcnt){
    for(int i = 0; i < trdcnt; i++){
        auto thread = new TaskThread(this, m_tskque);
        connect(thread, SIGNAL(threadTaskDone(int)), this, SLOT(atThreadTaskDone(int)));
        m_threads.push_back(thread);
    }
    
    auto size = m_threads.size();
    for(decltype(size) i = 0; i < size; i++){
        m_threads.at(i) -> start();
    }
}

void TaskThreadPool::atThreadTaskDone(int id){
    emit taskDone(id);
}
