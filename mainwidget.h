#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "packedwidget.h"
#include "unpackedwidget.h"
#include "utility/taskthreadpool.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    
private:
    Ui::MainWidget *ui;
    TaskQueue      m_tskque;
    TaskThreadPool m_threadpool;
    
    void initialize();
    void initConnection();
    void connectPackedWidget(PackedWidget *widget);
    void connectUnpackedWidget(UnpackedWidget *widget);
    void deleteItem(int index);
    void deleteProject(int index);
    void doActionPack();
    void doActionUnpack();
    void doActionSave();
    void doActionDelete();
    
/////////////////////////////////////////////////////////////////////////

private slots:
    void atMenuNewTriggered(QAction *act);
    void atMenuEditTriggered(QAction *act);
    void atTaskDone(int id);
    void atTaskRecv(TaskPtr tp);
    
signals:
    void projectItemChange(int);
    void taskDoneFromMain(int id);
};

#endif // MAINWIDGET_H
