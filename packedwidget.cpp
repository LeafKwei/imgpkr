#include <QMessageBox>
#include <QFileDialog>
#include "packedwidget.h"
#include "task/taskpack.h"
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
    initComponent();
    initConnection();
}

void PackedWidget::initComponent(){
    m_dlgProgbar = new QProgressDialog(this);
    m_dlgProgbar -> reset();  //reset函数会调用QProgressDialog内部的stop函数，避免其创建后自动弹出
    m_dlgProgbar -> setLabelText(tr("处理中..."));
    m_dlgProgbar -> setCancelButtonText("取消");
}

void PackedWidget::initConnection(){
    connect(ui -> btnInput, SIGNAL(clicked(bool)), this, SLOT(atBtnInputClicked(bool)));
    connect(ui -> btnOutput, SIGNAL(clicked(bool)), this, SLOT(atBtnOutputClicked(bool)));
    connect(ui -> btnPack, SIGNAL(clicked(bool)), this, SLOT(atBtnPackClicked(bool)));
}

/* 检查打包前的所有预置条件是否满足 */
bool PackedWidget::checkPrecondition(){
    /* 文件路径是否正常 */
    if(ui -> editInput -> text().size() == 0){
        return false;
    }
    
    if(ui -> editOutput -> text().size() == 0){
        return false;
    }
    
    return true;
}

TaskPtr PackedWidget::makeTask(){
    TaskPtr tp(new TaskPack(
        makeRandomID(ID_BOUND),
        ui -> editInput -> text(),
        ui -> editOutput -> text())
    );
    
    return tp;
}

void PackedWidget::enablePackFunc(){
    ui -> btnPack -> setDisabled(false);
}

void PackedWidget::disablePackFunc(){
    ui -> btnPack -> setDisabled(true);
}

///////////////////////////////////////////////////////////////////////// SLOT

/* 选择输入文件所在的目录路径 */
void PackedWidget::atBtnInputClicked(bool b){
    QString path = QFileDialog::getExistingDirectory(
        this, tr("选择一个目录"), "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        
    if(path.isEmpty()) return;
    ui -> editInput -> setText(path);
}

/* 选择输出文件所在的目录路径 */
void PackedWidget::atBtnOutputClicked(bool b){
    QString path = QFileDialog::getExistingDirectory(
        this, tr("选择一个目录"), "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        
    if(path.isEmpty()) return;
    ui -> editOutput -> setText(path);
}

void PackedWidget::atBtnPackClicked(bool b){
    /* 检查预置条件 */
    if(!checkPrecondition()){
        QMessageBox::warning(this, tr("错误"), tr("未选择正确的目录"));
        return;
    }

    /* 当预置条件验证完毕后，禁用打包功能，随后创建Task并通过信号通知mainwidget处理 */
    disablePackFunc();
    auto tp = makeTask();
    m_taskid = tp -> id();
    emit sendPackTask(tp);
}

void PackedWidget::atPackTaskDone(int id){
    /* 检查任务id是否等于自身派发的任务id，如果不是则忽略 */
    if(id != m_taskid && (-id) != m_taskid){
        return;
    }
    
    m_taskid = -1; //任务完成后，将taskid置为负数
    qDebug() << "Task " << id << " Done.";
    enablePackFunc();
}
