#pragma once 
#include <iostream>
#include "OrderSystemView.h"
#include "Identity.h"
using namespace std;

class Teacher : Identity
{
private:
    /* data */
public:
    OrderSystemView osv;
    Teacher(/* args */);
    void login();
    ~Teacher();
};

