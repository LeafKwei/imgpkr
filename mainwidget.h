#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

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
    
    void initialize();
    void initConnection();
    void deleteItem(int index);
    void deleteProject(int index);
    void doActionPack();
    void doActionUnpack();
    void doActionSave();
    void doActionDelete();
    
signals:
    void projectItemChange(int);
    
private slots:
    void atMenuNewTriggered(QAction *act);
    void atMenuEditTriggered(QAction *act);
};

#endif // MAINWIDGET_H
