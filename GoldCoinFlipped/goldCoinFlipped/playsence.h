#ifndef PLAYSENCE_H
#define PLAYSENCE_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include "mypushbutton.h"

namespace Ui {
class PlaySence;
}

class PlaySence : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlaySence(QWidget *parent = nullptr);
    ~PlaySence();
    void paintEvent(QPaintEvent *);

signals:
    void backLevelSence();

private:
    Ui::PlaySence *ui;
};

#endif // PLAYSENCE_H
