#ifndef TASKTHREAD_H
#define TASKTHREAD_H

#include <QThread>
#include "ONLYTEST.h"
#include "taskqueue.h"

class TaskThread : public QThread
{
    Q_OBJECT
public:
    explicit TaskThread(QObject *parent, TaskQueue *tskque);
    
protected:
    void run() override;
    
private:
    TaskQueue *m_tskque;

/////////////////////////////////////////////////////////////////////////

signals:
    void threadTaskDone(int id); //当返回负数的id时，代表任务失败
};

#endif // TASKTHREAD_H
