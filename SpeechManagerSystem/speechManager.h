#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <algorithm>
#include <deque>
#include <iomanip>
#include "competitor.h"
using namespace std;

#define COMPETITOELISTPATH "competitorList.txt"

class speechManager
{
private:
    /* data */
public:
    vector<int> vPreContest;
    vector<int> vFirstGroup;
    vector<int> vSecondGroup;
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
    void startCompetition();
    void getKeyboard();
    double computeScore();
    void giveAMark(vector<int> & vCP);
    void printResult(vector<int> & vCP);
    void printCompetitorId(vector<int> & vCP);
    void promoted(vector<int> & contestant, vector<int> & vV);
    void writeCSV();
    void loadRecord();
    ~speechManager();
};

// 创建仿函数用于排序
class MyCompare
{
public:
    bool operator()(const Competitor &p1, const Competitor &p2)
    {
        return p1.score > p2.score;
    }
};


