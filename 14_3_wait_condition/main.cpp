#include "Dialog.h"

#include <QApplication>
#include <QReadWriteLock>
#include <QWaitCondition>

QReadWriteLock rwLocker;
QWaitCondition waiter;
int seq = 0,diceValue = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
