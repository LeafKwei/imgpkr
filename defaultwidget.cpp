#include "defaultwidget.h"
#include "ui_defaultwidget.h"

/**
 * DefaultWidget用于提供一个默认界面，当没有任何项目时，显示DefaultWidget
 */
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
