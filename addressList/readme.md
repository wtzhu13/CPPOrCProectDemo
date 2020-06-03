# QT手把手打造通讯录

## 功能及界面介绍

![](..\configImages\addrList\1591184617(1).png)

- 打开通讯录默认小时所有人的信息。
- 通过输入姓名可以查询指定人的信息。
- 点击添加表格会自动生成一行，填写好后点击修改即可完成添加。
- 直接在已有内容上修改后点击修改即可完成修改。
- 选中一行后点击删除就可以删除该条信息。

## 功能逻辑实现

功能的实现都是用`QSqlTableModel`通过QT的API操作数据库，避免SQL语句，共能很简单注释也很清楚，就不坐更多解释，有不清楚的可以留言，我有比较简单的资料可以查看。

### 1. 连接数据库

```C++
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("addresslist");       //这里输入你的数据库名
    db.setUserName("root");
    db.setPassword("123456");   //这里输入你的密码
    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("无法打开数据库"), "无法创建数据库连接！ ", QMessageBox::Cancel);
        return false;
    }
     QSqlQuery query(db);
    // 使数据库支持中文
     query.exec("SET NAMES 'Latin1'");
     return true;
}
```

创建一个连接数据可的函数，设置好数据库IP，用户名，密码及需要操作的库名即可。

如果没有连接上课已搜索QT连接数据的相关内容，我安装了一个mysql的连接器，并在主函数汇总用一下代码启动。能直接连上的就不用多此一举。

```c++
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));
    QProcess process;
    process.start("C:\\mysql\\bin\\mysqld.exe");
    if(!createConnection()) { return 1;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
```

### 2. 查询

```C++
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
    }
}
```

### 3.修改

```c++
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
```

### 4.添加

```c++
// 添加按钮
void MainWindow::on_pushButton_4_clicked()
{
    // 获得表的行数
    int rowNum = model->rowCount();
    // 添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),rowNum+1);
}
```

### 5.删除

```c++
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
```

