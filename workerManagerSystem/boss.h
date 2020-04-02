#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class Boss : public Worker
{
private:
    /* data */
public:
    Boss(int id, string name, int dID);
    virtual void showInfo();
    virtual string getDeptName();
    ~Boss();
};
