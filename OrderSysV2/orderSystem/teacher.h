#ifndef TEACHER_H
#define TEACHER_H

#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include <QTableWidget>
#include <QtWidgets/QMessageBox>
#include <fstream>
#include <QDateTime>
#include "global.h"

namespace Ui {
class Teacher;
}

class Teacher : public QWidget
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = nullptr);
    ~Teacher();

private slots:
    void on_pushButton_lookAllOrder_clicked();

    void on_pushButton_checkOrder_clicked();

    void showOrderInfo(int lookFlag);

    void on_pushButton_clicked();

    void updateOrderState(int order_id, int stateID);

    void updateRoomMarginInfo(int date_id, int time_id, int room_id);

    int getID(QString str);

private:
    Ui::Teacher *ui;
};

#endif // TEACHER_H
