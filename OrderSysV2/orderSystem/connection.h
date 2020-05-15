#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDebug>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "globalConfig.h"

/************************************************
* 函数名：connectDatabase()
* 参数：无
* 返回值：bool成功true，失败false
* 描述：数据库连接
************************************************/
bool connectDatabase()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dataBaseIP);   //主机名称，如localhost
    db.setDatabaseName(dataBase);    //数据库名称
    db.setPort(dataBasePort);              //数据库端口号
    db.setUserName(dataBaseUser);        //用户名称
    db.setPassword(dataBasePWD);      //用户密码
    db.open();
    if(db.isOpen())
    {

        return true;
    }
    else
    {
        return false;
    }
}

#endif // CONNECTION_H
