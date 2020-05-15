#include "widget.h"

#include <QApplication>
#include <QDebug>
#include "dialog.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Dialog login;
    qDebug() << "hello";
    if(connectDatabase())
    {
        qDebug()<<"连接成功"<<endl;
        if(login.exec() == QDialog::Accepted){
            w.show();
            return a.exec();
        }
    }
    else
    {
        qDebug()<<"连接失败"<<endl;
    }

    return 0;
}
