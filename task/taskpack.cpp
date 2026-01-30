#include <QDir>
#include <QFileDialog>
#include "taskpack.h"

TaskPack::TaskPack(int id, const QString &inpath, const QString &outpath)
    : Task(id)
    , m_inpath(inpath)
    , m_outpath(outpath)
{
    
}

int TaskPack::executeTask(){
    //todo 实现图片打包功能
    QThread::sleep(5);
    return 0;
}

int TaskPack::getAllPictureNameFrom(QVector<QString> &names, QString path){
    QDir dir(path);
    
    if(!dir.exists()){
        return 0;
    }
    
    const QStringList &files = dir.entryList(QStringList("*.png"));
    for(auto &f : files){
        names.push_back(f);
    }
    
    return names.size();
}