#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
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

int PackedWidget::getAllPictureNameFrom(QVector<QString> &names, QString path){
    QDir dir(path);
    
    if(!dir.exists()){
        return 0;
    }
    
    const QStringList &files = dir.entryList(QStringList("*.png"));
    for(auto &f : files){
        names.push_back(f);
    }
    
    return names.size();
}

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
    QVector<QString> filenames;
    const QString inpath = ui -> editInput -> text();
    const QString outpath = ui -> editOutput -> text();
    
    /* 检查预置条件 */
    if(!checkPrecondition()){
        QMessageBox::warning(this, tr("错误"), tr("未选择正确的目录"));
        return;
    }
    
    /* 获取选定目录下的所有文件名称 */
    if(getAllPictureNameFrom(filenames, inpath) == 0){
        QMessageBox::warning(this, tr("错误"), tr("选择的目录下没有任何png文件"));
        return;
    }
    
    //todo
}
