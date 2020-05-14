#include "widget.h"

#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    qDebug() << "hello";

//    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");   //主机名称，如localhost
//    db.setDatabaseName("test");    //数据库名称
//    db.setPort(3306);              //数据库端口号
//    db.setUserName("root");        //用户名称
//    db.setPassword("123456");      //用户密码
//    db.open();
//    if(db.isOpen())qDebug()<<"true"<<endl;
//    else qDebug()<<"false"<<endl;


    w.show();
    return a.exec();
}
