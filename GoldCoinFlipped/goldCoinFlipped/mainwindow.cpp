#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 将开始按键放到指定位置
    MyPushButton * startBtn = new MyPushButton(":/src/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5, this->height()*0.7);

    // 创建一个新界面的对象
    chooseSence = new ChooseLevelSence();

    // 连接信号槽
    connect(startBtn, &MyPushButton::clicked, [=](){
    qDebug() << "开始游戏~";
    startBtn->zoom();
    startBtn->zoom(UP);

<<<<<<< HEAD
        // 添加一个演示，是动画更明显
        QTimer::singleShot(500, this, [=](){
            // 隐藏当前页面，打开新的页面
            this->hide();
            chooseSence->show();
=======
    // 延时执行
    QTimer::singleShot(200, this, [=](){
        // 隐藏当前页面，打开新的页面
        this->hide();
        chooseSence->show();
>>>>>>> 82b4db95078715168c4b2025ceebdeb00974d618
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    exit(0);
}
