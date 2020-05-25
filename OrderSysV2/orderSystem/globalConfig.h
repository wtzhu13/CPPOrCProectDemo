/******************************************************************************

  Copyright (C), 2020, Fred

 ******************************************************************************
  File Name     : globalConfig.h
  Version       : v1.0
  Author        : wtzhu_13/Fred
  Created       : 2020/05
  Description   : this file was private for orderSystem
  History       :
  1.Date        :
    Author      :
    Modification: Created file
******************************************************************************/
#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H
#include <QString>

/********************数据库配置信息***********************/
QString dataBaseIP = "localhost";
QString dataBase = "order_system";
unsigned int dataBasePort = 3306;
QString dataBaseUser = "root";
QString dataBasePWD = "123456";

#endif // GLOBALCONFIG_H
