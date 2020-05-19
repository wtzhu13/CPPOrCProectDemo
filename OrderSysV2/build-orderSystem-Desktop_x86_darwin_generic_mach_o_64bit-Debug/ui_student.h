/********************************************************************************
** Form generated from reading UI file 'student.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_H
#define UI_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Student
{
public:
    QPushButton *pushButton_applyOrder;
    QComboBox *comboBox_orderDate;
    QComboBox *comboBox_orderTime;
    QComboBox *comboBox_orderRoom;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_checkSelfOrder;
    QPushButton *pushButton_cancleOrder;
    QPushButton *pushButton_checkAllOrder;

    void setupUi(QWidget *Student)
    {
        if (Student->objectName().isEmpty())
            Student->setObjectName(QString::fromUtf8("Student"));
        Student->resize(604, 468);
        pushButton_applyOrder = new QPushButton(Student);
        pushButton_applyOrder->setObjectName(QString::fromUtf8("pushButton_applyOrder"));
        pushButton_applyOrder->setGeometry(QRect(370, 40, 112, 32));
        comboBox_orderDate = new QComboBox(Student);
        comboBox_orderDate->addItem(QString());
        comboBox_orderDate->addItem(QString());
        comboBox_orderDate->addItem(QString());
        comboBox_orderDate->addItem(QString());
        comboBox_orderDate->addItem(QString());
        comboBox_orderDate->setObjectName(QString::fromUtf8("comboBox_orderDate"));
        comboBox_orderDate->setGeometry(QRect(70, 40, 91, 32));
        comboBox_orderTime = new QComboBox(Student);
        comboBox_orderTime->addItem(QString());
        comboBox_orderTime->addItem(QString());
        comboBox_orderTime->setObjectName(QString::fromUtf8("comboBox_orderTime"));
        comboBox_orderTime->setGeometry(QRect(170, 40, 91, 32));
        comboBox_orderRoom = new QComboBox(Student);
        comboBox_orderRoom->addItem(QString());
        comboBox_orderRoom->addItem(QString());
        comboBox_orderRoom->addItem(QString());
        comboBox_orderRoom->setObjectName(QString::fromUtf8("comboBox_orderRoom"));
        comboBox_orderRoom->setGeometry(QRect(270, 40, 91, 32));
        label = new QLabel(Student);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 58, 16));
        label_2 = new QLabel(Student);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 20, 58, 16));
        label_3 = new QLabel(Student);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 20, 58, 16));
        pushButton_checkSelfOrder = new QPushButton(Student);
        pushButton_checkSelfOrder->setObjectName(QString::fromUtf8("pushButton_checkSelfOrder"));
        pushButton_checkSelfOrder->setGeometry(QRect(370, 110, 112, 32));
        pushButton_cancleOrder = new QPushButton(Student);
        pushButton_cancleOrder->setObjectName(QString::fromUtf8("pushButton_cancleOrder"));
        pushButton_cancleOrder->setGeometry(QRect(370, 240, 112, 32));
        pushButton_checkAllOrder = new QPushButton(Student);
        pushButton_checkAllOrder->setObjectName(QString::fromUtf8("pushButton_checkAllOrder"));
        pushButton_checkAllOrder->setGeometry(QRect(370, 170, 112, 32));

        retranslateUi(Student);

        QMetaObject::connectSlotsByName(Student);
    } // setupUi

    void retranslateUi(QWidget *Student)
    {
        Student->setWindowTitle(QApplication::translate("Student", "Form", nullptr));
        pushButton_applyOrder->setText(QApplication::translate("Student", "\347\224\263\350\257\267\351\242\204\347\272\246", nullptr));
        comboBox_orderDate->setItemText(0, QApplication::translate("Student", "\345\221\250\344\270\200", nullptr));
        comboBox_orderDate->setItemText(1, QApplication::translate("Student", "\345\221\250\344\272\214", nullptr));
        comboBox_orderDate->setItemText(2, QApplication::translate("Student", "\345\221\250\344\270\211", nullptr));
        comboBox_orderDate->setItemText(3, QApplication::translate("Student", "\345\221\250\345\233\233", nullptr));
        comboBox_orderDate->setItemText(4, QApplication::translate("Student", "\345\221\250\344\272\224", nullptr));

        comboBox_orderTime->setItemText(0, QApplication::translate("Student", "\344\270\212\345\215\210", nullptr));
        comboBox_orderTime->setItemText(1, QApplication::translate("Student", "\344\270\213\345\215\210", nullptr));

        comboBox_orderRoom->setItemText(0, QApplication::translate("Student", "1\345\217\267\346\234\272\346\210\277", nullptr));
        comboBox_orderRoom->setItemText(1, QApplication::translate("Student", "2\345\217\267\346\234\272\346\210\277", nullptr));
        comboBox_orderRoom->setItemText(2, QApplication::translate("Student", "3\345\217\267\346\234\272\346\210\277", nullptr));

        label->setText(QApplication::translate("Student", "\351\242\204\347\272\246\346\227\245\346\234\237", nullptr));
        label_2->setText(QApplication::translate("Student", "\351\242\204\347\272\246\346\227\266\351\227\264", nullptr));
        label_3->setText(QApplication::translate("Student", "\351\242\204\347\272\246\346\234\272\346\210\277", nullptr));
        pushButton_checkSelfOrder->setText(QApplication::translate("Student", "\346\237\245\347\234\213\350\207\252\345\267\261\351\242\204\347\272\246", nullptr));
        pushButton_cancleOrder->setText(QApplication::translate("Student", "\345\217\226\346\266\210\351\242\204\347\272\246\351\242\204\347\272\246", nullptr));
        pushButton_checkAllOrder->setText(QApplication::translate("Student", "\346\237\245\347\234\213\346\211\200\346\234\211\351\242\204\347\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student: public Ui_Student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_H
