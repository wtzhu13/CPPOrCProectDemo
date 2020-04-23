# include "test.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
 
using namespace std;

class Base
{
private:
    /* data */
public:
    Base(/* args */);
    void func();
    ~Base();
};

Base::Base(/* args */)
{
}

void Base::func(/* args */)
{
    cout << "hello" << endl;
}

Base::~Base()
{
}

class Son: public Base
{
private:
    /* data */
public:
    Son(/* args */);
    ~Son();
};

Son::Son(/* args */)
{
}

Son::~Son()
{
}

int main(int argc, char const *argv[])
{
    Son s;
    s.func();
    return 0;
}
