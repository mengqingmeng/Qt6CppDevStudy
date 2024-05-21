#include "DiceThread.h"

DiceThread::DiceThread(QObject *parent)
    : QThread{parent}
{

}

void DiceThread::diceBegin(){ // 开始
    m_paused = false;
}

void DiceThread::dicePause(){ // 暂停
    m_paused = true;
}

void DiceThread::stopThread(){
    m_stop = true;
}

bool DiceThread::readValue(int *seq, int *diceValue)
{
    if(locker.tryLock(100)){
        *seq = m_seq;
        *diceValue = m_diceValue;
        locker.unlock();
        return true;
    }
    return false;
}

void DiceThread::run(){

    // 初始化标识
    m_stop = false;
    m_paused = true;
    m_seq = 0;

    // 设置随机种子
    srand(QTime::currentTime().msec());
    while(!m_stop){ // 未停止
        if(!m_paused){ // 未暂停
            locker.lock();
            m_diceValue = QRandomGenerator::global()->bounded(1,7); // 1-6 随机数
            m_seq++; // 次数
            locker.unlock();
        }
        msleep(500);
    }

    quit();
}
