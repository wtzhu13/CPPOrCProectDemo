#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "global.h"
#include "OrderSystemView.h"
#include "Identity.h"
using namespace std;


// 预约信息类型
typedef struct AppointInfo
{
    int date;   // 预约日期
    int time;   // 预约时间
    int roomId; // 预约机房号
    int state;  // 预约状态
}AppointInfo;


class Student : Identity
{
private:
    int logNum;
public:
    OrderSystemView osv;
    string name;
    int id;
    enum AppointmentState appointmentState;
    vector<AppointInfo> vMyAppointment;     // 存放自己的预约信息

    Student(string name, int id);
    void initStuSys();       // 初始化系统
    void appointment();      // 申请预约
    int checkSameTimeAppointment(int date, int time, int stuId);    // 查看同时段预约
    void checkAppointment(); // 查看预约信息
    void checkAllAppointment(); // 查看所有人预约
    void cancelOrder();      // 取消预约
    ~Student();
};


