#pragma once
#include "OrderSystemView.h"
#include "Administrator.h"
#include "Teacher.h"
#include "Student.h"
#include <fstream>
using namespace std;

#define TEACHERFILE "teacherInfo.txt"
#define STUFILE "stuInfo.txt"

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
    void stuSys();      // 学生子系统
    void teacherSys();  // 老师子系统
    bool judgeExist(string name, int pwd, string path);  // 判断用户名和密码是否存在
    int judgeFileEmpty(string path);
    ~ComputerOrderSystem();
};


