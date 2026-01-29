#ifndef TASKPACK_H
#define TASKPACK_H

#include <QVector>
#include "utility/task.h"

class TaskPack : public Task
{
public:
    TaskPack(int id);
    int executeTask() override;
    
private:
    int getAllPictureNameFrom(QVector<QString> &names, QString path);
};

#endif // TASKPACK_H
