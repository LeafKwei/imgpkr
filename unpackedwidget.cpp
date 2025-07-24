#include "unpackedwidget.h"
#include "ui_unpackedwidget.h"

UnpackedWidget::UnpackedWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UnpackedWidget)
{
    ui->setupUi(this);
}

UnpackedWidget::~UnpackedWidget()
{
    delete ui;
}
