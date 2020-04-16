#pragma once
#include <iostream>
#include <fstream>
#include "Identity.h"
#include "OrderSystemView.h"
using namespace std;

#define STUFILE "stuInfo.txt"
#define TEACHERFILE "teacherInfo.txt"

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
    int judgeFileEmpty(string path);
    ~Administrator();
};


