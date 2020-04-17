#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Identity
{
private:
    /* data */
public:
 string name;
    Identity(){};
    int judgeFileEmpty(string path)
    {
        ifstream ifs;
        ifs.open(path, ios::in);	
        if (!ifs.is_open())
        {
            cout << "文件打开失败" << endl;
            return -1;
        }
        char ch;
        ifs >> ch;
        if (ifs.eof())	// 如果数组为空，则workerAray = NULL并退出
        {
            return 1;
        }
        return 0;
    }
    virtual ~Identity(){};
};
