#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QUuid>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    // 3个复选框
    QCheckBox* chkBoxUnder;     // 下划线
    QCheckBox* chkBoxItalic;    // 斜体
    QCheckBox* chKBoxBold;      // 粗体
    // 3个单选框
    QRadioButton* radioBlack;   // 黑色
    QRadioButton* radioRed;     // 红色
    QRadioButton* radioBlue;    // 蓝色

    QPushButton* btnOk;
    QPushButton* btnCancel;
    QPushButton* btnClose;

    QPlainTextEdit* textEdit;

    void initUI();
    void initSignalSlots();

private slots:
    void do_chckBoxunder(bool checked);
    void do_chkBoxItalic(bool checked);
    void do_chkBoxBold(bool checked);
    void do_setFontColor();
};
#endif // DIALOG_H
