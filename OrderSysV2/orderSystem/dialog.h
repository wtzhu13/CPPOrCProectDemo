/******************************************************************************

  Copyright (C), 2020, Fred

 ******************************************************************************
  File Name     : dialog.h
  Version       : v1.0
  Author        : wtzhu_13/Fred
  Created       : 2020/05
  Description   : this file was private for orderSystem
  History       :
  1.Date        :
    Author      :
    Modification: Created file
******************************************************************************/
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets/QMessageBox>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QCryptographicHash>
#include "global.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
