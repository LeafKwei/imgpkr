#include <QDir>
#include <QFileDialog>
#include "task/taskpack.h"
#include "3rdimpl/qtpngreader.h"
#include "3rdinclude/packer/impl/Packer.hpp"

using packer::Packer;

TaskPack::TaskPack(int id, const QString &inpath, const QString &outpath)
    : Task(id)
    , m_inpath(inpath)
    , m_outpath(outpath)
{
    
}

int TaskPack::executeTask(){
    Packer packer;
    QVector<QString> names;
    
    getAllPictureNameFrom(names, m_inpath);
    for(auto &name : names){
        //todo 生成Reader对象
    }
    
    return 0;
}

int TaskPack::getAllPictureNameFrom(QVector<QString> &names, QString path){
    QDir dir(path);
    
    if(!dir.exists()){
        qDebug() << "Don't exists: " << path;
        return 0;
    }
    
    const QStringList &files = dir.entryList(QStringList("*.png"));
    for(auto &f : files){
        names.push_back(f);
    }
    
    return names.size();
}