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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QTableView *tableView;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_modifyUserInfo;
    QPushButton *pushButton_delUser;
    QPushButton *pushButton_roomInfo;
    QPushButton *pushButton_addUser;
    QPushButton *pushButton_clearOrder;
    QFrame *frame_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_pwd;
    QLineEdit *lineEdit_naem;

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
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 541, 281));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tableView = new QTableView(frame);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 521, 251));
        frame_2 = new QFrame(Widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(290, 300, 271, 201));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_modifyUserInfo = new QPushButton(frame_2);
        pushButton_modifyUserInfo->setObjectName(QString::fromUtf8("pushButton_modifyUserInfo"));

        gridLayout->addWidget(pushButton_modifyUserInfo, 0, 1, 1, 1);

        pushButton_delUser = new QPushButton(frame_2);
        pushButton_delUser->setObjectName(QString::fromUtf8("pushButton_delUser"));

        gridLayout->addWidget(pushButton_delUser, 1, 0, 1, 1);

        pushButton_roomInfo = new QPushButton(frame_2);
        pushButton_roomInfo->setObjectName(QString::fromUtf8("pushButton_roomInfo"));

        gridLayout->addWidget(pushButton_roomInfo, 1, 1, 1, 1);

        pushButton_addUser = new QPushButton(frame_2);
        pushButton_addUser->setObjectName(QString::fromUtf8("pushButton_addUser"));

        gridLayout->addWidget(pushButton_addUser, 2, 0, 1, 1);

        pushButton_clearOrder = new QPushButton(frame_2);
        pushButton_clearOrder->setObjectName(QString::fromUtf8("pushButton_clearOrder"));

        gridLayout->addWidget(pushButton_clearOrder, 2, 1, 1, 1);

        frame_3 = new QFrame(Widget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 300, 271, 201));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 251, 181));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 3, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 1, 1, 1);

        lineEdit_id = new QLineEdit(groupBox);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        gridLayout_2->addWidget(lineEdit_id, 0, 2, 1, 1);

        lineEdit_pwd = new QLineEdit(groupBox);
        lineEdit_pwd->setObjectName(QString::fromUtf8("lineEdit_pwd"));

        gridLayout_2->addWidget(lineEdit_pwd, 2, 2, 1, 1);

        lineEdit_naem = new QLineEdit(groupBox);
        lineEdit_naem->setObjectName(QString::fromUtf8("lineEdit_naem"));

        gridLayout_2->addWidget(lineEdit_naem, 1, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "OrderSystem", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\346\237\245\350\257\242\347\224\250\346\210\267", nullptr));
        pushButton_modifyUserInfo->setText(QApplication::translate("Widget", "\344\277\256\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        pushButton_delUser->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        pushButton_roomInfo->setText(QApplication::translate("Widget", "\346\237\245\347\234\213\346\234\272\346\210\277\344\277\241\346\201\257", nullptr));
        pushButton_addUser->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        pushButton_clearOrder->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\351\242\204\347\272\246", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "\346\267\273\345\212\240\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        comboBox->setItemText(0, QApplication::translate("Widget", "student", nullptr));
        comboBox->setItemText(1, QApplication::translate("Widget", "teacher", nullptr));
        comboBox->setItemText(2, QApplication::translate("Widget", "admin", nullptr));

        label_4->setText(QApplication::translate("Widget", "\350\272\253\344\273\275", nullptr));
        label_2->setText(QApplication::translate("Widget", "\345\247\223\345\220\215", nullptr));
        label->setText(QApplication::translate("Widget", "\345\255\246\345\217\267", nullptr));
        label_3->setText(QApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
