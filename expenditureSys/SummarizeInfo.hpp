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

#ifndef SummarizeInfo_hpp
#define SummarizeInfo_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct AccountInfoPer{
    string classID;
    string date;
    float money;
    string remark;
}AccountInfoPer;

class SummarizeInfo
{
public:
    SummarizeInfo();
    ~SummarizeInfo();
    void getMonth();
    void getMonthInfo(int flag);
    void computeTotalMoney(string classID, float money);
    void showDetailinfo();
    void showInfo(int flag);
    void printFormat();
private:
    float alimony;
    float scholarship;
    float remuneration;
    float schoolThings;
    float lifeThings;
    float gameCost;
    string dateStr;
    vector<AccountInfoPer> infoVec;
};

#endif /* SummarizeInfo_hpp */
