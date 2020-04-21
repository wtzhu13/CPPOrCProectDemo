#pragma once
#include <iostream>
#include <string>
using namespace std;

extern string globalDate[];
extern string globalTime[];
extern string globalState[];

// 预约信息类型
typedef struct AppointInfo
{
    int date;   // 预约日期
    int time;   // 预约时间
    int roomId; // 预约机房号
    int state;  // 预约状态
}AppointInfo;
