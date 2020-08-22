/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QPlainTextEdit *plainTextEditReceive;
    QGridLayout *gridLayout;
    QComboBox *serialPortNum;
    QLabel *label;
    QComboBox *baudRate;
    QLabel *label_2;
    QComboBox *dataCb;
    QLabel *label_3;
    QComboBox *stopCb;
    QLabel *label_4;
    QComboBox *checkCb;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QLabel *label_6;
    QLineEdit *lineEditSend;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonOpen;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClose;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonSend;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonClear;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(652, 506);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        plainTextEditReceive = new QPlainTextEdit(Widget);
        plainTextEditReceive->setObjectName(QString::fromUtf8("plainTextEditReceive"));
        plainTextEditReceive->setReadOnly(true);

        gridLayout_2->addWidget(plainTextEditReceive, 0, 0, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        serialPortNum = new QComboBox(Widget);
        serialPortNum->setObjectName(QString::fromUtf8("serialPortNum"));

        gridLayout->addWidget(serialPortNum, 0, 0, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        baudRate = new QComboBox(Widget);
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->setObjectName(QString::fromUtf8("baudRate"));

        gridLayout->addWidget(baudRate, 1, 0, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        dataCb = new QComboBox(Widget);
        dataCb->addItem(QString());
        dataCb->addItem(QString());
        dataCb->addItem(QString());
        dataCb->setObjectName(QString::fromUtf8("dataCb"));

        gridLayout->addWidget(dataCb, 2, 0, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        stopCb = new QComboBox(Widget);
        stopCb->addItem(QString());
        stopCb->addItem(QString());
        stopCb->addItem(QString());
        stopCb->setObjectName(QString::fromUtf8("stopCb"));

        gridLayout->addWidget(stopCb, 3, 0, 1, 1);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        checkCb = new QComboBox(Widget);
        checkCb->addItem(QString());
        checkCb->setObjectName(QString::fromUtf8("checkCb"));

        gridLayout->addWidget(checkCb, 4, 0, 1, 1);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 10, 311, 51));

        verticalLayout_2->addWidget(groupBox);

        lineEditSend = new QLineEdit(Widget);
        lineEditSend->setObjectName(QString::fromUtf8("lineEditSend"));

        verticalLayout_2->addWidget(lineEditSend);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        pushButtonOpen = new QPushButton(Widget);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));

        horizontalLayout_6->addWidget(pushButtonOpen);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButtonClose = new QPushButton(Widget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));

        horizontalLayout_6->addWidget(pushButtonClose);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        pushButtonSend = new QPushButton(Widget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        horizontalLayout_6->addWidget(pushButtonSend);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        pushButtonClear = new QPushButton(Widget);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

        horizontalLayout_6->addWidget(pushButtonClear);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_6);


        gridLayout_2->addLayout(verticalLayout_2, 1, 1, 1, 1);


        retranslateUi(Widget);

        baudRate->setCurrentIndex(2);
        dataCb->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "serialAssistant", nullptr));
        label->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", nullptr));
        baudRate->setItemText(0, QApplication::translate("Widget", "4800", nullptr));
        baudRate->setItemText(1, QApplication::translate("Widget", "9600", nullptr));
        baudRate->setItemText(2, QApplication::translate("Widget", "115200", nullptr));

        label_2->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        dataCb->setItemText(0, QApplication::translate("Widget", "6", nullptr));
        dataCb->setItemText(1, QApplication::translate("Widget", "7", nullptr));
        dataCb->setItemText(2, QApplication::translate("Widget", "8", nullptr));

        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", nullptr));
        stopCb->setItemText(0, QApplication::translate("Widget", "1", nullptr));
        stopCb->setItemText(1, QApplication::translate("Widget", "1.5", nullptr));
        stopCb->setItemText(2, QApplication::translate("Widget", "2", nullptr));

        label_4->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", nullptr));
        checkCb->setItemText(0, QApplication::translate("Widget", "None", nullptr));

        label_5->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", nullptr));
        groupBox->setTitle(QString());
        label_6->setText(QApplication::translate("Widget", "<html><head/><body><p>\350\207\252\345\210\266\344\270\262\345\217\243\345\212\251\346\211\213</p><p>\344\275\234\350\200\205\357\274\232\347\214\252\347\214\252\347\210\261\345\220\203\351\261\274    e-mail:wtzhu_13@163.com</p><p>\346\227\266\351\227\264\357\274\2322020.08.22</p></body></html>", nullptr));
        pushButtonOpen->setText(QApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));
        pushButtonClose->setText(QApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        pushButtonSend->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        pushButtonClear->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
