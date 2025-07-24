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
    Ui::PackedWidget *ui;
    
    explicit PackedWidget(QWidget *parent = nullptr);
    ~PackedWidget();

private:

};

#endif // PACKEDWIDGET_H
