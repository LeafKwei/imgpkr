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
    void doActionPack();
    void doActionUnpack();
    void doActionSave();
    
signals:
    void projectItemChange(int);
    
private slots:
    void atMenuNewTriggered(QAction *act);
};

#endif // MAINWIDGET_H
