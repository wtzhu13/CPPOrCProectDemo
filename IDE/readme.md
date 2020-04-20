# IDE

**功能介绍：**一款基于QT的简易c语言编辑器，可以编辑，编译和运行。

**环境配置：**编译运行功能的前提是windows平台上已经安装gcc并配置到系统环境变量中，这个的配置方式可自行百度，很多帖子有讲。或直接安装QT，便于阅读源码。同时，安装QT自带会安装gcc，将其配置到环境变量中即可

[主题运行效果可观看成品展示]()



### UI

在创建工程的时候勾选上UI选项，会自动生成一个`mainWindow`，在菜单栏中点击添加菜单功能，然后在ui文件中通过拖拽控件布局。布局完成后，在布局下方找到对应控件名称并右键转到槽，工程会自动在`mainwindow.cpp`中生成对应的槽函数，在槽函数中即可实现各自功能。槽函数的命名为`on_action控件名_triggered`。





### 主要功能实现

#### 打开文件

**思路：**通过`QFileDialog::getOpenFileName()`函数获取文件路径。然后通过`fopen`打开路径对应的文件，并通过一个临时变量`str`存放文件中的内容，最后通过`ui->textEdit->setText()`函数将临时变量中的内容展示在文本编辑控件中。最后关闭文件。

**注意：**通过`QFileDialog::getOpenFileName()`函数获取的文件路径是`QString`类型的数据，所以在给`fopen`使用前需要转换为`char *`类型。`QT`中使用UTF-8编码，所以如果文件使用GBK编码，需要转换编码方式。

**API说明：**

- `QFileDialog::getOpenFileName()` 通过可视化方式获取路径
- `codec->fromUnicode(path).data()`改变编码方式并转换数据类型
- `codec->toUnicode(buf)`  转换为UTF-8编码
- `ui->textEdit->setText(str)`  向文本编辑框放入待编辑内容

**代码实现：**

```c++
void MainWindow::on_actionOPEN_triggered()
{
    // 打开文件，获取文件路径
    path = QFileDialog::getOpenFileName();
    cout << "path=" << path;
    if(path.isEmpty())
    {
        // 没有选择路径直接退出
        return;
    }
    // 字符编码转换
    char *fileName = codec->fromUnicode(path).data();
    // 打开文件并读取内容,并放进编辑区
    FILE *fp = fopen(fileName, "rb");
    if(fp == NULL)
    {
        cout << "on_actionOPEN_triggered() fopen err";
        return;
    }

    char buf[1024*5];
    QString str = "";

    // 读取文件
    while (1) {
        memset(buf, 0, sizeof (buf));
        fgets(buf, sizeof (buf), fp);

        // 根据标志位改变字符编码方式
        if(flag == utf_8)
        {
            str += buf;
        }
        else if(flag == GBK)
        {
            str += codec->toUnicode(buf);
        }
        if(feof(fp))
        {
            break;
        }
    }

    // 将文件内容放进编辑区
    ui->textEdit->setText(str);

    // 关闭文件
    fclose(fp);
    fp = NULL;

}
```



#### 文件另存为

**思路：**通过`QFileDialog::getSaveFileName()`获取文件待保存的路径，然后通过临时变量保存文本编辑区的内容，最后通过写的方式打开待保存的路径，将临时变量内容写入，关闭文件即可。

**注意：**依旧是编码方式，还有`QString`和`char *`类型的不同

**API说明：**

- `QFileDialog::getSaveFileName()` 通过可视化方式获取保存路径
- `str.toStdString().data()`  将`QString`转换为char * 类型
- `ui->textEdit->toPlainText()`  获取文本编辑框内容

**代码实现：**

```c++
void MainWindow::on_actionSAVE_AS_triggered()
{
    // 选择另存为的路径，为UTF8编码,返回类型为QString类型
    path = QFileDialog::getSaveFileName();
    if(path.isEmpty())
    {
        // 如果没有选择路径直接退出
        return;
    }
    // 需要将路径转换为GBK编码，并且为char * 类型
    const char *fileName = codec->fromUnicode(path).data();
    cout << fileName;

    // 打开文件并读取内容,并放进编辑区
    FILE *fp = fopen(fileName, "wb");
    if(fp == NULL)
    {
        cout << "on_actionSAVE_AS_triggered open file err";
    }

    // 获取编辑区的内容，返回QString
    QString str = ui->textEdit->toPlainText();

    // 将QString转换为char * 类型
    const char *buf = str.toStdString().data();
    fputs(buf, fp);

    // 关闭文件
    fclose(fp);
}
```



#### 文件保存

**思路：**如果是open一个文件改动后需要保存，那么在open的时候就已经获取到了文件路径，直接将编辑区的内容获取后保存到指定文件中即可。如果打开编辑器后开始编辑内容需要保存，那么此时没有获取过路径，就需要通过`QFileDialog::getSaveFileName()`获取一下保存路径。

**注意：**依旧是编码方式，还有`QString`和`char *`类型的不同。

