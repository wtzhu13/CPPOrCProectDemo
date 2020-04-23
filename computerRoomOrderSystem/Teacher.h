#pragma once 
#include <iostream>
#include "OrderSystemView.h"
#include "Identity.h"
using namespace std;

class Teacher : public Identity
{
private:
    /* data */
public:
    OrderSystemView osv;
    Teacher(int id, string name);
    void validOrder();
    ~Teacher();
};

