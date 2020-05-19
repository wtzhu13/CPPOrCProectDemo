/********************************************************************************
** Form generated from reading UI file 'teacher.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_H
#define UI_TEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Teacher
{
public:
    QLabel *label;
    QPushButton *pushButton_checkAllOrder;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Teacher)
    {
        if (Teacher->objectName().isEmpty())
            Teacher->setObjectName(QString::fromUtf8("Teacher"));
        Teacher->resize(400, 300);
        label = new QLabel(Teacher);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 58, 16));
        pushButton_checkAllOrder = new QPushButton(Teacher);
        pushButton_checkAllOrder->setObjectName(QString::fromUtf8("pushButton_checkAllOrder"));
        pushButton_checkAllOrder->setGeometry(QRect(190, 110, 112, 32));
        pushButton_2 = new QPushButton(Teacher);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 150, 112, 32));

        retranslateUi(Teacher);

        QMetaObject::connectSlotsByName(Teacher);
    } // setupUi

    void retranslateUi(QWidget *Teacher)
    {
        Teacher->setWindowTitle(QApplication::translate("Teacher", "Form", nullptr));
        label->setText(QApplication::translate("Teacher", "teacher", nullptr));
        pushButton_checkAllOrder->setText(QApplication::translate("Teacher", "\346\237\245\347\234\213\346\211\200\346\234\211\351\242\204\347\272\246", nullptr));
        pushButton_2->setText(QApplication::translate("Teacher", "\345\256\241\346\240\270\351\242\204\347\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Teacher: public Ui_Teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_H
