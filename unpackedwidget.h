#ifndef UNPACKEDWIDGET_H
#define UNPACKEDWIDGET_H

#include <QWidget>

namespace Ui {
class UnpackedWidget;
}

class UnpackedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UnpackedWidget(QWidget *parent = nullptr);
    ~UnpackedWidget();

private:
    Ui::UnpackedWidget *ui;
};

#endif // UNPACKEDWIDGET_H
