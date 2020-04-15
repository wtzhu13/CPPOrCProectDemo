#include "ComputerOrderSystem.h"
#include "OrderSystemView.h"

ComputerOrderSystem::ComputerOrderSystem(/* args */)
{
}

ComputerOrderSystem::~ComputerOrderSystem()
{
}

void ComputerOrderSystem::startSys()
{
    OrderSystemView osv;
    osv.showMainMenu();
    int choice;
    cin >> choice;
    switch (choice)
    {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 0:
            this->exitSys();    //  退出系统
            break;
        default:
            break;
    }
}

/*******************************************
* 函数名：void ComputerOrderSystem::exitSys()
* 功能：退出系统
* 参数：
* 返回值：
********************************************/
void ComputerOrderSystem::exitSys()
{
    cout << "欢迎下次使用！" << endl;
    exit(0);    // 退出系统
}