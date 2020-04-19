# pragma once
#include <iostream>
#include <string>
using namespace std;

class OrderSystemView
{
private:
    /* data */
public:
    OrderSystemView(/* args */);
    void showMainMenu();
    void loginUserId();
    void loginPassWord();
    void showAdminMenu(string name);
    void showAddUsrMenu();
    void showUsrInfoMenu();
    ~OrderSystemView();
};


