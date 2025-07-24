#include "packedwidget.h"
#include "ui_packedwidget.h"

PackedWidget::PackedWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PackedWidget)
{
    ui->setupUi(this);
}

PackedWidget::~PackedWidget()
{
    delete ui;
}
