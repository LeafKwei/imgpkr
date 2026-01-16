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
    void initialize();
    void initConnection();
    bool checkPrecondition();
    int  getAllPictureNameFrom(QVector<QString> &names, QString path);
    
private slots:
    void atBtnInputClicked(bool b);
    void atBtnOutputClicked(bool b);
    void atBtnPackClicked(bool b);
};

#endif // PACKEDWIDGET_H
