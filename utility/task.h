#ifndef TASK_H
#define TASK_H

#include <QSharedPointer>
#include "utility/ONLYTEST.h"
#include "utility/utility.h"

constexpr int ID_BOUND = 100000;

class Task
{
public:
    explicit Task(int id);
    virtual ~Task() =default;
    virtual int executeTask() =0;  //返回任务执行是否成功。0=成功，其他值=失败
    int id();
    
private:
    int m_id;
};

inline Task::Task(int id) : m_id(id){}
inline int Task::id(){ return m_id; }
using TaskPtr = QSharedPointer<Task>;

#endif // TASK_H
