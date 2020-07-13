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

#ifndef InputStatement_hpp
#define InputStatement_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class InputStatement
{
public:
    InputStatement();
    ~InputStatement();
    void showInputMenu();
    void inputAccount();
};

#endif /* InputStatement_hpp */
