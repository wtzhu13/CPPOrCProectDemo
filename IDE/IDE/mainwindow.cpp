#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextCodec>   // 字符编码转换头文件
#include <QFileDialog>  // 文件对话框
#include <string.h>

#define cout qDebug()

QString path;   // 定义一个全局变量存放地址

// 定义一个枚举类型
enum MyCode
{
    utf_8, GBK
};
enum MyCode flag;

// 字符编码指针
QTextCodec *codec;

// 构造函数，主要做初始化工作
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化，默认为UTF_8
    flag = utf_8;
    // 字符编码指针初始化
    codec = QTextCodec::codecForName("GBK");

}

// 析构函数，对象结束前（窗口关闭）自动调用析构函数，做清理工作
MainWindow::~MainWindow()
{
    delete ui;
}

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

// 打开文件的处理函数
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

// 另存为处理
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

// 退出系统
void MainWindow::on_actionQUITE_triggered()
{
    exit(0);
}

// 创建新文件
void MainWindow::on_actionNEW_triggered()
{
    // 新建文件首先输入地址
    path = QFileDialog::getSaveFileName();
    ui->textEdit->setText("");
}

// 保存文件
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

// 编译代码并运行
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
