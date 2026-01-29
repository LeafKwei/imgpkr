#ifndef TASKTHREAD_H
#define TASKTHREAD_H

#include <QThread>
#include "taskqueue.h"
#include "waiter.h"

class TaskThread : public QThread
{
    Q_OBJECT
public:
    explicit TaskThread(QObject *parent, TaskQueue *tskque, Waiter *cond_hastask);
    
protected:
    void run() override;
    
private:
    TaskQueue *m_tskque;
    Waiter *m_cond_hastask;

/////////////////////////////////////////////////////////////////////////

signals:
    void threadTaskDone(int id);
};

#endif // TASKTHREAD_H
