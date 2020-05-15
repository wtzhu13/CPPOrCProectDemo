#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QVariant>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{  
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("phonenum");
    model->select();
//    model->removeColumn(0); //不显示id属性列,如果这时添加记录，则该属性的值添加不上
    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}


// 查询按钮
void MainWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    qDebug() << name;
    if(name.length())
    {
        //根据姓名进行筛选， 一定要使用单引号
        model->setFilter(QString("name = '%1'").arg(name));
        model->select();

    }
    else
    {
        qDebug() << "查询全部";
        model->setTable("phoneNum");
        model->select();
//        QMessageBox::warning(this, tr("Warning"),tr("不提供姓名默认为全部查询") );
    }
}

// 修改按钮
void MainWindow::on_pushButton_2_clicked()
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

// 添加按钮
void MainWindow::on_pushButton_4_clicked()
{
    // 获得表的行数
    int rowNum = model->rowCount();
    // 添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),rowNum+1);
}

// 删除按钮
void MainWindow::on_pushButton_3_clicked()
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
