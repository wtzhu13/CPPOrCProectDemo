//
//  main.cpp
//  expenditureSys
//
//  Created by Bigfish on 2020/6/14.
//  Copyright © 2020 Bigfish. All rights reserved.
//  author: fred
//  E-mail: wtzhu_13@163.com
//  more information: https://blog.csdn.net/wtzhu_13
//

#include <iostream>
#include "InputStatement.hpp"
#include "SummarizeInfo.hpp"
#include "SearchInfo.hpp"

void showMainMenu()
{
    system("clear");
    cout << "请选择功能:" << endl;
    cout << "1.添加费用项目" << endl;
    cout << "2.按月汇总" << endl;
    cout << "3.查询" << endl;
    cout << "q.退出" << endl;
}

int main(int argc, const char * argv[]) {
    while (1) {
        // 获取选择的项目
        showMainMenu();
        cout << "请输入选项编码:";
        char choice = '0';
        cin >> choice;
        // 根据项目显示不同的功能界面
        switch (choice) {
            case '1':
                {
                    InputStatement i;
                    i.showInputMenu();
                    i.inputAccount();
                }
                break;
            case '2':
                {
                    SummarizeInfo s;
                    s.getMonth();
                    s.getMonthInfo(1);
                }
            break;
            case '3':
                {
                    SearchInfo si;
                    si.showSearchMenu();
                }
            break;
            case 'q':
                exit(0);
            break;
            default:
                break;
        }
    }
    return 0;
}
