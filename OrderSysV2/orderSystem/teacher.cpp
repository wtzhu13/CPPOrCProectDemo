#include "teacher.h"
#include "ui_teacher.h"

Teacher::Teacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("欢迎 %1 使用预约系统").arg(userName));
}

Teacher::~Teacher()
{
    delete ui;
}

/************************************************
* 函数名：Teacher::on_pushButton_lookAllOrder_clicked()
* 参数：无
* 返回值：无
* 描述：查看所有人预约
************************************************/
void Teacher::on_pushButton_lookAllOrder_clicked()
{
    showOrderInfo(0);

}

/************************************************
* 函数名：Teacher::on_pushButton_checkOrder_clicked()
* 参数：无
* 返回值：无
* 描述：查看审核预约
************************************************/
void Teacher::on_pushButton_checkOrder_clicked()
{
    // 显示待审核的信息
    showOrderInfo(1);

}

/************************************************
* 函数名：void Teacher::on_pushButton_clicked()
* 参数：无
* 返回值：无
* 描述：审核预约
************************************************/
void Teacher::on_pushButton_clicked()
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
    index = model->index(curRow,5);
    QString order_state = model->data(index).toString();
    index = model->index(curRow,0);
    int order_id = model->data(index).toInt();

    int date_id = getID(QString("select date_id from date_info where date_str = '%1'").arg(order_date));
    int time_id = getID(QString("select time_id from time_info where time_str = '%1'").arg(order_time));
    int room_id = getID(QString("select room_id from room_info where room_name = '%1'").arg(order_room));

    qDebug() << order_id << user_id << date_id << time_id << room_id <<order_state;

    if(order_state != "待审核"){
        QMessageBox::information(NULL, "Title", "该记录非待审核记录！");
        return;
    }
    int ok = QMessageBox::information(this,tr("通过申请？"),
    tr("通过申请？ "),QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        qDebug() << "不通过";
        int stateID = 3;
        updateOrderState(order_id, stateID);
        // 房间余量要更新
        updateRoomMarginInfo(date_id, time_id, room_id);
    }
    else
    {
        qDebug() << "通过";
        int stateID = 2;
        updateOrderState(order_id, stateID);
    }
}

/************************************************
* 函数名：Teacher::updateRoomMarginInfo()
* 参数：无
* 返回值：无
* 描述：更新机房余量信息
************************************************/
void Teacher::updateRoomMarginInfo(int date_id, int time_id, int room_id)
{

    QString tableName;
    switch (date_id) {
    case 1:
        tableName = "monday_room_margin";
        break;
    case 2:
        tableName = "tuesday_room_margin";
        break;
    case 3:
        tableName = "wednesday_room_margin";
        break;
    case 4:
        tableName = "thursday_room_margin";
        break;
    case 5:
        tableName = "friday_room_margin";
        break;
    }
    QString timeName;
    switch (time_id) {
    case 1:
        timeName = "room_margin_am";
        break;
    case 2:
        timeName = "room_margin_pm";
        break;
    }
    QSqlQuery queryMargin;
    queryMargin.exec(QString("select %1 from %2 where room_id = %3").arg(timeName).arg(tableName).arg(room_id));
    queryMargin.next();
    int orgMargin = queryMargin.value(0).toInt();
    qDebug() << orgMargin;
    orgMargin++;
    queryMargin.exec(QString("update %1 set %2 = %3 where room_id = %4").arg(tableName).arg(timeName).arg(orgMargin).arg(room_id));
}

/************************************************
* 函数名：Teacher::on_pushButton_checkOrder_clicked()
* 参数：无
* 返回值：无
* 描述：更新数据库中预约状态
************************************************/
void Teacher::updateOrderState(int order_id, int stateID)
{
    QSqlQuery query;
    QString queryStr = QString("update order_info set state_id = %1 where order_id = %2 ")
            .arg(stateID).arg(order_id);
    qDebug() << queryStr;
    query.exec(queryStr);
    on_pushButton_checkOrder_clicked();
}

/************************************************
* 函数名：int Student::getID(QString str)
* 参数：无
* 返回值：ID
* 描述：获取数据对应的ID
************************************************/
int Teacher::getID(QString str)
{
    QSqlQuery queryID;
    queryID.exec(str);
    queryID.next();
    int date_id = queryID.value(0).toInt();
    return date_id;
}

/************************************************
* 函数名：Teacher::on_pushButton_checkOrder_clicked()
* 参数：无
* 返回值：无
* 描述：审核预约
************************************************/
void Teacher::showOrderInfo(int lookFlag)
{
    QSqlRelationalTableModel *orderModel;
    orderModel = new QSqlRelationalTableModel(this);
    orderModel->setEditStrategy(QSqlTableModel::OnFieldChange);  // 属性变化时写入数据库
    // 设置操作的表
    orderModel->setTable("order_info");
    // 设置显示外键对应的内容
    orderModel->setRelation(2, QSqlRelation("date_info", "date_id", "date_str"));
    orderModel->setRelation(3, QSqlRelation("time_info", "time_id", "time_str"));
    orderModel->setRelation(4, QSqlRelation("room_info", "room_id", "room_name"));
    orderModel->setRelation(5, QSqlRelation("state_info", "state_id", "state_str"));

    // 设置表字段的显示
    orderModel->setHeaderData(0, Qt::Horizontal, QObject::tr("预约ID"));
    orderModel->setHeaderData(1, Qt::Horizontal, QObject::tr("用户ID"));
    orderModel->setHeaderData(2, Qt::Horizontal, QObject::tr("日期（工作日）"));
    orderModel->setHeaderData(3, Qt::Horizontal, QObject::tr("时间"));
    orderModel->setHeaderData(4, Qt::Horizontal, QObject::tr("机房"));
    orderModel->setHeaderData(5, Qt::Horizontal, QObject::tr("状态"));
    if(lookFlag != 0){
        // 添加筛选的内容relTblAl_5表示第五个关联
        orderModel->setFilter("relTblAl_5.state_id = 1");
    }
    orderModel->select();
    ui->tableView->setModel(orderModel);
}


