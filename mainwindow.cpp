#include "mainwindow.h"
#include "packedwidget.h"
#include "./ui_mainwindow.h"
#include "./ui_mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    
    switch(state){
        default:
        case WindowState::Default:
            m_winstate = state;
            m_wgtMain =  takeCentralWidget();
            setCentralWidget(m_wgtDefault);
            break;
        case WindowState::Main:
            m_winstate = state;
            m_wgtDefault = takeCentralWidget();
            setCentralWidget(m_wgtMain);
            break;
    }
}

void MainWindow::initConnection(){
    
}

//===================== Slots =====================
void MainWindow::atActionPackClicked(){
    auto wgtProject = m_wgtMain -> ui -> wgtProject;
    wgtProject -> addWidget(new PackedWidget());
}

void MainWindow::atActionUnpackClicked(){

}










