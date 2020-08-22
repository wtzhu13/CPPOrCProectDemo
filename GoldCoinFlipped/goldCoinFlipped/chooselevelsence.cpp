#include "chooselevelsence.h"
#include "ui_chooselevelsence.h"

ChooseLevelSence::ChooseLevelSence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelSence)
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
           emit chooseScenseBack();
        });
    });

    // 创建选择关卡按钮
    for (int i=0;i < 20; i++) {
        MyPushButton *menuBtn = new MyPushButton(":/src/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i%4 * 70, 130 + i/4 * 70);

        // 设置每个按钮上的关卡数字
        QLabel *label = new QLabel();
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25 + i%4 * 70, 130 + i/4 * 70);
        // 设置label文字对齐方式，水平居中，垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        // 当label覆盖在按键上时，覆盖了按钮的点击事件导致按键接收不到点击，需要设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);

        connect(menuBtn, &MyPushButton::clicked, [=](){
            qDebug() << i + 1;
            this->hide();
            PlaySence *pPlaySence = new PlaySence(i+1);
            pPlaySence->setGeometry(this->geometry());
            pPlaySence->show();

            // 链接返回信号
            connect(pPlaySence, &PlaySence::backLevelSence, [=](){
                this->setGeometry(pPlaySence->geometry());
                this->show();
                delete pPlaySence;
            });
        });    
    }
}

ChooseLevelSence::~ChooseLevelSence()
{
    delete ui;
}

void ChooseLevelSence::on_actionquit_triggered()
{
    exit(0);
}

void ChooseLevelSence::paintEvent(QPaintEvent *)
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
