#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
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
    
signals:
    void projectItemChange(int);
};

#endif // MAINWIDGET_H
