#pragma once
#include "OrderSystemView.h"
#include "Administrator.h"
#include <fstream>
using namespace std;

class ComputerOrderSystem
{
private:
    /* data */
public:
    OrderSystemView osv;

    ComputerOrderSystem(/* args */);
    void startSys();    // 启动系统
    void exitSys();     // 退出系统
    void adminSys();    // 管理员系统
    bool judgeExist(string name, int id, string path);  // 判断用户名和密码是否存在
    ~ComputerOrderSystem();
};


