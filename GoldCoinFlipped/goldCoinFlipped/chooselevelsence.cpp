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
        qDebug() << "fanhui";
    });
}

ChooseLevelSence::~ChooseLevelSence()
{
    delete ui;
}

void ChooseLevelSence::on_actionquit_triggered()
{
<<<<<<< HEAD
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

=======
    this->close();
>>>>>>> 82b4db95078715168c4b2025ceebdeb00974d618
}
