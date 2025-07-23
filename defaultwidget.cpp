#include "defaultwidget.h"
#include "ui_defaultwidget.h"

DefaultWidget::DefaultWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DefaultWidget)
{
    ui->setupUi(this);
}

DefaultWidget::~DefaultWidget()
{
    delete ui;
}
