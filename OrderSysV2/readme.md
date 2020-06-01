# QT手把手打造预约系统——登录界面

## 效果展示

### 登录界面处事窗口

![](..\configImages\login_ui.png)

- 在用户ID处输入用户ID，没用选择用户名是因为可能存在同名学生，使用ID这种唯一标识更有区分性。
- 用户在密码区输入密码，且以密文形式展示，便于保密。
- 点击登录即可。



### 登录异常

![](..\configImages\login_err.png)

当用户名或者密码错误是，会有弹窗提示。



### 登录成功

当用户登录成功后调转到不同身份用户的界面。本项目有学生、教师和管理员三个身份，所以系统会根据登录人的ID自动跳转到指定的用户界面。



## 页面UI设计

本案例直接使用QT自带的拖拽的方式设计界面，具体用到的空间如下：

![](..\configImages\ui_design.png)

如图所以，将箭头左侧位置的空间拖到右侧区域并放置好位置即可，至于美观性这个有兴趣的可以后续研究。



## 登录代码实现

登录界面只有一个登录按钮，即点击登录按钮后做出相应的应答，所以直接在上图中选择登录按钮并右键转到槽即可直接生成槽函数，即登录按钮对应的逻辑处理。

具体的逻辑功能有一下几点：

- 从页面获取输入的用户ID和密码，并在数据库中查询相应的数据，如果数据完全和数据库一致，那么就完成登录，否则弹出提是框提示用户。
- 数据库中的密码是MD5加密算法加密过的，所以在和数据库进行比对之前也需要将页面获取的密码进行加密。
- 通过用户ID从数据库获取用户身份，以便登录成功跳转到指定页面。

具体代码如下：

```c++
/************************************************
* 函数名：Widget::on_pushButton_clicked()
* 参数：无
* 返回值：无
* 描述：登录按钮槽函数
************************************************/
void Dialog::on_pushButton_clicked()
{
    qDebug()<<"login";
    QString userPWD;    // 对话框中的密码
    QString truePWD;    // 数据库中的密码
    QString identity;

    // 获取对话框中的密码
    userPWD = ui->lineEdit_2->text();

    // 从数据库中获取密码
    QSqlQuery query;
    query.prepare("select pwd,identity,name from user_info where user_id = ?");
    QString user_id = ui->lineEdit->text();
    userID = user_id;
    query.addBindValue(user_id);
    query.exec();
    query.next();
    truePWD = query.value(0).toString();
    identity = query.value(1).toString();

    QString user_name = query.value(2).toString();
    // 对密码进行MD5加密
    QString pwdMD5;
    QByteArray str;
    str = QCryptographicHash::hash(userPWD.toLatin1(), QCryptographicHash::Md5);
    pwdMD5.append(str.toHex());

    // 根据用户身份确认接下来打开的窗口
    if(identity == "student"){
        globalIndex = 0;
    }
    else if(identity == "teacher"){
        globalIndex = 1;
    }
    else {
        globalIndex = 2;
    }

    if(userPWD != NULL && truePWD == pwdMD5){
        qDebug() << "登录";
        userName = user_name;   // 如果登录成功，则赋给全局变量后面用
        accept();
    }
    else{
        QMessageBox::warning(this, "waring", "用户名或密码错误！", QMessageBox::Yes);
    }
}
```

**需要注意的是：在这之前需要保证数据库连接正常，然后需要把代码中对应的表改成自己的表，不然运行结果就是一场的。**





# QT手把手打造预约系统——管理员

## 管理员界面介绍

![](..\configImages\adminUI.png)

- 点击查询用户会在框中显示用户信息。
- 修改用户信息直接在显示的表格中修改后点击该按钮即可。
- 删除用户，选中表格中的用户，点击即可删除。
- 查询机房信息，点击即可完成。
- 添加用户，先在左侧填写好相关信息，然后点击添加即可。
- 清空预约，点击即可完成清空，按照需求，管理员可以每周清空一次。



## 页面UI设计

![](..\configImages\adminUIDesign.png)

除了使用登录界面的几个控件外，本界面多了如图的两个控件，还是拖到指定位置即可。

## 功能逻辑实现

1. 查询用户，通过`QSqlTableModel`操作数据库，省去SQL语句。

   ```C++
   /************************************************
   * 函数名：Widget::on_pushButton_clicked()
   * 参数：无
   * 返回值：无
   * 描述：查询用户信息按钮
   ************************************************/
   void Widget::on_pushButton_clicked()
   {
       model = new QSqlTableModel(this);
       model->setTable("user_info");   // 设置查询表
       model->setEditStrategy(QSqlTableModel::OnManualSubmit);
       model->select();
       // model->removeColumn(0); //不显示id属性列,如果这时添加记录，则该属性的值添加不上
       ui->tableView->setModel(model);
   }
   ```

   - 首先创建一个连接，并制定需要操作的表。
   - 设置model的属性，并执行select()方法查询该表中全部类容。
   - 通过`ui->tableView->setModel(model);`方法直接显示表格中的类容。

