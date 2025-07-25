#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "defaultwidget.h"
#include "mainwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class WindowState{Default, Main};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    WindowState m_winstate;
    Ui::MainWindow *ui;
    DefaultWidget *m_wgtDefault;
    MainWidget *m_wgtMain;
    
    void initialize();
    void createCoreWidget();
    void changeCoreWidget(WindowState state);
    void initConnection();
    void exitMainWindow();
    
private slots:
    void atMenuNewTriggered(QAction *act);
    void atProjectItemChange(int count);
};
#endif // MAINWINDOW_H
