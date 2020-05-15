#include "dialog.h"
#include "ui_dialog.h"
#include <QtWidgets/QMessageBox>
#include <QDebug>
#include <QString>
#include <QSqlQuery>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
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
    qDebug()<<"连接成功"<<endl;
    QSqlQuery query;
    QString userPWD;    // 对话框中的密码
    QString truePWD;    // 数据库中的密码

    // 获取对话框中的密码
    userPWD = ui->lineEdit_2->text();

    // 从数据库中获取密码
    query.prepare("select * from user_info where user_name = ?");
    QString user_name = ui->lineEdit->text();
    query.addBindValue(user_name);
    query.exec();
    query.next();
    truePWD = query.value(2).toString();
    if(userPWD != NULL && truePWD == userPWD){
        qDebug() << "登录";
        accept();
    }
    else{
        QMessageBox::warning(this, "waring", "用户名或密码错误！", QMessageBox::Yes);
    }
}
