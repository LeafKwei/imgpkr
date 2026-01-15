#include "mainwindow.h"
#include "packedwidget.h"
#include "./ui_mainwindow.h"
#include "./ui_mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/resource/icon/icon.png"));
    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize(){
    createCoreWidget();                       //创建MainWidget和DefaultWidget对象
    changeCoreWidget(WindowState::Default);   //将mainwindow的主窗口视图设置为DefaultWidget
    initConnection();
}

void MainWindow::createCoreWidget(){
    m_wgtDefault = new DefaultWidget();
    m_wgtMain = new MainWidget();
}

/**
 * 根据给定的mianwindow窗口状态设置主窗口视图
 * 如果状态是Default，则将主窗口设置为DefaultWidget，并备份原主窗口对象
 * 如果状态是Main，则将主窗口设置为MainWiget，并备份原主窗口对象
 */
void MainWindow::changeCoreWidget(WindowState state){
    if(state == m_winstate) return;
    
    decltype(m_wgtMain) bakMain;
    decltype(m_wgtDefault) bakDefault;
    
    switch(state){
        default:
        case WindowState::Default:
            m_winstate = state;
            bakMain = dynamic_cast<MainWidget*>(takeCentralWidget());
            if(bakMain != nullptr) m_wgtMain = bakMain;  //在程序最初启动时，takeCentralWidget会获取到一个nullptr，此处需要排除该情况
            setCentralWidget(m_wgtDefault);
            break;
        case WindowState::Main:
            m_winstate = state;
            bakDefault = dynamic_cast<DefaultWidget*>(takeCentralWidget());
            if(bakDefault != nullptr) m_wgtDefault = bakDefault;
            setCentralWidget(m_wgtMain);
            break;
    }
}

void MainWindow::initConnection(){
    connect(ui -> menuNew, SIGNAL(triggered(QAction*)), m_wgtMain, SLOT(atMenuNewTriggered(QAction*)));
    connect(ui -> menuEdit, SIGNAL(triggered(QAction*)), m_wgtMain, SLOT(atMenuEditTriggered(QAction*)));
    connect(ui -> menuNew, SIGNAL(triggered(QAction*)), this, SLOT(atMenuNewTriggered(QAction*)));
    connect(ui -> menuEdit, SIGNAL(triggered(QAction*)), this, SLOT(atMenuEditTriggered(QAction*)));
    connect(ui -> menuHelp, SIGNAL(triggered(QAction*)), this, SLOT(atMenuHelpTriggered(QAction*)));
    connect(m_wgtMain, SIGNAL(projectItemChange(int)), this, SLOT(atProjectItemChange(int)));
}

void MainWindow::exitMainWindow(){
    QCoreApplication::exit(0);
}

void MainWindow::doActionUsage(){

}

void MainWindow::doActionVersion(){

}

//===================== Slots =====================
void MainWindow::atMenuNewTriggered(QAction *act){
    if(act -> text() == "退出") exitMainWindow();
}

void MainWindow::atMenuEditTriggered(QAction *act){
    
}

void MainWindow::atMenuHelpTriggered(QAction *act){
    if(act -> text() == "使用说明") doActionUsage();
    if(act -> text() == "版本信息") doActionVersion();
}

void MainWindow::atProjectItemChange(int count){
    if(count > 0) changeCoreWidget(WindowState::Main);
    else changeCoreWidget(WindowState::Default);
}







