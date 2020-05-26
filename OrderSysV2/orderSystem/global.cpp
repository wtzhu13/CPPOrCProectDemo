/******************************************************************************

  Copyright (C), 2020, Fred

 ******************************************************************************
  File Name     : global.cpp
  Version       : v1.0
  Author        : wtzhu_13/Fred
  Created       : 2020/05
  Description   : this file was private for orderSystem
  History       :
  1.Date        :
    Author      :
    Modification: Created file
******************************************************************************/
#include "global.h"

int globalIndex = 0;
QString userName;
QString userID;

GlobalFunc::GlobalFunc()
{

}

GlobalFunc::~GlobalFunc()
{

}

void GlobalFunc::saveLog(QString filePath, QString fileText)
{
    QFile file(filePath);
    // 以追加的形式写入文件中
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    file.write(fileText.toUtf8());
    file.close();
}


