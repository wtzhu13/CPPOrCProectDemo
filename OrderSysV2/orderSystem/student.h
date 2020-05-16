#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>

namespace Ui {
class Student;
}

class Student : public QWidget
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);
    ~Student();

private:
    Ui::Student *ui;
};

#endif // STUDENT_H
