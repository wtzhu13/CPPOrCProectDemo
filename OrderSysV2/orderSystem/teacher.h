#ifndef TEACHER_H
#define TEACHER_H

#include <QWidget>

namespace Ui {
class Teacher;
}

class Teacher : public QWidget
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = nullptr);
    ~Teacher();

private:
    Ui::Teacher *ui;
};

#endif // TEACHER_H
