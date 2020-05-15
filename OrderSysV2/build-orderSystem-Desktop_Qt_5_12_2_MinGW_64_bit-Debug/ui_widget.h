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
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_roomInfo;
    QPushButton *pushButton_5;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(922, 527);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(455, 262));
        Widget->setMaximumSize(QSize(65535, 65535));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 470, 112, 32));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 470, 112, 32));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(380, 470, 112, 32));
        pushButton_roomInfo = new QPushButton(Widget);
        pushButton_roomInfo->setObjectName(QString::fromUtf8("pushButton_roomInfo"));
        pushButton_roomInfo->setGeometry(QRect(530, 470, 112, 32));
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(680, 470, 112, 32));
        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 901, 451));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "OrderSystem", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\346\237\245\350\257\242\347\224\250\346\210\267", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        pushButton_roomInfo->setText(QApplication::translate("Widget", "\346\237\245\347\234\213\346\234\272\346\210\277\344\277\241\346\201\257", nullptr));
        pushButton_5->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\351\242\204\347\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
