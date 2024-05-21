#ifndef DICETHREAD_H
#define DICETHREAD_H

#include <QThread>
#include <QTime>
#include <QMutex>
#include <QMutexLocker>
#include <QReadWriteLock>
#include <QWaitCondition>
#include <QRandomGenerator>

extern QReadWriteLock rwLocker;
extern QWaitCondition waiter;
extern int seq,diceValue;

// 骰子线程
class DiceThread : public QThread
{
    Q_OBJECT
public:
    explicit DiceThread(QObject *parent = nullptr);

protected:
    void run() override;
};

// 接受骰子线程数据
class ValueThread : public QThread{
    Q_OBJECT
public:
    explicit ValueThread(QObject* parent = nullptr);

Q_SIGNALS:
    void newValue(int seq,int diceValue);

protected:
    void run() override;
};

//
class PictureThread : public QThread{
    Q_OBJECT
public:
    explicit PictureThread(QObject* parent =nullptr);

Q_SIGNALS:
    void pictureValue(QString filename);

protected:
    void run() override;
};

#endif // DICETHREAD_H
