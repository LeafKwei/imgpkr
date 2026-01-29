#ifndef PACKEDWIDGET_H
#define PACKEDWIDGET_H

#include <QWidget>
#include <QProgressDialog>

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
    bool m_contpack;
    Ui::PackedWidget *ui;
    QProgressDialog *m_dlgProgbar;
    
    void initialize();
    void initComponent();
    void initConnection();
    bool checkPrecondition();

/////////////////////////////////////////////////////////////////////////

signals:
    void startPack(int cnt);
    void increProgbar(int inc);
    void donePack();

private slots:
    void atBtnInputClicked(bool b);
    void atBtnOutputClicked(bool b);
    void atBtnPackClicked(bool b);
    void atPackCanceled();
};

#endif // PACKEDWIDGET_H