**API说明：**无特殊`API`用到的上面已经介绍过。

**代码实现：**

```c++
void MainWindow::on_actionSAVE_triggered()
{
    // 如果刚打开编辑器开始写东西，此时path为空就需要通过getSaveFileName获取一个路径
    if(path.isEmpty())
    {
        path = QFileDialog::getSaveFileName();
    }
    const char *fileName = codec->fromUnicode(path).data();
    // 打开文件并读取内容,并放进编辑区
    FILE *fp = fopen(fileName, "wb");
    if(fp == NULL)
    {
        cout << "on_actionSAVE_triggered open file err";
    }

    // 获取编辑区的内容，返回QString
    QString str = ui->textEdit->toPlainText();

    // 将QString转换为char * 类型
    const char *buf = str.toStdString().data();
    fputs(buf, fp);

    // 关闭文件
    fclose(fp);
}
```



#### 编译运行

**思路：**首先判断一下需要运行的文件是否已经存在，如保存文件中出现的第二种情况，一打开编辑器就开始编辑的文件，还没保存到本地，那么就需要先保存到本地。然后通过`gcc filename.c -o filename`生成可执行文件，再执行可执行程序即可。第一步获取`filename`:通过`QString的replace`函数将路径最后的`.c`去掉即可。第二步执行可执行程序。

**注意：**执行以上的两部都需要在终端执行，直接调用system函数即可。如果编译出错，那么就不能继续执行，需终端停留在报错页面，使用`cmd /k`可实现终端停留

**API说明：**

- `replace()` `QString`中的函数,替换字符串中指定字符串。
- `QString("gcc %1 -o %2").arg(arg1).arg(arg2)`  `QString`格式化
- `ui->textEdit->toPlainText()`  获取文本编辑框内容

**代码实现：**

```c++
void MainWindow::on_actioncomplie_triggered()
{
    if(path.isEmpty())
    {
        // 如果没有路径则需要保存一下才能运行
        this->on_actionSAVE_triggered();
    }

    QString demo = path;

    // 生成的目标文件名
    demo.replace(".c", "");

    // gcc filename.c -o filename
    QString cmd = QString("gcc %1 -o %2").arg(path).arg(demo);

    // system执行成返回0
    int ret = system(codec->fromUnicode(cmd).data());
    if(ret != 0)
    {
        // cmd /k 停留在终端
        cmd = QString("cmd /k gcc %1 -o %2").arg(path).arg(demo);
        system(codec->fromUnicode(cmd).data());
        return;
    }
    QString target = QString("cmd /k %1").arg(demo);
    system(codec->fromUnicode(target).data());
    system("cmd");
}
```



#### 改变字符编码

**思路：**通过`codec->fromUnicode(path)`或`codec->toUnicode(buf)`两个API实现编码转换功能。由于字符编码需要在好几个槽函数中使用，所以思考定义一个全局变量，通过这个全局变量的状态来判断如何转换。通过`ui->label->setText`在左下角实时显示当前的编码方式。

**注意：**别的槽函数使用，所以需要使用全局变量。

**API说明：**

**API说明：**

- `replace()` `QString`中的函数,替换字符串中指定字符串。
- `QString("gcc %1 -o %2").arg(arg1).arg(arg2)`  `QString`格式化
- `ui->label->setText("当前以GBK显示，切换编码后请重新打开文件")`  将制定内容显示在`label`中。

**代码实现：**

```c++
// UTF_8转换函数
void MainWindow::on_actionUTF_8_triggered()
{
    // 按下转换按键，为UTF_8
    flag = utf_8;
    ui->label->setText("当前以UTF-8显示，切换编码后请重新打开文件");
}

// GBK转换函数
void MainWindow::on_actionGBK_triggered()
{
    // 按下按键转换为GBK
    flag = GBK;
    ui->label->setText("当前以GBK显示，切换编码后请重新打开文件");
}
```



#### 退出、复制、粘贴、剪切、撤销

**思路：**直接调用QT自带的相应的功能函数。

**API说明：**

- ` ui->textEdit->copy()` 复制
- `ui->textEdit->paste()` 粘贴
- `ui->textEdit->cut()`  剪切
- `ui->textEdit->undo()`撤销

**代码实现：**

```c++
// 复制
void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit->copy();
}

// 粘贴
void MainWindow::on_actionpaste_triggered()
{
    ui->textEdit->paste();
}

// 剪切
void MainWindow::on_actioncut_triggered()
{
    ui->textEdit->cut();
}

// 撤销
void MainWindow::on_actionundo_triggered()
{
    ui->textEdit->undo();
}

// 退出系统
void MainWindow::on_actionQUITE_triggered()
{
    exit(0);
}
```

### 完整代码

完整的工程代码连接：https://github.com/wtzhu13/CPPOrCProectDemo/tree/master/IDE



**彩蛋：**这个项目中还包含其他一些练手小项目，后续会慢慢更新，不断往里添加。