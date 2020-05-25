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
//    qDebug() << userName;
//    qDebug() << userID;
//    qDebug() << orderDate;
//    qDebug() << orderTime;
//    qDebug() << orderRoom;
//    qDebug() << orderDateIndex;
//    qDebug() << orderTimeIndex;
//    qDebug() << orderRoomIndex;

    QSqlQuery query;

    // 检查该事件段是否已经有预约
    QString queryStr = QString("select order_id from order_info where "
                         "user_id = '%1' and order_date = %2 and order_time = %3 and order_room = %4")
                 .arg(userID).arg(orderDateIndex+1).arg(orderTimeIndex+1).arg(orderRoomIndex+1);
    qDebug() << queryStr;
    query.exec(queryStr);
    query.next();
    if(query.value(0).toString() != ""){
        // 不为空则说明在预约数据库中有数据，那么同一时间段就无法再次预约
        QMessageBox::information(NULL, "Title", "对不起，您无法预约该时间段！");
    }
    else {
        // 为空则可以预约，将预约信息添加到数据库
        bool exec_flag = query.exec(QString("insert into order_info "
                                            "(user_id,order_date, order_time, order_room, state_id) "
                                            "values(%1, %2, %3, %4, %5)")
                                    .arg(userID).arg(orderDateIndex+1).arg(orderTimeIndex+1).arg(orderRoomIndex+1).arg(1));
        if(exec_flag){
            qDebug() << "添加成功";
            // 预约成功则需要把机房余量减掉一个
            margin[orderRoomIndex]--;
            // 将机房余量数据写入数据库
            QSqlQuery queryRoomInfo;
            bool roomFlag = queryRoomInfo.exec(QString("update room_info set room_margin = %1 where room_id = %2").arg(margin[orderRoomIndex]).arg(orderRoomIndex+1));
            if(roomFlag){
                qDebug() << "OK";
            }
            else {
                qDebug() << "数据库错误";
            }
            getRoomInfo();
            // 更新界面表格数据
            QMessageBox::information(NULL, "Title", "预约成功！");

//            Global::saveLog();
        }
        else {
            qDebug() << "添加失败";
            QMessageBox::information(NULL, "Title", "数据库错误！");
        }
    }
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
        // 从数据库获取机房数据
        roomID = query.value(0).toInt();
        roomStr = query.value(1).toString();
        roomMaxNum = query.value(2).toInt();
        roomMargin = query.value(3).toInt();
        // 将数据放到表格中
        ui->tableWidget_roomMargin->setItem(row, 0, new QTableWidgetItem(QString::number(roomID, 10)));
        ui->tableWidget_roomMargin->setItem(row, 1, new QTableWidgetItem(roomStr));
        ui->tableWidget_roomMargin->setItem(row, 2, new QTableWidgetItem(QString::number(roomMargin, 10)));
//        qDebug() << roomID;
//        qDebug() << roomStr;
//        qDebug() << roomMargin;
        margin[row] = roomMargin;
        row++;
    }
    // 显示表格内容
    ui->tableWidget_roomMargin->show();
    qDebug() << margin[0] << margin[1] << margin[2];
}

/************************************************
* 函数名：Student::on_pushButton_applyOrder_checkMargin_clicked()
* 参数：无
* 返回值：无
* 描述：获取机房余量信息
************************************************/
void Student::on_pushButton_applyOrder_checkMargin_clicked()
{
    getRoomInfo();
}
