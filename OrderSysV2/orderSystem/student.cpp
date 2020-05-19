#include "student.h"
#include "ui_student.h"

Student::Student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("欢迎 %1 使用预约系统").arg(userName));
}

Student::~Student()
{
    delete ui;
}

/************************************************
* 函数名：Student::on_pushButton_applyOrder_clicked()
* 参数：无
* 返回值：无
* 描述：申请预约
************************************************/
void Student::on_pushButton_applyOrder_clicked()
{

}

/************************************************
* 函数名：Student::on_pushButton_checkSelfOrder_clicked()
* 参数：无
* 返回值：无
* 描述：查看自己的预约
************************************************/
void Student::on_pushButton_checkSelfOrder_clicked()
{

}

/************************************************
* 函数名：Student::on_pushButton_checkAllOrder_clicked()
* 参数：无
* 返回值：无
* 描述：查看所有人的预约
************************************************/
void Student::on_pushButton_checkAllOrder_clicked()
{

}

/************************************************
* 函数名：Student::on_pushButton_cancleOrder_clicked()
* 参数：无
* 返回值：无
* 描述：取消预约
************************************************/
void Student::on_pushButton_cancleOrder_clicked()
{

}
