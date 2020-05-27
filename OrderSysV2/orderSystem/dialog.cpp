/******************************************************************************

  Copyright (C), 2020, Fred

 ******************************************************************************
  File Name     : dialog.cpp
  Version       : v1.0
  Author        : wtzhu_13/Fred
  Created       : 2020/05
  Description   : this file was private for orderSystem
  History       :
  1.Date        :
    Author      :
    Modification: Created file
******************************************************************************/
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    qDebug()<<"login 0";
}

Dialog::~Dialog()
{
    delete ui;
}

/************************************************
* 函数名：Widget::on_pushButton_clicked()
* 参数：无
* 返回值：无
* 描述：登录按钮槽函数
************************************************/
void Dialog::on_pushButton_clicked()
{
    qDebug()<<"login";

    QString userPWD;    // 对话框中的密码
    QString truePWD;    // 数据库中的密码
    QString identity;

    // 获取对话框中的密码
    userPWD = ui->lineEdit_2->text();
//    userPWD = "123456";

    // 从数据库中获取密码
    QSqlQuery query;
    query.prepare("select pwd,identity,name from user_info where user_id = ?");
    QString user_id = ui->lineEdit->text();
//    QString user_id = "101";
    userID = user_id;
    query.addBindValue(user_id);
    query.exec();
    query.next();
    truePWD = query.value(0).toString();
    identity = query.value(1).toString();

    QString user_name = query.value(2).toString();
    // 对密码进行MD5加密
    QString pwdMD5;
    QByteArray str;
    str = QCryptographicHash::hash(userPWD.toLatin1(), QCryptographicHash::Md5);
    pwdMD5.append(str.toHex());
//    qDebug() << pwdMD5;

    // 根据用户身份确认接下来打开的窗口
    if(identity == "student"){
        globalIndex = 0;
    }
    else if(identity == "teacher"){
        globalIndex = 1;
    }
    else {
        globalIndex = 2;
    }

    if(userPWD != NULL && truePWD == pwdMD5){
        qDebug() << "登录";
        userName = user_name;   // 如果登录成功，则赋给全局变量后面用
        accept();
    }
    else{
        QMessageBox::warning(this, "waring", "用户名或密码错误！", QMessageBox::Yes);
    }
}


