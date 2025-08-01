#include <QFileDialog>
#include "unpackedwidget.h"
#include "ui_unpackedwidget.h"

UnpackedWidget::UnpackedWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UnpackedWidget)
{
    ui->setupUi(this);
    initialize();
}

UnpackedWidget::~UnpackedWidget()
{
    delete ui;
}

void UnpackedWidget::initialize(){
    initConnection();
}

void UnpackedWidget::initConnection(){
    connect(ui -> btnInput, SIGNAL(clicked(bool)), this, SLOT(atBtnInputClicked(bool)));
    connect(ui -> btnOutput, SIGNAL(clicked(bool)), this, SLOT(atBtnOutputClicked(bool)));
    connect(ui -> btnUnpack, SIGNAL(clicked(bool)), this, SLOT(atBtnUnpackClicked(bool)));
}

void UnpackedWidget::atBtnInputClicked(bool b){
    QString path = QFileDialog::getExistingDirectory(
        this, tr("Open directory"), "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        
    if(path.isEmpty()) return;
    ui -> editInput -> setText(path);
}

void UnpackedWidget::atBtnOutputClicked(bool b){
    QString path = QFileDialog::getExistingDirectory(
        this, tr("Open directory"), "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        
    if(path.isEmpty()) return;
    ui -> editOutput -> setText(path);
}

void UnpackedWidget::atBtnUnpackClicked(bool b){

}