/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *loginTitle;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(400, 300));
        Dialog->setMaximumSize(QSize(400, 300));
        Dialog->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 110, 113, 20));
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 150, 113, 20));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 110, 54, 12));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 150, 54, 12));
        label_2->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 230, 121, 31));
        comboBox = new QComboBox(Dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(190, 190, 113, 20));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 190, 58, 16));
        label_3->setAlignment(Qt::AlignCenter);
        loginTitle = new QLabel(Dialog);
        loginTitle->setObjectName(QString::fromUtf8("loginTitle"));
        loginTitle->setGeometry(QRect(130, 40, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        loginTitle->setFont(font);
        loginTitle->setScaledContents(false);
        loginTitle->setMargin(10);
#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\345\257\206    \347\240\201", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "\347\231\273\345\275\225", nullptr));
        comboBox->setItemText(0, QApplication::translate("Dialog", "\345\255\246\347\224\237", nullptr));
        comboBox->setItemText(1, QApplication::translate("Dialog", "\350\200\201\345\270\210", nullptr));
        comboBox->setItemText(2, QApplication::translate("Dialog", "\347\256\241\347\220\206\345\221\230", nullptr));

        label_3->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\350\272\253\344\273\275", nullptr));
        loginTitle->setText(QApplication::translate("Dialog", "\346\254\242\350\277\216\344\275\277\347\224\250\351\242\204\347\272\246\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H