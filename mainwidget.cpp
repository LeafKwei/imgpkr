#include "mainwidget.h"
#include "packedwidget.h"
#include "unpackedwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    initialize();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::initialize(){
    initConnection();
}

void MainWidget::initConnection(){
    connect(ui -> wgtProjectItem, SIGNAL(currentRowChanged(int)), ui -> wgtProject, SLOT(setCurrentIndex(int)));
}

void MainWidget::doActionPack(){
    ui -> wgtProjectItem -> addItem("新建打包项目");
    ui -> wgtProject -> addWidget(new PackedWidget());
    emit projectItemChange(ui -> wgtProjectItem -> count());
}

void MainWidget::doActionUnpack(){
    ui -> wgtProjectItem -> addItem("新建解包项目");
    ui -> wgtProject -> addWidget(new UnpackedWidget());
    emit projectItemChange(ui -> wgtProjectItem -> count());
}

void MainWidget::doActionSave(){
    
}

//============== Slots ===================
void MainWidget::atMenuNewTriggered(QAction *act){
    if(act -> text() == "打包") doActionPack();
    if(act -> text() == "解包") doActionUnpack();
    if(act -> text() == "保存") doActionSave();
}
