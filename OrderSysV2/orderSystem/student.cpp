/******************************************************************************

  Copyright (C), 2020, Fred

 ******************************************************************************
  File Name     : student.cpp
  Version       : v1.0
  Author        : wtzhu_13/Fred
  Created       : 2020/05
  Description   : this file was private for orderSystem
  History       :
  1.Date        :
    Author      :
    Modification: Created file
******************************************************************************/
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

    // 获取系统时间，存日志的时候需要
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    QString orderInfoStr = current_date + "," + userID + "," + userName + "," + orderDate + ","
            + orderTime +  "," +  orderRoom +  "," +  QString("待审核") + "\n";
    qDebug() << orderInfoStr;
    QSqlQuery query;

    // 检查该事件段是否已经有预约
    QString queryStr = QString("select order_id from order_info where "
                         "user_id = '%1' and order_date = %2 and order_time = %3")
                 .arg(userID).arg(orderDateIndex+1).arg(orderTimeIndex+1);
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
            // 把操作存放到日志文件中
            GlobalFunc::saveLog(LOGFILEPATH, orderInfoStr);
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
    QSqlRelationalTableModel *selfOrderModel;
    selfOrderModel = new QSqlRelationalTableModel(this);
    selfOrderModel->setEditStrategy(QSqlTableModel::OnFieldChange);  // 属性变化时写入数据库
    // 设置操作的表
    selfOrderModel->setTable("order_info");
    // 设置显示外键对应的内容
    selfOrderModel->setRelation(2, QSqlRelation("date_info", "date_id", "date_str"));
    selfOrderModel->setRelation(3, QSqlRelation("time_info", "time_id", "time_str"));
    selfOrderModel->setRelation(4, QSqlRelation("room_info", "room_id", "room_name"));
    selfOrderModel->setRelation(5, QSqlRelation("state_info", "state_id", "state_str"));

    // 设置表字段的显示
    selfOrderModel->setHeaderData(0, Qt::Horizontal, QObject::tr("预约ID"));
    selfOrderModel->setHeaderData(1, Qt::Horizontal, QObject::tr("用户ID"));
    selfOrderModel->setHeaderData(2, Qt::Horizontal, QObject::tr("日期（工作日）"));
    selfOrderModel->setHeaderData(3, Qt::Horizontal, QObject::tr("时间"));
    selfOrderModel->setHeaderData(4, Qt::Horizontal, QObject::tr("机房"));
    selfOrderModel->setHeaderData(5, Qt::Horizontal, QObject::tr("状态"));

    // 添加筛选的内容
    selfOrderModel->setFilter(QObject::tr("user_id = %1").arg(userID));

    selfOrderModel->select();
    ui->tableView->setModel(selfOrderModel);
}

/************************************************
* 函数名：Student::on_pushButton_checkAllOrder_clicked()
* 参数：无
* 返回值：无
* 描述：查看所有人的预约
************************************************/
void Student::on_pushButton_checkAllOrder_clicked()
{
    QSqlRelationalTableModel *allOrderModel;
    allOrderModel = new QSqlRelationalTableModel(this);
    allOrderModel->setEditStrategy(QSqlTableModel::OnFieldChange);  // 属性变化时写入数据库
    // 设置操作的表
    allOrderModel->setTable("order_info");
    // 设置显示外键对应的内容
    allOrderModel->setRelation(2, QSqlRelation("date_info", "date_id", "date_str"));
    allOrderModel->setRelation(3, QSqlRelation("time_info", "time_id", "time_str"));
    allOrderModel->setRelation(4, QSqlRelation("room_info", "room_id", "room_name"));
    allOrderModel->setRelation(5, QSqlRelation("state_info", "state_id", "state_str"));

    // 设置表字段的显示
    allOrderModel->setHeaderData(0, Qt::Horizontal, QObject::tr("预约ID"));
    allOrderModel->setHeaderData(1, Qt::Horizontal, QObject::tr("用户ID"));
    allOrderModel->setHeaderData(2, Qt::Horizontal, QObject::tr("日期（工作日）"));
    allOrderModel->setHeaderData(3, Qt::Horizontal, QObject::tr("时间"));
    allOrderModel->setHeaderData(4, Qt::Horizontal, QObject::tr("机房"));
    allOrderModel->setHeaderData(5, Qt::Horizontal, QObject::tr("状态"));
    // 添加筛选的内容
    allOrderModel->select();
    ui->tableView->setModel(allOrderModel);
}

/************************************************
* 函数名：Student::on_pushButton_cancleOrder_clicked()
* 参数：无
* 返回值：无
* 描述：取消预约
************************************************/
void Student::on_pushButton_cancleOrder_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    QAbstractItemModel *model = ui->tableView->model ();
    QModelIndex index = model->index(curRow,1);
    QString data = model->data(index).toString();
    qDebug() << data;

    // 如果ID不是当前用户的则表明实在查看所有预约时选择取消，且选中的是别人的数据
    if(data != userID){
        QMessageBox::information(NULL, "Title", "只能取消自己的预约信息！");
        return;
    }

    int ok = QMessageBox::warning(this,tr("确认取消该预约？"),
    tr("确认取消该预约？ "),QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        // 如果不删除， 则撤销
        return;
    }
    else
    {
        // 否则提交， 在数据库中删除该行
        QSqlQuery query;
        QString queryStr = QString("delete from order_info where user_id = '%1' and order_date = %2"
                                   "and order_time = %3 and order_room = %4").arg(userID).arg(orderDateIndex + 1)
                .arg(orderTimeIndex + 1).arg(orderRoomIndex + 1);
        qDebug() << queryStr;
        query.exec(queryStr);
    }

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
