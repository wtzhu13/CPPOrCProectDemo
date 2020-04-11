#include <iostream>
#include "speechManager.h"
using namespace std;

int main(int argc, char const *argv[])
{
    speechManager sm;
    // sm.test();      // 测试功能debug用
    sm.showMenu();  
    
    while (1)
    {
        cout << "请输入选择" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 0:     // 退出系统
                sm.exitSys();
                break;
            case 1:
                sm.startCompetition();  // 开始比赛
                return 0;
            case 2:
                sm.loadRecord();
                break;
            case 3:
                sm.clearFile(); // 清空数据
                break;
            default:
                break;
        }
    }    
    return 0;
}
