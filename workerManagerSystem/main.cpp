#include <iostream>
#include "workerManager.h"
using namespace std;

int main()
{   
    workerManager wm;
    while (1)
    {
        int choice = 0;
        wm.showMenu();  // 显示菜单
        cout << "please input your choice" << endl;
        cin >> choice;  // 输入选择项
        if ( !cin.fail() && (0 <= choice && choice <= 7))
        {
            switch (choice)
            {
                case 0:
                    wm.exitSys();
                    break;
                case 1: //添加职工
                    wm.addWorker();
                    break;
                case 2: //显示职工
                    wm.showWorker();
                    break;
                case 3: //删除职工
                    wm.deleteById();
                    break;
                case 4: //修改职工
                    wm.modifyWorkerInfo();
                    break;
                case 5: //查找职工
                    wm.findWorker();
                    break;
                case 6: //排序职工
                    wm.sortById();
                    break;
                case 7: //清空文件
                    wm.clear();
                    break;
                default:
                    break;
            }
        }
        else
        {
            cout << "输入有误" << endl;
            cin.clear();        // 重置cin 输入状态,即重置cin.fail()的状态
            cin.ignore();       // 清除cin 缓冲区未读取的内容，cin.sync()说是可以，不过我在Mac上不行
        }       
    }   
    return 0;
}