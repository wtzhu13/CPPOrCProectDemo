/*******************************************************************************
 *  All rights reserved, Copyright (C) wtzhu
 * -----------------------------------------------------------------------------
 * [File Name]: 			main.cpp
 * [Description]: 			Main file of serialAssistant
 *
 * [Author]: 				Fred
 * [Date Of Creation]:      2020/08/22
 * [e-mail]:                wtzhu_13@163.com
 * [Note]:
 *
 * ------------------------------------------------------------------------------
 * Date					Author				Modifications
 * ------------------------------------------------------------------------------
 * 2020-08				Fred                Created
 *******************************************************************************/
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
