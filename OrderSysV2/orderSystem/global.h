/******************************************************************************

  Copyright (C), 2020, Fred

 ******************************************************************************
  File Name     : global.h
  Version       : v1.0
  Author        : wtzhu_13/Fred
  Created       : 2020/05
  Description   : this file was private for orderSystem
  History       :
  1.Date        :
    Author      :
    Modification: Created file
******************************************************************************/
#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>
#include <QtDebug>
#include <QFile>
#include <QSqlRelationalTableModel>

extern int globalIndex;
extern QString userName;
extern QString userID;
const QString LOGFILEPATH = "./orderInfo.log";  // 日志文件地址

class GlobalFunc
{
public:
    GlobalFunc();
    ~GlobalFunc();
    static void saveLog(QString filePath, QString fileText);
};

#endif // GLOBAL_H
