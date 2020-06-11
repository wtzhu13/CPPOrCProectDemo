#include "mypushbutton.h"


MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(this->normalImgPath);
    if(!ret){
        QString str = QString("%1 图片加载失败").arg(this->normalImgPath);
        qDebug() << str;
        return;
    }
    // 设置图片大小
    this->setFixedSize(pix.width(), pix.height());
    // 设置边框类型
    this->setStyleSheet("QPushButton{border:0px;}");
    // 设置图标
    this->setIcon(pix);
    // 设置图标大小
    this->setIconSize(QSize(pix.width(), height()));
}

void MyPushButton::zoom(int direstion)
{
    qDebug() << "action";
    QPropertyAnimation *action = new QPropertyAnimation(this, "geometry");
    // 设置时间间隔
    action->setDuration(200);
    if(direstion){
        // 设置其实位置
        action->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
        // 设置结束位置
        action->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    }
    else{
        // 设置其实位置
        action->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
        // 设置结束位置
        action->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    }
    // 设置缓和曲线
    action->setEasingCurve(QEasingCurve::OutBounce);
    // 执行动画效果
    action->start();

}
