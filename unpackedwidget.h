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
    
    void initialize();
    void initConnection();
    
/////////////////////////////////////////////////////////////////////////

private slots:
    void atBtnInputClicked(bool b);
    void atBtnOutputClicked(bool b);
    void atBtnUnpackClicked(bool b);
};

#endif // UNPACKEDWIDGET_H
