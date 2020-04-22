#pragma once
#include <iostream>
#include <fstream>
#include "OrderSystemView.h"
using namespace std;

enum AppointmentDate
{
    Monday, 
    Tuesday,
    Wednesday,
    Thursday,
    Friday
};

class Identity
{
private:
    /* data */
public:
    string name;
    unsigned int roomMargin[3];
    Identity();
    int judgeFileEmpty(string path);
    void getroomMargin();
    void getRoomGross(unsigned int roomGross[]);
    void getAppointmentCount(unsigned int appointment[]);
    virtual ~Identity();
};
