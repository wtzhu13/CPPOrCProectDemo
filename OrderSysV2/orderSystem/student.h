#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
#include "global.h"

namespace Ui {
class Student;
}

class Student : public QWidget
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);
    ~Student();

private slots:
    void on_pushButton_applyOrder_clicked();

    void on_pushButton_checkSelfOrder_clicked();

    void on_pushButton_checkAllOrder_clicked();

    void on_pushButton_cancleOrder_clicked();

private:
    Ui::Student *ui;
};

#endif // STUDENT_H
