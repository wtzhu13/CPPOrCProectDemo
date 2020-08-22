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

    // 初始化关卡左边数组
    dataConfig config;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gameArray[i][j] = config.mData[this->levelSence][i][j];
        }
    }

    // 胜利的图标先放在窗口顶端，不显示在画面中，等胜利了再动画到画面内
    QLabel* winLabel = new QLabel;
        QPixmap tmpPix;
        tmpPix.load(":/src/LevelCompletedDialogBg.png");
        winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
        winLabel->setPixmap(tmpPix);
        winLabel->setParent(this);
        winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());


    // 显示游戏背景
    for (int i = 0; i < 4;i++) {
        for (int j = 0; j < 4;j++) {
            QPixmap pix = QPixmap(":/src/BoardNode(1).png");
            QLabel *label = new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(75+ i*50, 200+ j*50);

            // 创建金币
            QString img;
            if(gameArray[i][j] == 1){
                img = ":/src/Coin0001.png";
            }
            else{
                img = ":/src/Coin0008.png";
            }
            Mycoin *coin = new Mycoin(img);
            coin->setParent(this);
            coin->move(77 + i*50,204+j*50);
            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArray[i][j];

            coinBtn[i][j] = coin;

            connect(coin,&Mycoin::clicked,[=](){
                    //qDebug() << "点击的位置： x = " <<  coin->posX << " y = " << coin->posY ;
                    coin->changeFlag();
                    gameArray[i][j] = gameArray[i][j] == 0 ? 1 : 0; //数组内部记录的标志同步修改

                    // 延时处理周围的四个币的翻转
                    QTimer::singleShot(300, this,[=](){
                    if(coin->posX+1 <=3)
                    {
                      coinBtn[coin->posX+1][coin->posY]->changeFlag();
                      gameArray[coin->posX+1][coin->posY] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                    }
                    if(coin->posX-1>=0)
                    {
                      coinBtn[coin->posX-1][coin->posY]->changeFlag();
                      gameArray[coin->posX-1][coin->posY] = gameArray[coin->posX-1][coin->posY]== 0 ? 1 : 0;
                    }
                    if(coin->posY+1<=3)
                    {
                     coinBtn[coin->posX][coin->posY+1]->changeFlag();
                     gameArray[coin->posX][coin->posY+1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                    }
                    if(coin->posY-1>=0)
                    {
                     coinBtn[coin->posX][coin->posY-1]->changeFlag();
                     gameArray[coin->posX][coin->posY-1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                    }


                    this->isWin = true;
                    for(int i = 0 ; i < 4;i++)
                    {
                        for(int j = 0 ; j < 4; j++)
                        {
                            //qDebug() << coinBtn[i][j]->flag ;
                            if( coinBtn[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if(this->isWin)
                   {
                      qDebug() << "胜利";
                      // 胜利之后把按钮禁用，再点击不生效
                      for(int i = 0 ; i < 4;i++)
                      {
                          for(int j = 0 ; j < 4; j++)
                          {
                                coinBtn[i][j]->isWin = true;
                          }
                      }
                      QPropertyAnimation * animation1 =  new QPropertyAnimation(winLabel,"geometry");
                          animation1->setDuration(1000);
                          animation1->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                          animation1->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                          animation1->setEasingCurve(QEasingCurve::OutBounce);
                          animation1->start();
                   }
                });
            });
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
