#include "mycoin.h"

Mycoin::Mycoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret){
        qDebug() << "Mycoin::Mycoin load img err!";
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pixmap;
        QString str = QString(":/src/Coin000%1.png").arg((this->min)++);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if(this->min > this->max){
            this->min = 1;
            this->isAnimation = false;
            timer1->stop();
        }
    });

    connect(timer2,&QTimer::timeout,[=](){
            QPixmap pixmap;
            QString str = QString(":/src/Coin000%1.png").arg((this->max)-- );
            pixmap.load(str);
            this->setFixedSize(pixmap.width(),pixmap.height() );
            this->setStyleSheet("QPushButton{border:0px;}");
            this->setIcon(pixmap);
            this->setIconSize(QSize(pixmap.width(),pixmap.height()));
            if(this->max < this->min) //如果小于最小值，重置最大值，并停止定时器
            {
                this->max = 8;
                this->isAnimation = false;
                timer2->stop();
            }
        });
}

/*******************************************
* 函数名：Mycoin::changeFlag
* 功能：金币翻转功能实现
* 参数：
* 返回值：
********************************************/
void Mycoin::changeFlag()
{
    if(this->flag){
        timer1->start(30);
        this->isAnimation = true;
        this->flag = false;
    }
    else{
        timer2->start(30);
        this->isAnimation = true;
        this->flag = true;
    }
}

/*******************************************
* 函数名：
* 功能：防止金币翻转过程中点击了别的金币
* 参数：
* 返回值：
********************************************/
void Mycoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin == true)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
