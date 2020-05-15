#include "dialog.h"
#include "ui_dialog.h"
#include <QtWidgets/QMessageBox>
#include <QDebug>

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
    if(ui->lineEdit->text() == "qt" && ui->lineEdit_2->text() == "123456"){
        qDebug() << "登录";
        accept();
    }
    else{
        QMessageBox::warning(this, "waring", "pwd err", QMessageBox::Yes);
    }
}
