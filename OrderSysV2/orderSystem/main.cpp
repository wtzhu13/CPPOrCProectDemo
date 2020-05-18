#include "widget.h"
#include <QApplication>
#include <QDebug>
#include "dialog.h"
#include "connection.h"
#include "student.h"
#include "teacher.h"
#include "global.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog login;
    qDebug() << "hello";
    if(connectDatabase())
    {
        qDebug()<<"连接成功"<<endl;
        if(login.exec() == QDialog::Accepted){
            switch (globalIndex) {
                case 0:{
                    Student stu;
                    stu.show();
                    return a.exec();
                }
                break;
                case 1:{
                    Teacher teacher;
                    teacher.show();
                    return a.exec();
                }
                break;
                case 2:{
                    Widget w;
                    w.show();
                    return a.exec();
                }
                break;
                default:
                    break;
            }

        }
    }
    else
    {
        qDebug()<<"连接失败"<<endl;
    }

    return a.exec();
}
