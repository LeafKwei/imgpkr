#include <QFileDialog>
#include "packedwidget.h"
#include "ui_packedwidget.h"

PackedWidget::PackedWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PackedWidget)
{
    ui->setupUi(this);
    initialize();
}

PackedWidget::~PackedWidget()
{
    delete ui;
}

void PackedWidget::initialize(){
    initConnection();
}

void PackedWidget::initConnection(){
    connect(ui -> btnInput, SIGNAL(clicked(bool)), this, SLOT(atBtnInputClicked(bool)));
    connect(ui -> btnOutput, SIGNAL(clicked(bool)), this, SLOT(atBtnOutputClicked(bool)));
    connect(ui -> btnPack, SIGNAL(clicked(bool)), this, SLOT(atBtnPackClicked(bool)));
}

void PackedWidget::atBtnInputClicked(bool b){
    QString path = QFileDialog::getExistingDirectory(
        this, tr("Open directory"), "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        
    if(path.isEmpty()) return;
    ui -> editInput -> setText(path);
}

void PackedWidget::atBtnOutputClicked(bool b){
    QString path = QFileDialog::getExistingDirectory(
        this, tr("Open directory"), "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        
    if(path.isEmpty()) return;
    ui -> editOutput -> setText(path);
}

void PackedWidget::atBtnPackClicked(bool b){

}
