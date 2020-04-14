/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNEW;
    QAction *actionOPEN;
    QAction *actionSAVE;
    QAction *actionSAVE_AS;
    QAction *actionQUITE;
    QAction *actionundo;
    QAction *actioncopy;
    QAction *actionpaste;
    QAction *actioncut;
    QAction *actionUTF_8;
    QAction *actionGBK;
    QAction *actioncomplie;
    QWidget *centralWidget;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuedit;
    QMenu *menubuild;
    QMenu *menucode;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1041, 679);
        actionNEW = new QAction(MainWindow);
        actionNEW->setObjectName(QString::fromUtf8("actionNEW"));
        actionOPEN = new QAction(MainWindow);
        actionOPEN->setObjectName(QString::fromUtf8("actionOPEN"));
        actionSAVE = new QAction(MainWindow);
        actionSAVE->setObjectName(QString::fromUtf8("actionSAVE"));
        actionSAVE_AS = new QAction(MainWindow);
        actionSAVE_AS->setObjectName(QString::fromUtf8("actionSAVE_AS"));
        actionQUITE = new QAction(MainWindow);
        actionQUITE->setObjectName(QString::fromUtf8("actionQUITE"));
        actionundo = new QAction(MainWindow);
        actionundo->setObjectName(QString::fromUtf8("actionundo"));
        actioncopy = new QAction(MainWindow);
        actioncopy->setObjectName(QString::fromUtf8("actioncopy"));
        actionpaste = new QAction(MainWindow);
        actionpaste->setObjectName(QString::fromUtf8("actionpaste"));
        actioncut = new QAction(MainWindow);
        actioncut->setObjectName(QString::fromUtf8("actioncut"));
        actionUTF_8 = new QAction(MainWindow);
        actionUTF_8->setObjectName(QString::fromUtf8("actionUTF_8"));
        actionGBK = new QAction(MainWindow);
        actionGBK->setObjectName(QString::fromUtf8("actionGBK"));
        actioncomplie = new QAction(MainWindow);
        actioncomplie->setObjectName(QString::fromUtf8("actioncomplie"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 581, 21));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 20, 1041, 611));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1041, 23));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuedit = new QMenu(menuBar);
        menuedit->setObjectName(QString::fromUtf8("menuedit"));
        menubuild = new QMenu(menuBar);
        menubuild->setObjectName(QString::fromUtf8("menubuild"));
        menucode = new QMenu(menuBar);
        menucode->setObjectName(QString::fromUtf8("menucode"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuedit->menuAction());
        menuBar->addAction(menubuild->menuAction());
        menuBar->addAction(menucode->menuAction());
        menufile->addAction(actionNEW);
        menufile->addAction(actionOPEN);
        menufile->addAction(actionSAVE);
        menufile->addAction(actionSAVE_AS);
        menufile->addAction(actionQUITE);
        menuedit->addAction(actionundo);
        menuedit->addAction(actioncopy);
        menuedit->addAction(actionpaste);
        menuedit->addAction(actioncut);
        menubuild->addAction(actioncomplie);
        menucode->addAction(actionUTF_8);
        menucode->addAction(actionGBK);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNEW->setText(QApplication::translate("MainWindow", "NEW", nullptr));
        actionOPEN->setText(QApplication::translate("MainWindow", "OPEN", nullptr));
        actionSAVE->setText(QApplication::translate("MainWindow", "SAVE", nullptr));
        actionSAVE_AS->setText(QApplication::translate("MainWindow", "SAVE AS", nullptr));
        actionQUITE->setText(QApplication::translate("MainWindow", "QUITE", nullptr));
        actionundo->setText(QApplication::translate("MainWindow", "undo", nullptr));
        actioncopy->setText(QApplication::translate("MainWindow", "copy", nullptr));
        actionpaste->setText(QApplication::translate("MainWindow", "paste", nullptr));
        actioncut->setText(QApplication::translate("MainWindow", "cut", nullptr));
        actionUTF_8->setText(QApplication::translate("MainWindow", "UTF-8", nullptr));
        actionGBK->setText(QApplication::translate("MainWindow", "GBK", nullptr));
        actioncomplie->setText(QApplication::translate("MainWindow", "complie", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\344\273\245UTF-8\346\230\276\347\244\272", nullptr));
        menufile->setTitle(QApplication::translate("MainWindow", "FILE", nullptr));
        menuedit->setTitle(QApplication::translate("MainWindow", "EDIT", nullptr));
        menubuild->setTitle(QApplication::translate("MainWindow", "BUILD", nullptr));
        menucode->setTitle(QApplication::translate("MainWindow", "CODE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
