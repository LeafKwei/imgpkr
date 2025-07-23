#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
}

void MainWindow::createCoreWidget(){
    m_wgtDefault = new DefaultWidget();
    m_wgtMain = new MainWidget();
}

void MainWindow::changeCoreWidget(WindowState state){
    switch(state){
        default:
        case WindowState::Default:
            m_winstate = state;
            setCentralWidget(m_wgtDefault);
            break;
        case WindowState::Main:
            m_winstate = state;
            setCentralWidget(m_wgtMain);
            break;
    }
}
