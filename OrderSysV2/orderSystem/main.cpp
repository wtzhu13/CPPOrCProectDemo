#include "widget.h"

#include <QApplication>
#include "connection.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    qDebug() << "hello";
    if(connectDatabase())
    {
        qDebug()<<"连接成功"<<endl;
    }
    else
    {
        qDebug()<<"连接失败"<<endl;
    }
    w.show();
    return a.exec();
}
