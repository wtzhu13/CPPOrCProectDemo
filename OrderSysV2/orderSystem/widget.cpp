#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("user_info");
    model->select();
    // model->removeColumn(0); //不显示id属性列,如果这时添加记录，则该属性的值添加不上
    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
    delete model;
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

    qDebug()<<"连接成功"<<endl;
    QSqlQuery query;

    query.exec("select * from user_info");
    while(query.next()){
        qDebug() << query.value(0).toInt() << query.value(1).toString() << query.value(2).toString() << query.value(3).toInt();
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
    QSqlQuery query;

    query.exec("select * from room_info");
    while(query.next()){
        qDebug() << "机房：" << query.value(0).toInt() << "最大容量：" << query.value(1).toInt();
    }
}
