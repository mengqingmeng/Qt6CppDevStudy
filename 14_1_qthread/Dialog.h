#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "DiceThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    DiceThread thread;

private slots:
    void onThreadStarted();
    void onThreadFinished();
    void onThreadNewValue(int seq,int diceValue);

    /**
     * @brief on_btnStartThread_clicked 启动线程按钮
     */
    void on_btnStartThread_clicked();
    /**
     * @brief on_btnStopThread_clicked 停止线程按钮
     */
    void on_btnStopThread_clicked();

    void on_btnDiceBegin_clicked();
    void on_btnDiceEnd_clicked();

    void on_btnClear_clicked();

protected:
    void closeEvent(QCloseEvent* event);
};
#endif // DIALOG_H
