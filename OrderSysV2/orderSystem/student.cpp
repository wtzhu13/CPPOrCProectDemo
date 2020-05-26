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
            margin[orderTimeIndex][orderRoomIndex]--;
            // 将机房余量数据写入数据库
            QSqlQuery queryRoomInfo;
            QString queryStr = QString("update room_info set room_margin_am = %1, "
                                       "room_margin_pm = %2 where room_id = %3")
                               .arg(margin[0][orderRoomIndex]).arg(margin[1][orderRoomIndex]).arg(orderRoomIndex+1);
            qDebug() << queryStr;
            bool roomFlag = queryRoomInfo.exec(queryStr);
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
            on_pushButton_checkSelfOrder_clicked();
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
    // 获取选中行的数据
    int curRow = ui->tableView->currentIndex().row();
    QAbstractItemModel *model = ui->tableView->model ();
    QModelIndex index = model->index(curRow,1);
    QString user_id = model->data(index).toString();
    index = model->index(curRow,2);
    QString order_date = model->data(index).toString();
    index = model->index(curRow,3);
    QString order_time = model->data(index).toString();
    index = model->index(curRow,4);
    QString order_room = model->data(index).toString();
    qDebug() << user_id << order_date << order_time << order_room;

    // 如果ID不是当前用户的则表明实在查看所有预约时选择取消，且选中的是别人的数据
    if(user_id != userID){
        QMessageBox::information(NULL, "Title", "只能取消自己的预约信息！");
        return;
    }

    // 将获取行的内容装换为id便于后续操作
    int date_id = getID(QString("select date_id from date_info where date_str = '%1'").arg(order_date));
    int time_id = getID(QString("select time_id from time_info where time_str = '%1'").arg(order_time));
    int room_id = getID(QString("select room_id from room_info where room_name = '%1'").arg(order_room));
    qDebug() << date_id << time_id << room_id;

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
        QString queryStr = QString("delete from order_info where user_id = '%1' "
                                   "and order_date = %2 "
                                   "and order_time = %3 "
                                   "and order_room = %4")
                .arg(userID).arg(date_id).arg(time_id).arg(room_id);
        qDebug() << queryStr;
        query.exec(queryStr);

        // 机房对应的余量增加
        margin[time_id-1][room_id-1]++;
        // 将机房余量数据写入数据库
        QSqlQuery queryRoomInfo;
        QString queryStrRoomInfo = QString("update room_info set room_margin_am = %1, "
                                   "room_margin_pm = %2 where room_id = %3")
                           .arg(margin[0][room_id-1]).arg(margin[1][room_id-1]).arg(room_id);
        qDebug() << queryStrRoomInfo;
        bool roomFlag = queryRoomInfo.exec(queryStrRoomInfo);
        if(roomFlag){
            qDebug() << "OK";
        }
        else {
            qDebug() << "数据库错误";
        }
        getRoomInfo();

        // 更新一下显示
        on_pushButton_checkSelfOrder_clicked();

        // 取消的记录记录到本地日志
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
        QString logInfoStr = current_date + "," + userID + "," + userName + "," + order_date + ","
                + order_time +  "," +  order_room +  "," +  QString("取消") + "\n";
        qDebug() << logInfoStr;
        GlobalFunc::saveLog(LOGFILEPATH, logInfoStr);
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
        roomMarginAM = query.value(3).toInt();
        roomMarginPM = query.value(4).toInt();
        // 将数据放到表格中
        ui->tableWidget_roomMargin->setItem(row, 0, new QTableWidgetItem(QString::number(roomID, 10)));
        ui->tableWidget_roomMargin->setItem(row, 1, new QTableWidgetItem(roomStr));
        ui->tableWidget_roomMargin->setItem(row, 2, new QTableWidgetItem(QString::number(roomMarginAM, 10)));
        ui->tableWidget_roomMargin->setItem(row, 3, new QTableWidgetItem(QString::number(roomMarginPM, 10)));
//        qDebug() << roomID;
//        qDebug() << roomStr;
//        qDebug() << roomMargin;
        margin[0][row] = roomMarginAM;
        margin[1][row] = roomMarginPM;
        row++;
    }
    // 显示表格内容
    ui->tableWidget_roomMargin->show();
    qDebug() << margin[0][0] << margin[0][1] << margin[0][2]<< margin[1][0] << margin[1][1] << margin[1][2];
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

/************************************************
* 函数名：int Student::getID(QString str)
* 参数：无
* 返回值：ID
* 描述：获取数据对应的ID
************************************************/
int Student::getID(QString str)
{
    QSqlQuery queryID;
    queryID.exec(str);
    queryID.next();
    int date_id = queryID.value(0).toInt();
    return date_id;
}
