#ifndef TASKPACK_H
#define TASKPACK_H

#include <QVector>
#include "utility/task.h"

class TaskPack : public Task
{
public:
    TaskPack(int id, const QString &inpath, const QString &outpath);
    int executeTask() override;
    
private:
    QString m_inpath;
    QString m_outpath;
    QVector<QString> m_filenames;
    int getAllPictureNameFrom(QVector<QString> &names, QString path);
};

#endif // TASKPACK_H
