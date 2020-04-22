#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 预约信息类型
typedef struct AppointInfo
{
    int date;   // 预约日期
    int time;   // 预约时间
    int roomId; // 预约机房号
    int stuId;
    string stuName;
    int state;  // 预约状态
}AppointInfo;

enum AppointmentState
{
    audit, 
    cancle,
    success,
    fail
};

#define TEACHERFILE "teacherInfo.txt"
#define STUFILE "stuInfo.txt"
#define ROMMINFOFILE "roomInfo.txt"
#define ADMININFOFILE "adminConfig.cfg"
#define ORDERFILE "order.log"

extern string globalDate[];
extern string globalTime[];
extern string globalState[];

extern void saveLog(int logNumSave, int dateSave, int timeSave, int stuIdSave, string nameSave, int roomSave, int StateSave);
extern int getLogNum();

