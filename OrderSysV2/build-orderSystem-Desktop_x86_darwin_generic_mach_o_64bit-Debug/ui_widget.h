/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_addUser;
    QPushButton *pushButton_delUser;
    QPushButton *pushButton_roomInfo;
    QPushButton *pushButton_clearOrder;
    QTableView *tableView;
    QPushButton *pushButton_modifyUserInfo;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(581, 528);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(455, 262));
        Widget->setMaximumSize(QSize(65535, 65535));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 440, 112, 32));
        pushButton_addUser = new QPushButton(Widget);
        pushButton_addUser->setObjectName(QString::fromUtf8("pushButton_addUser"));
        pushButton_addUser->setGeometry(QRect(210, 440, 112, 32));
        pushButton_delUser = new QPushButton(Widget);
        pushButton_delUser->setObjectName(QString::fromUtf8("pushButton_delUser"));
        pushButton_delUser->setGeometry(QRect(320, 440, 112, 32));
        pushButton_roomInfo = new QPushButton(Widget);
        pushButton_roomInfo->setObjectName(QString::fromUtf8("pushButton_roomInfo"));
        pushButton_roomInfo->setGeometry(QRect(320, 470, 112, 32));
        pushButton_clearOrder = new QPushButton(Widget);
        pushButton_clearOrder->setObjectName(QString::fromUtf8("pushButton_clearOrder"));
        pushButton_clearOrder->setGeometry(QRect(210, 470, 112, 32));
        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 20, 511, 401));
        pushButton_modifyUserInfo = new QPushButton(Widget);
        pushButton_modifyUserInfo->setObjectName(QString::fromUtf8("pushButton_modifyUserInfo"));
        pushButton_modifyUserInfo->setGeometry(QRect(100, 470, 112, 32));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "OrderSystem", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\346\237\245\350\257\242\347\224\250\346\210\267", nullptr));
        pushButton_addUser->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        pushButton_delUser->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        pushButton_roomInfo->setText(QApplication::translate("Widget", "\346\237\245\347\234\213\346\234\272\346\210\277\344\277\241\346\201\257", nullptr));
        pushButton_clearOrder->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\351\242\204\347\272\246", nullptr));
        pushButton_modifyUserInfo->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
