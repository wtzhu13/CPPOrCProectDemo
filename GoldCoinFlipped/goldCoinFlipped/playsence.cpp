#include "playsence.h"
#include "ui_playsence.h"

PlaySence::PlaySence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlaySence)
{
    ui->setupUi(this);
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
}

PlaySence::~PlaySence()
{
    delete ui;
}

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
