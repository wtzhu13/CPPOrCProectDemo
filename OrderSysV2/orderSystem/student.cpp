#include "student.h"
#include "ui_student.h"

Student::Student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("欢迎 %1 使用预约系统").arg(userName));
    getRoomInfo();
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
    qDebug() << userName;
    qDebug() << userID;
    qDebug() << orderDate;
    qDebug() << orderTime;
    qDebug() << orderRoom;
    qDebug() << orderDateIndex;
    qDebug() << orderTimeIndex;
    qDebug() << orderRoomIndex;
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

/************************************************
* 函数名：Student::on_comboBox_orderDate_currentIndexChanged(int index)
* 参数：无
* 返回值：无
* 描述：选择预约日期
************************************************/
void Student::on_comboBox_orderDate_currentIndexChanged(int index)
{
    index = ui->comboBox_orderDate->currentIndex();
    orderDateIndex = index;
    orderDate = ui->comboBox_orderDate->currentText();
}

/************************************************
* 函数名：Student::on_comboBox_orderTime_currentIndexChanged(int index)
* 参数：无
* 返回值：无
* 描述：选择预约时间
************************************************/
void Student::on_comboBox_orderTime_currentIndexChanged(int index)
{
    index = ui->comboBox_orderTime->currentIndex();
    orderTimeIndex = index;
    orderTime = ui->comboBox_orderTime->currentText();

}

/************************************************
* 函数名：Student::on_comboBox_orderRoom_currentIndexChanged(int index)
* 参数：无
* 返回值：无
* 描述：选择预约机房
************************************************/
void Student::on_comboBox_orderRoom_currentIndexChanged(int index)
{
    index = ui->comboBox_orderRoom->currentIndex();
    orderRoomIndex = index;
    orderRoom = ui->comboBox_orderRoom->currentText();

}

/************************************************
* 函数名：Student::getRoomInfo()
* 参数：无
* 返回值：无
* 描述：获取机房信息
************************************************/
void Student::getRoomInfo()
{
    int row = 0;
    QSqlQuery query;
    bool flag = query.exec("select * from room_info");
    if(flag){
        qDebug() << "OK";
    }
    while (query.next()) {
        qDebug() << "NO";
        roomID = query.value(0).toInt();
        roomStr = query.value(1).toString();
        roomMargin = query.value(2).toInt();
        ui->tableWidget_roomMargin->setItem(row, 0, new QTableWidgetItem(QString::number(roomID, 10)));
        ui->tableWidget_roomMargin->setItem(row, 1, new QTableWidgetItem(roomStr));
        ui->tableWidget_roomMargin->setItem(row, 2, new QTableWidgetItem(QString::number(roomMargin, 10)));
        qDebug() << roomID;
        qDebug() << roomStr;
        qDebug() << roomMargin;
        row++;
    }
    ui->tableWidget_roomMargin->show();
    qDebug() << "roomMagin";
}
