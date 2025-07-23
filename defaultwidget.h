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
    explicit DefaultWidget(QWidget *parent = nullptr);
    ~DefaultWidget();

private:
    Ui::DefaultWidget *ui;
};

#endif // DEFAULTWIDGET_H
