#ifndef DEFAULTWIDGET_H
#define DEFAULTWIDGET_H

#include <QWidget>

namespace Ui {
class DefaultWidget;
}

class DefaultWidget : public QWidget
{
    Q_OBJECT

public:
    Ui::DefaultWidget *ui;
    
    explicit DefaultWidget(QWidget *parent = nullptr);
    ~DefaultWidget();

private:
};

#endif // DEFAULTWIDGET_H
