#include "Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    initUI();
    initSignalSlots();
    setWindowTitle(tr("手工创建UI"));
    // 生成一个随机的 UUID
    QUuid uuid = QUuid::createUuid();

    // 将 UUID 转换为字符串格式
    QString uuidString = uuid.toString(QUuid::WithoutBraces);

    qDebug() << "Generated UUID: " << uuidString;
}

Dialog::~Dialog()
{
}

void Dialog::initUI()
{
    // 字体样式复选框
    chkBoxUnder = new QCheckBox("Underline");
    chkBoxItalic = new QCheckBox("Italic");
    chKBoxBold = new QCheckBox("Bold");

    QHBoxLayout* hLay1 = new QHBoxLayout();
    hLay1->addWidget(chkBoxUnder);
    hLay1->addWidget(chkBoxItalic);
    hLay1->addWidget(chKBoxBold);

    // 颜色 单选框
    radioBlack = new QRadioButton("Black");
    radioBlack->setCheckable(true);
    radioBlue = new QRadioButton("Blue");
    radioBlue->setCheckable(true);
    radioRed = new QRadioButton("Red");
    radioRed->setCheckable(true);

    QHBoxLayout* hLay2 = new QHBoxLayout();
    hLay2->addWidget(radioBlack);
    hLay2->addWidget(radioBlue);
    hLay2->addWidget(radioRed);

    // 按钮
    btnOk = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("关闭");
    QHBoxLayout* hLay3 = new QHBoxLayout();
    hLay3->addWidget(btnOk);
    hLay3->addWidget(btnCancel);
    hLay3->addWidget(btnClose);

    textEdit = new QPlainTextEdit;
    textEdit->setPlainText("Hello world\n 手工创建");
    QFont font = textEdit->font();
    font.setPointSize(20);
    textEdit->setFont(font);

    QVBoxLayout* vLay = new QVBoxLayout(this);
    vLay->addLayout(hLay1);
    vLay->addLayout(hLay2);
    vLay->addWidget(textEdit);
    vLay->addLayout(hLay3);
    setLayout(vLay);
}

void Dialog::initSignalSlots()
{
    connect(chkBoxUnder,&QCheckBox::clicked,this,&Dialog::do_chckBoxunder);
    connect(chKBoxBold,&QCheckBox::clicked,this,&Dialog::do_chkBoxBold);
    connect(chkBoxItalic,&QCheckBox::clicked,this,&Dialog::do_chkBoxItalic);

    connect(radioBlack,&QCheckBox::clicked,this,&Dialog::do_setFontColor);
    connect(radioRed,&QCheckBox::clicked,this,&Dialog::do_setFontColor);
    connect(radioBlue,&QCheckBox::clicked,this,&Dialog::do_setFontColor);

    connect(btnOk,&QCheckBox::clicked,this,&QDialog::accept);
    connect(btnCancel,&QCheckBox::clicked,this,&QDialog::reject);
    connect(btnClose,&QCheckBox::clicked,this,&QDialog::close);
}

void Dialog::do_chckBoxunder(bool checked)
{
    QFont font = textEdit->font();
    font.setUnderline(checked);
    textEdit->setFont(font);
}

void Dialog::do_chkBoxItalic(bool checked)
{
    QFont font = textEdit->font();
    font.setItalic(checked);
    textEdit->setFont(font);
}

void Dialog::do_chkBoxBold(bool checked)
{
    QFont font = textEdit->font();
    font.setBold(checked);
    textEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    QPalette palette = textEdit->palette();
    if(radioBlack->isChecked()){
        palette.setColor(QPalette::Text,QColor(Qt::black));
    }else if(radioBlue->isChecked()){
        palette.setColor(QPalette::Text,QColor(Qt::blue));
    }else if(radioRed->isChecked()){
        palette.setColor(QPalette::Text,QColor(Qt::red));
    }

    textEdit->setPalette(palette);

}

