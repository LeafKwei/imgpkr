#ifndef TASKTHREADPOOL_H
#define TASKTHREADPOOL_H

#include <QObject>
#include <QVector>
#include <QMutex>
#include <QWaitCondition>
#include "taskqueue.h"
#include "waiter.h"

class TaskThread;

class TaskThreadPool : public QObject
{
    Q_OBJECT
public:
    explicit TaskThreadPool(QObject *parent, int trdcnt);
    void pushTask(Task *task);
    
private:
    Waiter    m_cond_hastask;
    TaskQueue m_taskqueue;
    QVector<TaskThread*> m_threads;
    
    void initThreads(int trdcnt);

/////////////////////////////////////////////////////////////////////////

private slots:
    void atThreadTaskDone(int id);

signals:
    void taskDone(int id);
};

#endif // TASKTHREADPOOL_H
