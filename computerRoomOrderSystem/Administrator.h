#pragma once
#include <iostream>
#include <fstream>
#include "Identity.h"
#include "OrderSystemView.h"
using namespace std;

#define STUFILE "stuInfo.txt"
#define TEACHERFILE "teacherInfo.txt"
#define ROMMINFOFILE "roomInfo.txt"
#define ORDERFILE "order.txt"

class Administrator : Identity
{
private:
    /* data */
public:
    string name;
    OrderSystemView osv;
    Administrator(string name);
    int showMenu();
    void addUser();     // 添加用户
    void saveUsrInfo(string path, int id, string name, int pwd);     // 保存用户信息到本地
    void showUsrInfo(); // 查看账号
    int judgeAccountExit(string path, int id);    // 查看账户是够已存在
    void showRoomInfo();    // 查看机房信息
    void clearOrder();  // 清空预约信息
    ~Administrator();
};


