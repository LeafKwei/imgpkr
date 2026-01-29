#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include <QList>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include "ONLYTEST.h"
#include "task.h"

class Task;

class TaskQueue
{
public:
    explicit TaskQueue();

    bool addTask(TaskPtr tp);
    TaskPtr takeTask();

private:
    QMutex m_mutex;
    QWaitCondition m_cond_hastask;
    QList<TaskPtr> m_tasks;
};

#endif // TASKQUEUE_H
