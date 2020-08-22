/*******************************************************************************
 *  All rights reserved, Copyright (C) wtzhu
 * -----------------------------------------------------------------------------
 * [File Name]: 			widget.h
 * [Description]: 			HeaderFile of widget.cpp
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
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QSerialPort *serialPort;

private slots:
    void on_pushButtonOpen_clicked();

    void on_pushButtonClose_clicked();

    void on_pushButtonSend_clicked();

    void on_pushButtonClear_clicked();

    void serialPortReadyRead_Slot();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
