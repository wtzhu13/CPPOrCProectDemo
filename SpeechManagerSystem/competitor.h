#pragma once
#include <iostream>
#include <string>
using namespace std;

class Competitor
{
public:
    string name;
    double score;
    int id;
    Competitor(string name, int id);
    ~Competitor();
};


