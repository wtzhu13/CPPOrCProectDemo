#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QTimer>

class Mycoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit Mycoin(QWidget *parent = nullptr);
    Mycoin(QString btnImg);
    void changeFlag();
    void mousePressEvent(QMouseEvent *e);

    // 坐标及正反标志
    int posX;
    int posY;
    bool flag;
    QTimer *timer1;
    QTimer *timer2;
    int min = 1;
    int max = 8;
    bool isAnimation = false;
    bool isWin = false;
signals:

};

#endif // MYCOIN_H
