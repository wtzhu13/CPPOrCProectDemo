/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(980, 650);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/a9f7716a1a25d7a4b2e5dc73bae4d860.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNEW = new QAction(MainWindow);
        actionNEW->setObjectName(QStringLiteral("actionNEW"));
        actionOPEN = new QAction(MainWindow);
        actionOPEN->setObjectName(QStringLiteral("actionOPEN"));
        actionSAVE = new QAction(MainWindow);
        actionSAVE->setObjectName(QStringLiteral("actionSAVE"));
        actionSAVE_AS = new QAction(MainWindow);
        actionSAVE_AS->setObjectName(QStringLiteral("actionSAVE_AS"));
        actionQUITE = new QAction(MainWindow);
        actionQUITE->setObjectName(QStringLiteral("actionQUITE"));
        actionundo = new QAction(MainWindow);
        actionundo->setObjectName(QStringLiteral("actionundo"));
        actioncopy = new QAction(MainWindow);
        actioncopy->setObjectName(QStringLiteral("actioncopy"));
        actionpaste = new QAction(MainWindow);
        actionpaste->setObjectName(QStringLiteral("actionpaste"));
        actioncut = new QAction(MainWindow);
        actioncut->setObjectName(QStringLiteral("actioncut"));
        actionUTF_8 = new QAction(MainWindow);
        actionUTF_8->setObjectName(QStringLiteral("actionUTF_8"));
        actionGBK = new QAction(MainWindow);
        actionGBK->setObjectName(QStringLiteral("actionGBK"));
        actioncomplie = new QAction(MainWindow);
        actioncomplie->setObjectName(QStringLiteral("actioncomplie"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 581, 21));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 30, 981, 611));
        textEdit->setLayoutDirection(Qt::LeftToRight);
        textEdit->setFrameShape(QFrame::Box);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setLineWidth(1);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 980, 23));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QStringLiteral("menufile"));
        menuedit = new QMenu(menuBar);
        menuedit->setObjectName(QStringLiteral("menuedit"));
        menubuild = new QMenu(menuBar);
        menubuild->setObjectName(QStringLiteral("menubuild"));
        menucode = new QMenu(menuBar);
        menucode->setObjectName(QStringLiteral("menucode"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "IED", nullptr));
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
