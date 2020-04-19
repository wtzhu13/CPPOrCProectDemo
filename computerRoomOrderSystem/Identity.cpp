#include "Identity.h"

Identity::Identity()
{
}

Identity::~Identity()
{

}

/*******************************************
* 函数名：
* 功能：判断文件是否为空
* 参数：
* 返回值：
********************************************/
int Identity::judgeFileEmpty(string path)
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

/*******************************************
* 函数名：
* 功能：获取机房余量
* 参数：
* 返回值：
********************************************/
void Identity::getroomMargin()
{
    // 获取机房总量
    unsigned int roomGross[3] = {0};
    unsigned int appointment[3] = {0};
    this->getRoomGross(roomGross);
    this->getAppointmentCount(appointment);
    for (int i = 0; i < 3; i++)
    {
        roomMargin[i] = roomGross[i] - appointment[i];
    }
}

/*******************************************
* 函数名：
* 功能：获取机房机位总量
* 参数：
* 返回值：
********************************************/
void Identity::getRoomGross(unsigned int roomGross[])
{
    ifstream ifs;
    ifs.open(ROMMINFOFILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    int roomId, roomCap;
    while (ifs >> roomId && ifs >> roomCap)
    {
        roomGross[--roomId] = roomCap;
    }  
    ifs.close();
}

/*******************************************
* 函数名：
* 功能：获取已预约的信息
* 参数：
* 返回值：
********************************************/
void Identity::getAppointmentCount(unsigned int appointment[])
{
    ifstream ifs;
    ifs.open(ORDERFILE, ios::in);
    int logNum, date, time, stuId, roomId, state;
    string name;
    while (ifs >> logNum && ifs >>date && ifs >>time
        && ifs >> stuId && ifs >> name && ifs >> roomId 
        && ifs >> state)
    {
        switch (roomId)
        {
        case 1:
            if (state == audit || state == success) // 在审核中或者成功预约则为占位
            {
                appointment[0]++;
            }           
            break;
        case 2:
            if (state == audit || state == success)
            {
                appointment[1]++;
            } 
            break;
        case 3:
            if (state == audit || state == success)
            {
                appointment[2]++;
            } 
            break;
        default:
            break;
        }
    }
}
