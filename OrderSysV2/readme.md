# QT手把手打造预约系统——登录界面

## 效果展示

### 登录界面处事窗口

![](D:\study\CPPOrCProectDemo\configImages\login_ui.png)

- 在用户ID处输入用户ID，没用选择用户名是因为可能存在同名学生，使用ID这种唯一标识更有区分性。
- 用户在密码区输入密码，且以密文形式展示，便于保密。
- 点击登录即可。



### 登录异常

![](D:\study\CPPOrCProectDemo\configImages\login_err.png)

当用户名或者密码错误是，会有弹窗提示。



### 登录成功

当用户登录成功后调转到不同身份用户的界面。本项目有学生、教师和管理员三个身份，所以系统会根据登录人的ID自动跳转到指定的用户界面。



## 页面UI设计

本案例直接使用QT自带的拖拽的方式设计界面，具体用到的空间如下：

![](D:\study\CPPOrCProectDemo\configImages\ui_design.png)

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