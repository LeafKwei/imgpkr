#ifndef PACKEDWIDGET_H
#define PACKEDWIDGET_H

#include <QWidget>

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
    Ui::PackedWidget *ui;
};

#endif // PACKEDWIDGET_H
