#pragma once
#include <iostream>
#include <fstream>
#include "OrderSystemView.h"
#include "global.h"
using namespace std;

class Identity
{
private:
    /* data */
public:
    int logNum;
    string name;
    int id;
    unsigned int roomMargin[5][2][3];
    enum AppointmentState appointmentState;
    vector<AppointInfo> vMyAppointment;     // 存放自己的预约信息
    vector<AppointInfo> AllAppointment;

    Identity();
    int judgeFileEmpty(string path);
    void getroomMargin();
    void getRoomGross(unsigned int roomGross[]);
    void getAppointmentCount(unsigned int appointment[5][2][3]);
    void getPersonalLog(int flag);   // 获取个人记录
    void filterAllfLog(AppointInfo tempAppointInfo);
    void filterSelfLog(AppointInfo tempAppointInfo);
    void checkAllAppointment();
    ~Identity();
};
