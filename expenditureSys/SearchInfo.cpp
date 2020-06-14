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

#include "SearchInfo.hpp"

SearchInfo::SearchInfo()
{
    this->totalMoney = 0.0;
}

SearchInfo::~SearchInfo()
{
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: SearchInfo::showSearchMenu()
*  parameters: void
*  return: void
*  commnent: 显示查询菜单
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SearchInfo::showSearchMenu()
{
    system("clear");
    cout << "请选择查询方式:" << endl;
    cout << "1.查询大于某个金额的明细" << endl;
    cout << "2.按类别查询" << endl;
    cout << "青训则方式编号:";
    int mainChoice;
    cin >> mainChoice;
    switch (mainChoice) {
        case 1:
            this->searchMoneyMoreThan();
            break;
        case 2:
            this->secrchByClassID();
            break;
        default:
            break;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: SearchInfo::searchMoneyMoreThan()
*  parameters: void
*  return: bool
*  commnent: 查询大于某个金额的明目
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SearchInfo::searchMoneyMoreThan()
{
    cout << "请输入金额:";
    float moneyFlag;
    cin >> moneyFlag;
    
    // 定义存放文件中内容的变量
    string classID;
    string date;
    float money;
    string remark;
    // 遍历文件,并根据条件进行筛选
    ifstream ifs;
    ifs.open("./account.txt", ios::in);
    if (!ifs.is_open()) {
        cout << "文件打开失败~" << endl;
    }
    else{
        while (ifs >> classID && ifs >> date && ifs >> money && ifs >> remark) {
            if (money > moneyFlag) {
                cout << classID << " " << date << " " << money << " " << remark << endl;
                this->totalMoney += money;
            }
        }
        cout << "金额大于" << moneyFlag << "元的总消费为:" << this->totalMoney << "元" << endl;
    }
    ifs.close();
    
    // 等待键盘输入
    cout << "请输入任意键继续...";
    char waitFlag;
    cin >> waitFlag;
    if (waitFlag != ' ')
    {
       return;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: SearchInfo::findInFile()
*  parameters: void
*  return: bool
*  commnent: 遍历文件内容
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SearchInfo::secrchByClassID()
{
    string classInput;
    cout << "类别编码和类别名称的对应关系如下：" << endl;
    cout << "收⼊类：a1-⽣活费，a2-奖学金，a3-稿费" << endl;
    cout << "⽀出类：b1-学习⽤品，b2-生活用品，b3-游戏" << endl;
    cout << "请选择类别编码:";
    cin >> classInput;
    // 定义存放文件中内容的变量
    string classID;
    string date;
    float money;
    string remark;
    // 遍历文件,并根据条件进行筛选
    ifstream ifs;
    ifs.open("./account.txt", ios::in);
    if (!ifs.is_open()) {
        cout << "文件打开失败~" << endl;
    }
    else{
        while (ifs >> classID && ifs >> date && ifs >> money && ifs >> remark) {
            if (classInput == classID) {
                cout << classID << " " << date << " " << money << " " << remark << endl;
                this->totalMoney += money;
            }
        }
        cout << "类别" << classInput << "的总消费为:" << this->totalMoney << "元" << endl;
    }
    ifs.close();

    // 等待键盘输入
    cout << "请输入任意键继续...";
    char waitFlag;
    cin >> waitFlag;
    if (waitFlag != ' ')
    {
       return;
    }
}
