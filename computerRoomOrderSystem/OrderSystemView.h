# pragma once
#include <iostream>
#include <string>
#include <vector>
#include "global.h"
using namespace std;

#define TEACHERFILE "teacherInfo.txt"
#define STUFILE "stuInfo.txt"
#define ROMMINFOFILE "roomInfo.txt"
#define ADMININFOFILE "adminConfig.cfg"
#define ORDERFILE "order.log"

class OrderSystemView
{
private:
    
public:
    OrderSystemView(/* args */);
    void showMainMenu();
    void loginUserId();
    void loginPassWord();
    void showAdminMenu(string name);
    void showAddUsrMenu();
    void showUsrInfoMenu();
    void showStuMenu();
    void showAppointmenDate();
    void showAppointmenTime();
    void showAppointmenRoom(unsigned int num[]);
    void showPersonalAppointment(vector<AppointInfo> v);
    ~OrderSystemView();
};


