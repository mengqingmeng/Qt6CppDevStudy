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

int DiceThread::diceValue()
{
    return m_diceValue;
}

void DiceThread::run(){

    // 初始化标识
    m_stop = false;
    m_seq = 0;

    // 设置随机种子
    srand(QTime::currentTime().msec());
    while(!m_stop){ // 未停止
        if(!m_paused){ // 未暂停
            m_diceValue = (rand() % 6) + 1; // 1-6 随机数
            m_seq++; // 次数
            emit newValue(m_seq,m_diceValue);
        }
        msleep(500);
    }

    quit();

}
