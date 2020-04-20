#pragma once
#include <iostream>
#include <fstream>
#include "OrderSystemView.h"
#include "Identity.h"
using namespace std;

class Student : Identity
{
private:
    int logNum;
public:
    OrderSystemView osv;
    string name;
    int id;
    enum AppointmentState appointmentState;

    Student(string name, int id);
    void initStuSys();       // 初始化系统
    void appointment();      // 申请预约
    int checkSameTimeAppointment(int date, int time, int stuId);    // 查看同时段预约
    void checkAppointment(); // 查看预约信息
    void checkAllAppointment(); // 查看所有人预约
    void cancelOrder();      // 取消预约
    ~Student();
};


