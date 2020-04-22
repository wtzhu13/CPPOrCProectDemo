#include "global.h"

string globalDate[] = {"周一", "周二", "周三", "周四", "周五"};
string globalTime[] = {"上午", "下午"};
string globalState[] = {"审核中", "取消", "通过", "拒绝"};

/*******************************************
* 函数名：
* 功能：保存一条日志到本地
* 参数：
* 返回值：
********************************************/
void saveLog(int logNumSave, int dateSave, int timeSave, int stuIdSave, 
string nameSave, int roomSave, int StateSave)
{
    ofstream ofs;
        ofs.open(ORDERFILE, ios::app);
        ofs << logNumSave << " " << dateSave << " " << timeSave << " " << stuIdSave
            << " " << nameSave << " " << roomSave << " " << StateSave << endl;
        ofs.close();
}

/*******************************************
* 函数名：
* 功能：获取日志文件的行数
* 参数：
* 返回值：
********************************************/
int getLogNum()
{
    int logNum = 0;
    // 获取申请机房日志
    ifstream ifs;
    ifs.open(ORDERFILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "预约文件打开失败" << endl;
    }
    char buf[1024] = { 0 };
    while (ifs.getline(buf,sizeof(buf)))
    {
        //有多少行就有多少条记录
        logNum ++;
    }
   ifs.close(); 
   return logNum;
}

