#ifndef TASKTHREADPOOL_H
#define TASKTHREADPOOL_H

#include <QObject>
#include <QVector>
#include <QMutex>
#include <QWaitCondition>
#include "utility/ONLYTEST.h"
#include "utility/taskqueue.h"

class TaskThread;

class TaskThreadPool : public QObject
{
    Q_OBJECT
public:
    explicit TaskThreadPool(QObject *parent, int trdcnt, TaskQueue *tskque);
    
private:
    TaskQueue *m_tskque;
    QVector<TaskThread*> m_threads;
    
    void initThreads(int trdcnt);

/////////////////////////////////////////////////////////////////////////

private slots:
    void atThreadTaskDone(int id);

signals:
    void taskDone(int id);
};

#endif // TASKTHREADPOOL_H
