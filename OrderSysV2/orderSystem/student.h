/******************************************************************************

  Copyright (C), 2020, Fred

 ******************************************************************************
  File Name     : student.h
  Version       : v1.0
  Author        : wtzhu_13/Fred
  Created       : 2020/05
  Description   : this file was private for orderSystem
  History       :
  1.Date        :
    Author      :
    Modification: Created file
******************************************************************************/
#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
#include <QSqlQuery>
#include <QTableWidget>
#include <QtWidgets/QMessageBox>
#include <fstream>
#include <QDateTime>
#include <QSqlRelationalTableModel>
#include "global.h"

namespace Ui {
class Student;
}

class Student : public QWidget
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);
    ~Student();

private slots:
    void on_pushButton_applyOrder_clicked();

    void on_pushButton_checkSelfOrder_clicked();

    void on_pushButton_checkAllOrder_clicked();

    void on_pushButton_cancleOrder_clicked();

    void on_comboBox_orderDate_currentIndexChanged(int index);

    void on_comboBox_orderTime_currentIndexChanged(int index);

    void on_comboBox_orderRoom_currentIndexChanged(int index);

    void getRoomInfo();

    void on_pushButton_applyOrder_checkMargin_clicked();

private:
    Ui::Student *ui;
    int orderDateIndex = 0;
    QString orderDate = "周一";
    int orderTimeIndex = 0;
    QString orderTime = "上午";
    int orderRoomIndex = 0;
    QString orderRoom = "1号机房";
    int roomID;
    QString roomStr;
    int roomMargin;
    int roomMaxNum;
    int margin[3];
};

#endif // STUDENT_H
