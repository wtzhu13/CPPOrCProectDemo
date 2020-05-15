#include "widget.h"

#include <QApplication>
#include "connection.h"
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Dialog login;
    qDebug() << "hello";
    if(connectDatabase())
    {
        qDebug()<<"连接成功"<<endl;
    }
    else
    {
        qDebug()<<"连接失败"<<endl;
    }
    if(login.exec() == QDialog::Accepted){
        w.show();
        return a.exec();
    }
    return 0;
}
