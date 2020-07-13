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

#ifndef SearchInfo_hpp
#define SearchInfo_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SearchInfo
{
public:
    SearchInfo();
    ~SearchInfo();
    void showSearchMenu();
    void searchMoneyMoreThan();
    void secrchByClassID();
private:
    float totalMoney;
};

#endif /* SearchInfo_hpp */
