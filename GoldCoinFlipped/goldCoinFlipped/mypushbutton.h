#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>
#include <QEasingCurve>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    // 自定义一个构造函数
    MyPushButton(QString normalImg, QString pressImg = "");
    void zoom(int direstion = 0);

    // 重写按钮的按下和释放
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    QString normalImgPath;
    QString pressImgPath;

signals:

};

#endif // MYPUSHBUTTON_H
