#ifndef PACKEDWIDGET_H
#define PACKEDWIDGET_H

#include <QWidget>
#include <QProgressDialog>
#include "utility/task.h"

namespace Ui {
class PackedWidget;
}

class PackedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PackedWidget(QWidget *parent = nullptr);
    ~PackedWidget();

private:
    int m_taskid;
    Ui::PackedWidget *ui;
    QProgressDialog *m_dlgProgbar;
    
    void initialize();
    void initComponent();
    void initConnection();
    bool checkPrecondition();
    TaskPtr makeTask();
    void enablePackFunc();
    void disablePackFunc();
    
/////////////////////////////////////////////////////////////////////////

signals:
    void sendPackTask(TaskPtr tp);

private slots:
    void atBtnInputClicked(bool b);
    void atBtnOutputClicked(bool b);
    void atBtnPackClicked(bool b);
    void atPackTaskDone(int id);
};

#endif // PACKEDWIDGET_H
