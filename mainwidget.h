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
    Ui::MainWidget *ui;
    
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
};

#endif // MAINWIDGET_H
