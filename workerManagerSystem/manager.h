#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Manager : public Worker
{
public:
    Manager(int id, string name, int dID);
    virtual void showInfo();
    virtual string getDeptName();
    ~Manager();

};