# pragma once
#include <iostream>
#include <string>
#include <vector>
#include "global.h"
using namespace std;

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


