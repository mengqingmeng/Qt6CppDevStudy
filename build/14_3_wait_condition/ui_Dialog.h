/********************************************************************************
** Form generated from reading UI file 'Dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnStartThread;
    QPushButton *btnStopThread;
    QPushButton *btnClear;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *plainTextEdit;
    QLabel *LabPic;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Lab;
    QLabel *LabA;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(497, 297);
        horizontalLayout = new QHBoxLayout(Dialog);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnStartThread = new QPushButton(widget);
        btnStartThread->setObjectName("btnStartThread");

        horizontalLayout_2->addWidget(btnStartThread);

        btnStopThread = new QPushButton(widget);
        btnStopThread->setObjectName("btnStopThread");

        horizontalLayout_2->addWidget(btnStopThread);

        btnClear = new QPushButton(widget);
        btnClear->setObjectName("btnClear");

        horizontalLayout_2->addWidget(btnClear);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        plainTextEdit = new QPlainTextEdit(widget_2);
        plainTextEdit->setObjectName("plainTextEdit");

        horizontalLayout_4->addWidget(plainTextEdit);

        LabPic = new QLabel(widget_2);
        LabPic->setObjectName("LabPic");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LabPic->sizePolicy().hasHeightForWidth());
        LabPic->setSizePolicy(sizePolicy1);
        LabPic->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(LabPic);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Lab = new QLabel(widget_3);
        Lab->setObjectName("Lab");

        horizontalLayout_3->addWidget(Lab);

        LabA = new QLabel(widget_3);
        LabA->setObjectName("LabA");

        horizontalLayout_3->addWidget(LabA);


        verticalLayout->addWidget(widget_3);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\347\272\277\347\250\213", nullptr));
        btnStartThread->setText(QCoreApplication::translate("Dialog", "\345\220\257\345\212\250\347\272\277\347\250\213", nullptr));
        btnStopThread->setText(QCoreApplication::translate("Dialog", "\347\273\223\346\235\237\347\272\277\347\250\213", nullptr));
        btnClear->setText(QCoreApplication::translate("Dialog", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        LabPic->setText(QString());
        Lab->setText(QCoreApplication::translate("Dialog", "Thread\347\212\266\346\200\201\357\274\232", nullptr));
        LabA->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
