#include <iostream>
#include "speechManager.h"
using namespace std;

int main(int argc, char const *argv[])
{
    speechManager sm;
    sm.test();      // 测试功能debug用
    sm.showMenu();
    
    cout << "请输入选择" << endl;
    int choice;
    cin >> choice;
    while (1)
    {
        switch (choice)
        {
            case 0:     // 退出系统
                sm.exitSys();
                break;
            case 1:
                /* code */
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            default:
                break;
        }
    }    
    return 0;
}
