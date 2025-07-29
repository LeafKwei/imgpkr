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
    createCoreWidget();
    changeCoreWidget(WindowState::Default);
    initConnection();
}

void MainWindow::createCoreWidget(){
    m_wgtDefault = new DefaultWidget();
    m_wgtMain = new MainWidget();
}

void MainWindow::changeCoreWidget(WindowState state){
    if(state == m_winstate) return;
    
    decltype(m_wgtMain) bakMain;
    decltype(m_wgtDefault) bakDefault;
    
    switch(state){
        default:
        case WindowState::Default:
            m_winstate = state;
            bakMain = dynamic_cast<MainWidget*>(takeCentralWidget());
            if(bakMain != nullptr) m_wgtMain = bakMain;
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
    connect(ui -> menuNew, SIGNAL(triggered(QAction*)), this, SLOT(atMenuNewTriggered(QAction*)));
    connect(ui -> menuEdit, SIGNAL(triggered(QAction*)), m_wgtMain, SLOT(atMenuEditTriggered(QAction*)));
    connect(m_wgtMain, SIGNAL(projectItemChange(int)), this, SLOT(atProjectItemChange(int)));
}

void MainWindow::exitMainWindow(){
    QCoreApplication::exit(0);
}

//===================== Slots =====================
void MainWindow::atMenuNewTriggered(QAction *act){
    if(act -> text() == "退出") exitMainWindow();
}

void MainWindow::atProjectItemChange(int count){
    if(count > 0) changeCoreWidget(WindowState::Main);
    else changeCoreWidget(WindowState::Default);
}







