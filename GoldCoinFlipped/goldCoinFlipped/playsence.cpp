#include "playsence.h"
#include "ui_playsence.h"

PlaySence::PlaySence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlaySence)
{

}

/*******************************************
* 函数名：PlaySence::PlaySence
* 功能：自定义构造函数
* 参数：关卡的编号
* 返回值：
********************************************/
PlaySence::PlaySence( int level, QWidget *parent) : QMainWindow(parent), levelSence(level),
    ui(new Ui::PlaySence)
{
    ui->setupUi(this);
    qDebug() << level;

    // 将返回按钮放入框架中
    MyPushButton *backBtn = new MyPushButton(":/src/BackButton.png", ":/src/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(), this->height()-backBtn->height());

    // 点击返回按键的链接
    connect(backBtn, &MyPushButton::clicked, [=](){
        // 发送返回信号
        QTimer::singleShot(200, this, [=](){
            QTimer::singleShot(200, this, [=](){
                emit backLevelSence();
            });

        });
    });

    // 显示关卡数
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str = QString("Level %1").arg(this->levelSence);
    label->setFont(font);
    label->setText(str);
    label->setGeometry(30, this->height() - 50, 120, 50);

    // 显示游戏背景
    for (int i; i < 4;i++) {
        for (int j; j < 4;j++) {
            QPixmap pix = QPixmap(":/src/BoardNode(1).png");
            QLabel *label = new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(75+ i*50, 200+ j*50);
        }
    }

}

PlaySence::~PlaySence()
{
    delete ui;
}

/*******************************************
* 函数名：PlaySence::paintEvent
* 功能：自定义绘图事件
* 参数：
* 返回值：
********************************************/
void PlaySence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    // 加载背景图片
    pix.load(":/src/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    // 加载标题
    pix.load(":/src/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}
