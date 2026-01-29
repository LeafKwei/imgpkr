#include <QDir>
#include <QFileDialog>
#include "taskpack.h"

TaskPack::TaskPack(int id) : Task(id){}

int TaskPack::executeTask(){
    //todo 实现图片打包功能
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