#ifndef CHOOSELEVELSENCE_H
#define CHOOSELEVELSENCE_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include "mypushbutton.h"

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

private:
    Ui::ChooseLevelSence *ui;
};

#endif // CHOOSELEVELSENCE_H
