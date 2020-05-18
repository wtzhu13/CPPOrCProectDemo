#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "all";
    model = new QSqlTableModel(this);
    model->setTable("user_info");   // 设置查询表
}

Widget::~Widget()
{
    delete ui;
    delete model;
    delete roomModel;

}

/************************************************
* 函数名：Widget::on_pushButton_clicked()
* 参数：无
* 返回值：无
* 描述：查询用户信息按钮
************************************************/
void Widget::on_pushButton_clicked()
{
    qDebug() << "查询";

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    // model->removeColumn(0); //不显示id属性列,如果这时添加记录，则该属性的值添加不上
    ui->tableView->setModel(model);

    QSqlQuery query;

    query.exec("select * from user_info");
    while(query.next()){
        qDebug() << query.value(0).toInt() << query.value(1).toString() << query.value(2).toString() << query.value(3).toString();
    }

}

/************************************************
* 函数名：Widget::on_pushButton_roomInfo_clicked()
* 参数：无
* 返回值：无
* 描述：查询机房信息
************************************************/
void Widget::on_pushButton_roomInfo_clicked()
{
    roomModel = new QSqlTableModel(this);
    roomModel->setTable("room_info");   // 设置查询表
    roomModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    roomModel->select();
    // model->removeColumn(0); //不显示id属性列,如果这时添加记录，则该属性的值添加不上
    ui->tableView->setModel(roomModel);

    QSqlQuery query;

    query.exec("select * from room_info");
    while(query.next()){
        qDebug() << "机房：" << query.value(0).toInt() << "最大容量：" << query.value(1).toInt();
    }

}

/************************************************
* 函数名：Widget::on_pushButton_addUser_clicked()
* 参数：无
* 返回值：无
* 描述：添加用户
************************************************/
void Widget::on_pushButton_addUser_clicked()
{
    // 获得表的行数
    int rowNum = model->rowCount();
    // 添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),rowNum+1);

}

/************************************************
* 函数名：Widget::on_pushButton_delUser_clicked()
* 参数：无
* 返回值：无
* 描述：删除用户
************************************************/
void Widget::on_pushButton_delUser_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();
    // 删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
    tr("你确定删除当前行吗？ "),QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        // 如果不删除， 则撤销
        model->revertAll();
    }
    else
    {
        // 否则提交， 在数据库中删除该行
        model->submitAll();
    }
}

/************************************************
* 函数名：Widget::on_pushButton_clearOrder_clicked()
* 参数：无
* 返回值：无
* 描述：清除预约信息
************************************************/
void Widget::on_pushButton_clearOrder_clicked()
{

}

/************************************************
* 函数名：Widget::on_pushButton_modifyUserInfo_clicked()
* 参数：无
* 返回值：无
* 描述：修改用户信息，添加和删除也得点击
************************************************/
void Widget::on_pushButton_modifyUserInfo_clicked()
{
    qDebug() << "修改";
    model->database().transaction(); //开始事务操作
    if (model->submitAll())
    {
       qDebug() << "修改ok";
       model->database().commit(); //提交
    }
    else
    {
       model->database().rollback(); //回滚
       QMessageBox::warning(this, tr("tableModel"),
       tr("数据库错误: %1").arg(model->lastError().text()));
    }
}
