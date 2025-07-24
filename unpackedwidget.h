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
    Ui::UnpackedWidget *ui;
    
    explicit UnpackedWidget(QWidget *parent = nullptr);
    ~UnpackedWidget();

private:
};

#endif // UNPACKEDWIDGET_H
