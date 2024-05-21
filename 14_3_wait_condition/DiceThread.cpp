#include "DiceThread.h"

DiceThread::DiceThread(QObject *parent)
    : QThread{parent}
{

}

void DiceThread::run(){
    seq = 0;
    while(1){
        rwLocker.lockForWrite();
        seq ++;
        diceValue = QRandomGenerator::global()->bounded(1,7);
        rwLocker.unlock();
        waiter.notify_all();
        msleep(500);
    }
}

ValueThread::ValueThread(QObject *parent)
{

}

void ValueThread::run()
{
    while(true){
        rwLocker.lockForRead();
        waiter.wait(&rwLocker);
        emit newValue(seq,diceValue);
        rwLocker.unlock();
    }
}

PictureThread::PictureThread(QObject *parent)
{

}

void PictureThread::run()
{
    while(true){
        rwLocker.lockForRead();
        waiter.wait(&rwLocker);
        QString filename = QString::asprintf(":/dice/images/d%d.png",diceValue);
        emit pictureValue(filename);
        rwLocker.unlock();
    }
}
