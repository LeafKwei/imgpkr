#include "mainwindow.h"

#include <QApplication>
#include <QFile>

QString loadStyleSheet(){
    QFile file(":/resource/qss/global/global.qss");
    
    if(file.open(QFile::ReadOnly)){
        QByteArray bytes = file.readAll();
        QString styleSheet(bytes);
        return styleSheet;
    }
    
    return QString("");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(loadStyleSheet());
    MainWindow w;
    w.show();
    return a.exec();
}
