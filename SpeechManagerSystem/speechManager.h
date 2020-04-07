#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "competitor.h"
using namespace std;

#define COMPETITOELISTPATH "competitorList.txt"

class speechManager
{
private:
    /* data */
public:
    vector<int> vPreContest;
    vector<int> vIntermediaryHeat;
    vector<int> vVictory;
    map<int, Competitor> m_Speaker;
    int competitorNum;
    speechManager(/* args */);
    void showMenu();
    void exitSys();
    void getCompetitorNum();
    void test();
    void initSys();
    void createCompetitor();
    ~speechManager();
};


