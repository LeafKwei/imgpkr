#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include <QVector>
#include <QMutex>
#include <QMutexLocker>

class Task;

class TaskQueue
{
public:
    explicit TaskQueue();

private:
    QMutex m_mutex;
    QVector<Task*> m_tasks;
};

#endif // TASKQUEUE_H
