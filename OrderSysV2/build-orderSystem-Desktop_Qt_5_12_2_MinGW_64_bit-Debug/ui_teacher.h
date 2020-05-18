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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Teacher
{
public:
    QLabel *label;

    void setupUi(QWidget *Teacher)
    {
        if (Teacher->objectName().isEmpty())
            Teacher->setObjectName(QString::fromUtf8("Teacher"));
        Teacher->resize(400, 300);
        label = new QLabel(Teacher);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 130, 58, 16));

        retranslateUi(Teacher);

        QMetaObject::connectSlotsByName(Teacher);
    } // setupUi

    void retranslateUi(QWidget *Teacher)
    {
        Teacher->setWindowTitle(QApplication::translate("Teacher", "Form", nullptr));
        label->setText(QApplication::translate("Teacher", "teacher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Teacher: public Ui_Teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_H
