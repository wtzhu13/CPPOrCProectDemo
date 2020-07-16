#ifndef CHOOSELEVELSENCE_H
#define CHOOSELEVELSENCE_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include "mypushbutton.h"
#include "playsence.h"

namespace Ui {
class ChooseLevelSence;
}

class ChooseLevelSence : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseLevelSence(QWidget *parent = nullptr);
    ~ChooseLevelSence();
    // 重写绘图事件
    void paintEvent(QPaintEvent *);

private slots:
    void on_actionquit_triggered();

signals:
    // 写一个自定义信号，告诉主场景，点击返回
    void chooseScenseBack();


private:
    Ui::ChooseLevelSence *ui;
};

#endif // CHOOSELEVELSENCE_H
