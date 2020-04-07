#pragma once
#include <iostream>
#include <string>
using namespace std;

class Competitor
{
public:
    string name;
    int id;
    int score;
    Competitor(string name, int id);
    ~Competitor();
};


