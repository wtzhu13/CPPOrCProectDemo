#include "mypushbutton.h"

/*******************************************
* 函数名：MyPushButton::MyPushButton
* 功能：自定义构造函数
* 参数：按钮需要加载的图片
* 返回值：
********************************************/
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

/*******************************************
* 函数名：MyPushButton::zoom
* 功能：跳动的动画效果，开始游戏按钮的效果
* 参数：按钮跳动的方向
* 返回值：
********************************************/
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

/*******************************************
* 函数名：MyPushButton::mousePressEvent
* 功能：拦截鼠标点击事件，针对返回按钮设置的动画效果
* 参数：鼠标事件
* 返回值：
********************************************/
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath != ""){
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret){
            qDebug() << "图片加载失败！";
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
    // 其他操作交给父类
    return QPushButton::mousePressEvent(e);
}

/*******************************************
* 函数名：MyPushButton::mousePressEvent
* 功能：拦截鼠标释放事件，针对返回按钮设置的动画效果
* 参数：鼠标事件
* 返回值：
********************************************/
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath != ""){
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret){
            qDebug() << "图片加载失败！";
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
    // 其他操作交给父类
    return QPushButton::mouseReleaseEvent(e);
}
