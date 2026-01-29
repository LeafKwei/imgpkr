#include "mainwidget.h"
#include "packedwidget.h"
#include "unpackedwidget.h"
#include "ui_mainwidget.h"

/**
 * MainWiget用于提供主要的功能框架，包括项目条目、打包、解包界面。当用户新建项目时，MainWidget才会显示，
 * 在没有任何项目存在的情况下，mainwindow将默认显示DefaultWidet
 */
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
    , m_threadpool(this, 9)
{
    ui->setupUi(this);
    initialize();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::initialize(){
    m_threadpool.pushTask(nullptr);
    initConnection();
}

void MainWidget::initConnection(){
    connect(ui -> wgtProjectItem, SIGNAL(currentRowChanged(int)), ui -> wgtProject, SLOT(setCurrentIndex(int)));
}

void MainWidget::deleteItem(int index){
    /* QListWidget的removeItemWidget函数只会移除item，但不会delete相关对象，因此需要先takeItem后手动删除 */
    auto item = ui -> wgtProjectItem -> takeItem(index);
    ui -> wgtProjectItem -> removeItemWidget(item);
    delete item;
}

void MainWidget::deleteProject(int index){
    /* 同样的，QStackWidget的removeWidget函数也不会删除对象，需要获取到对象并手动删除 */
    auto project = ui -> wgtProject -> widget(index);
    ui -> wgtProject -> removeWidget(project);
    delete project;
}

void MainWidget::doActionPack(){
    /**
     * 创建打包窗口，需要在左侧QListWidget列表窗口创建项目条目，并同时在右侧的QStackWidget中创建窗口对象
     * 随后发送信号给mainwindow以更新主窗口视图
     */
    ui -> wgtProjectItem -> addItem("新建打包项目");
    ui -> wgtProject -> addWidget(new PackedWidget());
    emit projectItemChange(ui -> wgtProjectItem -> count());
}

void MainWidget::doActionUnpack(){
    /**
     * 创建解包窗口，需要在左侧QListWidget列表窗口创建项目条目，并同时在右侧的QStackWidget中创建窗口对象
     * 随后发送信号给mainwindow以更新主窗口视图
     */
    ui -> wgtProjectItem -> addItem("新建解包项目");
    ui -> wgtProject -> addWidget(new UnpackedWidget());
    emit projectItemChange(ui -> wgtProjectItem -> count());
}

void MainWidget::doActionSave(){
    
}

void MainWidget::doActionDelete(){
    /**
     * 点击菜单中的删除按钮时，删除选中位置的打包\解包项目
     * 首先获取到该位置的索引号，然后从QListWidget和QStackWidget中删除索引对应的条目和视图对象，删除完毕后，
     * 发送信号到mainwindow，以更新删除后的主窗口视图
     */
    auto index = ui -> wgtProjectItem -> currentIndex().row();
    if(index == -1) return; //if no item is selected yet.
    deleteItem(index);      //these two functions must use the same index which should be got before performing deletion.
    deleteProject(index);
    emit projectItemChange(ui -> wgtProjectItem -> count());
}

///////////////////////////////////////////////////////////////////////// SLOT
void MainWidget::atMenuNewTriggered(QAction *act){
    if(act -> text() == "打包") doActionPack();
    if(act -> text() == "解包") doActionUnpack();
    if(act -> text() == "保存") doActionSave();
}

void MainWidget::atMenuEditTriggered(QAction *act){
    if(act -> text() == "删除") doActionDelete();
}






