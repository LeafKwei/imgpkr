#include <QtDebug>
#include "utility/taskthread.h"

TaskThread::TaskThread(QObject *parent, TaskQueue *tskque)
    : QThread{parent}
    , m_tskque(tskque)
{}

void TaskThread::run(){
    while(true){
        auto tp = m_tskque -> takeTask();
        auto okcode = tp -> executeTask();
    
        if(okcode){
            emit threadTaskDone(-(tp -> id()));
        }
        
        emit threadTaskDone(tp -> id());
    }
}