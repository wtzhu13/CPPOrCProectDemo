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

#include "InputStatement.hpp"

using namespace std;

InputStatement::InputStatement()
{
    
}

InputStatement::~InputStatement()
{
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  funcName: InputStatement::show_input_menu()
 *  parameters: void
 *  return: void
 *  commnent: 打印类别显示菜单
 * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
void InputStatement::showInputMenu()
{
    system("clear");
    cout << "类别编码和类别名称的对应关系如下：" << endl;
    cout << "收⼊类：a1-⽣活费，a2-奖学金，a3-稿费" << endl;
    cout << "⽀出类：b1-学习⽤品，b2-生活用品，b3-游戏" << endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: InputStatement::inputAccount()
*  parameters: void
*  return: void
*  commnent: 输入账目
* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
void InputStatement::inputAccount()
{
    cout << "请输入明细，格式如下：\na1 2020-1-26 2000.0 1⽉⽣活费" << endl;
    cout << "请输入添加明细的数量:";
    int accountCount;
    cin >> accountCount;
    for(int i = 0; i < accountCount; i++){
        cout << "请输入收支明细:";
        string classID;
        string date;
        float money;
        string remark;
        // 从控制台获取输入的内容
        cin >> classID >> date >> money >> remark;
        cout << classID << date << money << remark;
        // 将内容写到本地
        ofstream ofs;
        ofs.open("./account.txt", ios::app);
        if (ofs.is_open()) {
            // 文件打开正常就将内容写到文件中
            ofs << classID << " " << date << " " << money << " " << remark << endl;
            ofs.close();
        }
        else{
            cout << "文件打开失败" << endl;
        }
    }
}
