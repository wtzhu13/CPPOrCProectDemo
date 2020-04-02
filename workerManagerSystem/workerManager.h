#pragma once
#include <iostream>
#include <unistd.h>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define DATAFILEPATH "workerInfo.txt"

class workerManager
{
public:
    workerManager();
    void showMenu();
    void exitSys();
    void addWorker();
    void saveDataLocal(int id, string name, int departmentNum);
    void getWorkerCount(int *count);
    void initArray(int *countP);
    void deleteById();
    int IsExist(int id);
    void deleteWorker(int index);
    void test();
    void showWorker();
    void modifyWorkerInfo();
    void findWorker();
    void searcheByID();
    void searchByName();
    void waitQuit();
    void sortById();
    void clear();
    void clearFile();
    ~workerManager();
    int workerNum;
    Worker ** workerAray;
};


