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

#include "SummarizeInfo.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: myCompare()
*  parameters: AccountInfoPer &v1, AccountInfoPer &v2
*  return: void
*  commnent: 自定义一个比较方法,用于对容器中的自定数据类型进行排序
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool myCompare(AccountInfoPer &v1, AccountInfoPer &v2)
{
    return v1.money < v2.money;
}

SummarizeInfo::SummarizeInfo()
{
    // 初始化
    this->alimony = 0;
    this->scholarship = 0;
    this->remuneration = 0;
    this->schoolThings = 0;
    this->lifeThings = 0;
    this->gameCost = 0;
}

SummarizeInfo::~SummarizeInfo()
{
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: SummarizeInfo::getMonth()
*  parameters: void
*  return: void
*  commnent: 输入月份
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SummarizeInfo::getMonth()
{
    system("clear");
    cout << "请输⼊对收⽀类别数据进⾏汇总的⽉份(如：2020-1)：";
    cin >> dateStr;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: SummarizeInfo::getMonthInfo()
*  parameters: void
*  return: void
*  commnent: 获取对应月份的内容
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SummarizeInfo::getMonthInfo(int flag)
{
    // 定义接受文件内容的变量
    string classID;
    string date;
    float money;
    string remark;
    
    // 读取文件中存储的内容
    ifstream ifs;
    ifs.open("./account.txt", ios::in);
    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;
    }
    else{
        while (ifs >> classID && ifs >> date && ifs >> money && ifs >> remark) {
            AccountInfoPer infoPer;
            infoPer.classID = classID;
            infoPer.date = date;
            infoPer.money = money;
            infoPer.remark = remark;
            infoVec.push_back(infoPer);
            int ret = date.find(this->dateStr);
            // date中包含datestr则表明是这个月份数据
            if (!ret) {
//                cout << classID << date << money <<remark << endl;
                this->computeTotalMoney(classID, money);
            }
        }
        ifs.close();
        this->showInfo(1);
        this->showDetailinfo();
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: SummarizeInfo::computeTotalMoney
*  parameters: string classID, float money
*  return: void
*  commnent: 计算各个类别的总费用
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SummarizeInfo::computeTotalMoney(string classID, float money)
{
    if (classID == "a1") {
        this->alimony += money;
    }
    else if(classID == "a2"){
        this->scholarship += money;
    }
    else if(classID == "a3"){
        this->remuneration += money;
    }
    else if(classID == "b1"){
        this->schoolThings += money;
    }
    else if(classID == "b2"){
        this->lifeThings += money;
    }
    else if(classID == "b3"){
        this->gameCost += money;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: SummarizeInfo::computeTotalMoney
*  parameters: string classID, float money
*  return: void
*  commnent: 显示各笔明细
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SummarizeInfo::showDetailinfo()
{
    cout << "是否输出该月的各笔明细(y为输出,其他不输出):";
    char choice;
    cin >> choice;
    
    // 判断是否需要输出,需要的话就输去,否则直接退出
    if (choice == 'y') {
        // 用自定义的比较方式进行排序
        sort(infoVec.begin(), infoVec.end(), myCompare);
        // 按照自定一的哥是打印各笔明细
        this->printFormat();
    }
    else{
        return;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: SummarizeInfo::computeTotalMoney
*  parameters: string classID, float money
*  return: void
*  commnent: 显示支出信息
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SummarizeInfo::showInfo(int flag)
{
    // 将汇总信息显示在终端
    cout << "收入 生活费 " << this->alimony << endl;
    cout << "收入 奖学金 " << this->scholarship << endl;
    cout << "收入 稿费 " << this->remuneration << endl;
    cout << "支出 学习用品 " << this->schoolThings << endl;
    cout << "支出 生活用品 "   << lifeThings << endl;
    cout << "支出 游戏开销 "   << gameCost << endl;
    cout << this->dateStr << "总收入为:" << this->alimony + this->scholarship + this->remuneration << "\t" << this->dateStr << "总支出为:" << this->schoolThings + this->lifeThings + this->gameCost << endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  funcName: SummarizeInfo::computeTotalMoney
*  parameters: string classID, float money
*  return: void
*  commnent: 对各笔明细进行格式化输出
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SummarizeInfo::printFormat()
{
    vector<AccountInfoPer>::iterator it;
    // 遍历容器进行打印输出
    for (it = this->infoVec.begin(); it != this->infoVec.end(); it++) {
        if (it->classID == "a1") {
            cout << "生活费 收入 " << it->date << " " << it->money << " " << it->remark << endl;
        }
        else if (it->classID == "a2"){
            cout << "奖学金 收入 " << it->date << " " << it->money << " " << it->remark << endl;
        }
        else if (it->classID == "a3"){
            cout << "稿费 收入 " << it->date << " " << it->money << " " << it->remark << endl;
        }
        else if (it->classID == "b1"){
            cout << "学习用品 支出 " << it->date << " " << it->money << " " << it->remark << endl;
        }
        else if (it->classID == "b2"){
            cout << "生活用品 支出 " << it->date << " " << it->money << " " << it->remark << endl;
        }
        else if (it->classID == "b3"){
            cout << "游戏 支出 " << it->date << " " << it->money << " " << it->remark << endl;
        }
//        cout << it->classID << it->date << it->money << it->remark << endl;
    }
    cout << "请输入任意键继续...";
    char waitFlag;
    cin >> waitFlag;
    if (waitFlag != ' ')
    {
       return;
    }
    
}
