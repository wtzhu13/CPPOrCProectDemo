#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <set>
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
    map<int, Competitor> mSpeaker;
    int competitorNum;
    int turn;
    speechManager(/* args */);
    void showMenu();
    void exitSys();
    void getCompetitorNum();
    void test();
    void initSys();
    void createCompetitor();
    void drawLosts();
    ~speechManager();
};


