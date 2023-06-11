#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    diceThread = new DiceThread(this);
    valueThread = new ValueThread(this);
    pictureThread = new PictureThread(this);

    // started、finised为QThread的信号
    connect(diceThread,&DiceThread::started,this,&Dialog::onThreadStarted); // 线程开始
    connect(diceThread,&DiceThread::finished,this,&Dialog::onThreadFinished); // 线程结束

    connect(valueThread,&ValueThread::newValue,this,&Dialog::onThreadNewValue); // 新值信号
    connect(pictureThread,&PictureThread::pictureValue,this,[&](QString name){
        QPixmap  pic;
        int width = ui->LabPic->width();
        int height = ui->LabPic->height();
        pic.load(name);
        pic = pic.scaled(width,height,Qt::AspectRatioMode::KeepAspectRatio);
        ui->LabPic->setPixmap(pic);
    }); // 新图信号
}

// 槽：线程启动时触发
void Dialog::onThreadStarted(){
    ui->LabA->setText("启动");
}

// 槽：线程结束时触发
void Dialog::onThreadFinished(){
    ui->LabA->setText("结束");
}

// 槽函数，线程产生新值时触发。
void Dialog::onThreadNewValue(int seq,int diceValue){ // 线程值
    QString str = QString::fromLocal8Bit("第%1次投骰子，显示点数:%2")
                      .arg(seq,3)
                      .arg(diceValue,1);
    ui->plainTextEdit->appendPlainText(str);
}

// 软件关闭时，关闭线程。
void Dialog::closeEvent(QCloseEvent* event)
{
    accept();
}

//  启动线程
void Dialog::on_btnStartThread_clicked()
{

    // 1. 先开始消费者线程
    if(!valueThread->isRunning())
        valueThread->start();

    if(!pictureThread->isRunning())
        pictureThread->start();

    // 2. 再开始生产者线程。不然：先开始生产者线程，消费者未启动，数据会丢失。
    diceThread->start();

    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);
}

// 清除日志
void Dialog::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}

// 结束线程
void Dialog::on_btnStopThread_clicked()
{
    diceThread->terminate();
    diceThread->quit();

    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}
