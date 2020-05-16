#include "teacher.h"
#include "ui_teacher.h"

Teacher::Teacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
}

Teacher::~Teacher()
{
    delete ui;
}
