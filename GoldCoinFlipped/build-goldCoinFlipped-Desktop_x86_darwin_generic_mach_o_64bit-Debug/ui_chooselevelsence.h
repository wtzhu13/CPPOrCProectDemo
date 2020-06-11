/********************************************************************************
** Form generated from reading UI file 'chooselevelsence.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVELSENCE_H
#define UI_CHOOSELEVELSENCE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLevelSence
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *ChooseLevelSence)
    {
        if (ChooseLevelSence->objectName().isEmpty())
            ChooseLevelSence->setObjectName(QString::fromUtf8("ChooseLevelSence"));
        ChooseLevelSence->resize(320, 588);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChooseLevelSence->sizePolicy().hasHeightForWidth());
        ChooseLevelSence->setSizePolicy(sizePolicy);
        ChooseLevelSence->setMinimumSize(QSize(320, 588));
        ChooseLevelSence->setMaximumSize(QSize(320, 588));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/src/Coin0001.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChooseLevelSence->setWindowIcon(icon);
        actionquit = new QAction(ChooseLevelSence);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralwidget = new QWidget(ChooseLevelSence);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("border-image: url(:/src/OtherSceneBg.png);"));
        ChooseLevelSence->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChooseLevelSence);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        ChooseLevelSence->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(ChooseLevelSence);

        QMetaObject::connectSlotsByName(ChooseLevelSence);
    } // setupUi

    void retranslateUi(QMainWindow *ChooseLevelSence)
    {
        ChooseLevelSence->setWindowTitle(QApplication::translate("ChooseLevelSence", "\351\200\211\346\213\251\345\205\263\345\215\241", nullptr));
        actionquit->setText(QApplication::translate("ChooseLevelSence", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QApplication::translate("ChooseLevelSence", "\346\216\247\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseLevelSence: public Ui_ChooseLevelSence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVELSENCE_H
