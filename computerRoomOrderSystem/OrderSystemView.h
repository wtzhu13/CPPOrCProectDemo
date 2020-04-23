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
    void showAppointmenRoom(int choiceDate, int choiceTime, unsigned int num[5][2][3]);
    void showPersonalAppointment(vector<AppointInfo> v);
    ~OrderSystemView();
};


