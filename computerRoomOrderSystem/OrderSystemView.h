# pragma once
#include <iostream>
#include <string>
using namespace std;

#define TEACHERFILE "teacherInfo.txt"
#define STUFILE "stuInfo.txt"
#define ROMMINFOFILE "roomInfo.txt"
#define ADMININFOFILE "adminConfig.cfg"
#define ORDERFILE "order.log"

// string globalDate[] = {"周一", "周二", "周三", "周四", "周五"};
// string globalTime[] = {"上午", "下午"};
// string globalState[] = {"审核中", "取消", "通过", "拒绝"};

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
    ~OrderSystemView();
};


