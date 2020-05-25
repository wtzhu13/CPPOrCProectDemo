/******************************************************************************

  Copyright (C), 2020, Fred

 ******************************************************************************
  File Name     : widget.h
  Version       : v1.0
  Author        : wtzhu_13/Fred
  Created       : 2020/05
  Description   : this file was private for orderSystem
  History       :
  1.Date        :
    Author      :
    Modification: Created file
******************************************************************************/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QSqlTableModel>
#include <QCryptographicHash>
#include "global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_roomInfo_clicked();

    void on_pushButton_addUser_clicked();

    void on_pushButton_delUser_clicked();

    void on_pushButton_clearOrder_clicked();

    void on_pushButton_modifyUserInfo_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Widget *ui;
    QSqlTableModel *model;
    QSqlTableModel *roomModel;
    QSqlTableModel *orderModel;
    QString identity = "student";
    int identityID = 0;
};
#endif // WIDGET_H
