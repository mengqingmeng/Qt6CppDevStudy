#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // 创建定时器，设置执行周期，并且暂停运行
    timer = new QTimer(this);
    timer->setInterval(200);
    timer->stop();

    // started、finised为QThread的信号
    connect(&thread,&DiceThread::started,this,&Dialog::onThreadStarted); // 线程开始
    connect(&thread,&DiceThread::finished,this,&Dialog::onThreadFinished); // 线程结束

    connect(timer,&QTimer::timeout,this,[&](){
        int tempSeq,value;
        bool result = thread.readValue(&tempSeq,&value);
        if(result && (tempSeq != m_curSeq)){
            m_curSeq = tempSeq;
            onThreadNewValue(tempSeq,value);
        }
    });
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
    QString str = QString::asprintf("第%d次投骰子，显示点数:%d",seq,diceValue);
    ui->plainTextEdit->appendPlainText(str);

    QPixmap  pic;
    int width = ui->LabPic->width();
    int height = ui->LabPic->height();
    //:/dice/images/d1.png
    QString filename = QString::asprintf(":/dice/images/d%d.png",diceValue);
    pic.load(filename);
    pic = pic.scaled(width,height,Qt::AspectRatioMode::KeepAspectRatio);
    ui->LabPic->setPixmap(pic);
}

// 软件关闭时，关闭线程。
void Dialog::closeEvent(QCloseEvent* event)
{
    if(thread.isRunning()){// 线程正在运行时：1.设置停止标识。2.quit退出线程。3.等待线程交出执行权。
        thread.stopThread();
        thread.quit();
        thread.wait(); // 交出线程的执行权
    }

    accept();
}

//  启动线程
void Dialog::on_btnStartThread_clicked()
{
    thread.start(); // 开始线程

    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);

    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

// 开始线程
void Dialog::on_btnDiceBegin_clicked()
{
    thread.diceBegin();
    timer->start();
    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(true);
}

// 暂停线程
void Dialog::on_btnDiceEnd_clicked()
{
    thread.dicePause();
    timer->stop();
    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

// 清除日志
void Dialog::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}

// 结束线程
void Dialog::on_btnStopThread_clicked()
{
    thread.stopThread();
    thread.quit();
    thread.wait();

    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(false);
    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}
