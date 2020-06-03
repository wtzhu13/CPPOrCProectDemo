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

   

# QT手把手打造预约系统——学生用户

## 学生用户界面介绍

![](..\configImages\stuUI.png)

- 左上角显示机房的余量信息，默认周一，可以通过预约日期的通过自动调整。
- 右侧为预约提交区域，选择好相应的预约信息，点击申请即可完成预约。
- 下方显示预约信息，点击查看自己预约显示自己的预约信息，查看所有就会显示所有人的预约信息。
- 在自己的预约信息中选择一项后点击取消则出现如下图所示提示，点击确认后即完成取消。

![](..\configImages\cancleOrder.png)

## 页面UI设计



![](..\configImages\stuUIDesign.png)

- 将需要的控件拖到指定的位置调整好大小即可。
- 机房信息的表头可以双击TableWidget进行设置。

## 功能逻辑实现

1. 申请预约

   ```c++
   /************************************************
   * 函数名：Student::on_pushButton_applyOrder_clicked()
   * 参数：无
   * 返回值：无
   * 描述：申请预约
   ************************************************/
   void Student::on_pushButton_applyOrder_clicked()
   {
       // 获取系统时间，存日志的时候需要
       QDateTime current_date_time =QDateTime::currentDateTime();
       QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
       // 拼接日志信息
       QString orderInfoStr = current_date + "," + userID + "," + userName + "," + orderDate + ","
               + orderTime +  "," +  orderRoom +  "," +  QString("待审核") + "\n";
       qDebug() << orderInfoStr;
       QSqlQuery query;
   
       // 检查该时间段是否已经有预约
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
               margin[orderDateIndex][orderTimeIndex][orderRoomIndex]--;
               // 跟新数据库
               updateRoomInfo();
               // 提示信息
               QMessageBox::information(NULL, "Title", "预约成功！");
               // 把操作存放到日志文件中
               GlobalFunc::saveLog(LOGFILEPATH, orderInfoStr);
               // 显示一下自己的预约情况
               on_pushButton_checkSelfOrder_clicked();
           }
           else {
               qDebug() << "添加失败";
               QMessageBox::information(NULL, "Title", "数据库错误！");
           }
       }
   }
   ```

   - 获取系统时间并拼接成日志格式。
   - 通过`QSqlQuery`查询数据库检查相同时间段是否有预约。
   - 如果没有预约则可以将预约信息放进预约表，并将相应机房的相应时间的余量更新，最后将操作记录到日志。

2. 查看预约

   ```C++
   /************************************************
   * 函数名：Student::on_pushButton_checkSelfOrder_clicked()
   * 参数：无
   * 返回值：无
   * 描述：查看自己的预约
   ************************************************/
   void Student::on_pushButton_checkSelfOrder_clicked()
   {
       showOrderInfo(1);
   }
   
   /************************************************
   * 函数名：Student::on_pushButton_checkAllOrder_clicked()
   * 参数：无
   * 返回值：无
   * 描述：查看所有人的预约
   ************************************************/
   void Student::on_pushButton_checkAllOrder_clicked()
   {
       showOrderInfo(0);
   }
   
   /************************************************
   * 函数名：Student::showOrderInfo(int lookFlag)
   * 参数：无
   * 返回值：无
   * 描述：显示预约信息
   ************************************************/
   void Student::showOrderInfo(int lookFlag)
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
           orderModel->setFilter(QObject::tr("user_id = %1").arg(userID));
       }
       orderModel->select();
       ui->tableView->setModel(orderModel);
   }
   ```

   - 查看所有预约和查看自己的预约在逻辑上一致，只是查看自己的预约时多一条限定条件，所以将两个功能整合，通过标志位区分。
   - 通过`QSqlRelationalTableModel`来显示外键关联，这样更方面数据库的可视化。
   - `orderModel->setTable`设置需要操作的数据库。
   - `orderModel->setRelation`设置外键的显示。
   - `orderModel->setHeaderData`设置表头。
   - `orderModel->setFilter`添加过滤条件。

3. 取消预约

   ```c++
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
           margin[date_id-1][time_id-1][room_id-1]++;
           // 将机房余量数据写入数据库
           updateRoomInfo();
   
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
   ```

   - 获取选中行的内容。
   - 表中读到的内容是外键关联后显示的内容，所以通过`getID`来获取预约信息表中真正存放的值。
   - 弹框提示是否确认删除。
   - 确认删除则需要更新预约表，机房余量表，并将记录存放到日志。

# QT手把手打造预约系统——教师用户

## 教师界面介绍

![](..\configImages\teacherUI.png)

- 查看预约，可以查看所有学生的预约。

- 查看待审核的预约方便审核，点击后只显示需要审核的预约信息。

- 审核预约，选中一条待审核信息后点击审核机会弹框提示是否通过，选择一项即可完成审核。

  ![](..\configImages\checkOrder.png)

## 页面设计

![](..\configImages\teacherUIDesign.png)

界面设计用的空间都是前面几个页面用到的，就不在重复。

## 功能逻辑实现

1. 查看预约信息

   ```c++
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
   ```

   - 和学生界面查看预约信息一致，只是过滤条件不一样。

2. 审核预约

   ```c++
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
   ```

   - 获取选中行的内容。
   - 通过内容还原到预约信息表中真是存储的数据。
   - 判断给条信息是否是需要审核，因为有可能在查看所有预约的时候审核。
   - 需要审核就弹框提示是否通过。
   - 如果通过就需要更新预约信息表，如果不通过则还需要更新机房余量。
   - 最后将审核信息添加到日志文件。