2. 查看机房信息，同查询用户信息一样，使用`QSqlTableModel`来操作数据库。

   ```C++
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
       ui->tableView->setModel(roomModel);
   }
   ```

3. 添加用户，通过`QSqlQuery`来执行SQL语句操作数据库。

   ```C++
   /************************************************
   * 函数名：Widget::on_pushButton_addUser_clicked()
   * 参数：无
   * 返回值：无
   * 描述：添加用户
   ************************************************/
   void Widget::on_pushButton_addUser_clicked()
   {
       QString id = ui->lineEdit_id->text();
       QString name = ui->lineEdit_naem->text();
       QString pwd = ui->lineEdit_pwd->text();
   
       // 判断用户信息是否全
       if(id == "" || name == "" || pwd == ""){
           QMessageBox::information(NULL, "Title", "用户信息不全！");
           return;
       }
   
       // 判断用户ID的长度是否符合要求
       switch (identityID) {
           case 0:
               // 检查学生ID
               if(id.length() != 9){
                   QMessageBox::information(NULL, "Title", "用户ID错误！");
                   return;
               }
           break;
           case 1:
               // 检查教师ID
               if(id.length() != 3){
                   QMessageBox::information(NULL, "Title", "用户ID错误！");
                   return;
               }
           break;
           case 2:
               // 检查管理员ID
               if(id.length() != 1){
                   QMessageBox::information(NULL, "Title", "用户ID错误！");
                   return;
               }
           break;
           default:
           break;
       }
   
       if(pwd.length() != 6){
           QMessageBox::information(NULL, "Title", "请设置6位密码！");
           return;
       }
   
       qDebug() << id << name << pwd << identity;
   
       // MD5对密码进行加密
       QString pwdMD5;
       QByteArray str;
       str = QCryptographicHash::hash(pwd.toLatin1(), QCryptographicHash::Md5);
       pwdMD5.append(str.toHex());
   
       QString str1 = QString("insert into user_info values('%1', '%2', '%3', '%4')").arg(id)
               .arg(name).arg(pwdMD5).arg(identity);
       qDebug() << str1;
   
       // 判断用户名是否已经存在
       QSqlQuery query;
       query.exec(QString("select name from user_info where user_id = %1").arg(id));
       query.next();
       QString nameFlag = query.value(0).toString();
       if(nameFlag != ""){
           QMessageBox::information(NULL, "Title", "该用户已存在");
           qDebug() << "该用户已存在";
           return;
       }
       else{
           bool flag = query.exec(str1);
           if(flag){
               QMessageBox::information(NULL, "Title", "添加用户成功");
               ui->lineEdit_id->setText("");
               ui->lineEdit_naem->setText("");
               ui->lineEdit_pwd->setText("");
           }
           else{
               QMessageBox::information(NULL, "Title", "数据库发生错误");
           }
       }
   }
   ```

   - 从页面获取需要添加的用户的ID、姓名和密码。
   - 检查三份信息是否齐全，不全则提示用户补全。
   - 检查用户ID的长度，三种身份的ID长度不同，需要检查。
   - 检查密码长度，设置密码长度为6。
   - 对密码进行MD5加密。
   - 判断用户在数据库中是否已经存在，如果不存在则是新用户可以直接添加到数据库。

4. 删除用户

   ```C++
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
   ```

   - 获取选中的行。
   - 通过`model->removeRow(curRow)`删除选中的行。
   - 删除时通过弹出对话框提醒用户是否删除，如果删除就直接执行提交。

5. 清楚预约信息，通过`QSqlQuery`执行SQL语句删除预约信息。

   ```C++
   /************************************************
   * 函数名：Widget::on_pushButton_clearOrder_clicked()
   * 参数：无
   * 返回值：无
   * 描述：清除预约信息
   ************************************************/
   void Widget::on_pushButton_clearOrder_clicked()
   {
       QSqlQuery query;
       // 删除操作前给出提示信息，方便确认
       QMessageBox:: StandardButton result = QMessageBox::information(NULL, "Title", "确认清空预约记录？",
                                QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
       switch (result) {
           case QMessageBox::Yes:{
               qDebug()<<"Yes";
               query.exec("delete from order_info");
               QMessageBox::information(NULL, "Title", "已清空预约!");
               QSqlQuery queryRoom;
               queryRoom.exec("update room_info set room_margin = 20 where room_id = 1");
               queryRoom.exec("update room_info set room_margin = 50 where room_id = 2");
               queryRoom.exec("update room_info set room_margin = 100 where room_id = 3");
               break;
               }
           case QMessageBox::No:
               qDebug()<<"NO";
               break;
           default:
               break;
       }
   }
   ```

   

