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
    unsigned int appointment[5][2][3] = {0};
    this->getRoomGross(roomGross);
    this->getAppointmentCount(appointment);
    for (int a = 0; a < 5; a++)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                roomMargin[a][i][j] = roomGross[j] - appointment[a][i][j];
            }
        }
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
* 待改进，目前计算的一整天的剩余量，应该一天还分上午和下午，所以有六个数
********************************************/
void Identity::getAppointmentCount(unsigned int appointment[5][2][3])
{
    this->getPersonalLog(2);
    for (vector<AppointInfo>::iterator it = this->AllAppointment.begin();
            it != this->AllAppointment.end(); it++)
    {
            if (it->state == audit || it->state == success)
            {
                appointment[it->date - 1][it->time - 1][it->roomId - 1]++;
            }
    }
}

/*******************************************
* 函数名：
* 功能：获取个人的记录
* 参数：
* 返回值：
********************************************/
void Identity::getPersonalLog(int flag)
{
    ifstream ifs;
    ifs.open(ORDERFILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    int fId, fDate, fTime, fStuId, fRoomId, fState;
    string fName;
    // int tempFlag = 0;
    while (ifs >> fId && ifs >> fDate
    && ifs >> fTime && ifs >> fStuId
    && ifs >> fName && ifs >> fRoomId
    && ifs >> fState)   //  提取每条日志的各种状态
    {
        // tempFlag = 0;
        AppointInfo tempAppointInfo;    // 临时存放每一条日志信息
        tempAppointInfo.date = fDate;
        tempAppointInfo.time = fTime;
        tempAppointInfo.stuId = fStuId;
        tempAppointInfo.stuName = fName;
        tempAppointInfo.roomId = fRoomId;
        tempAppointInfo.state = fState; 
        switch (flag)
        {
        case 1:
            this->filterSelfLog(tempAppointInfo);
            break;
        case 2:
            this->filterAllfLog(tempAppointInfo);
            break;
        default:
            break;
        }        
    }
    ifs.close(); 
}

/*******************************************
* 函数名：
* 功能：过滤本人记录
* 参数：
* 返回值：
********************************************/
void Identity::filterSelfLog(AppointInfo tempAppointInfo)
{
    int tempFlag = 0;
    if (tempAppointInfo.stuId == this->id) // id相同就可以加入容器
        {
            for (vector<AppointInfo>::iterator it = this->vMyAppointment.begin();
         it != this->vMyAppointment.end(); it++) 
            {
                // 同一个人在同意时间的预约状态只能有一个
                if (it->date == tempAppointInfo.date && it->time == tempAppointInfo.time && it->roomId == tempAppointInfo.roomId)
                {
                    it->state = tempAppointInfo.state;
                    tempFlag = 1;
                    break;
                }                             
	        } 
            if (!tempFlag)
            {
                this->vMyAppointment.push_back(tempAppointInfo);
            }                      
        } 
}

/*******************************************
* 函数名：
* 功能：查看所有人预约
* 参数：
* 返回值：
********************************************/
void Identity::filterAllfLog(AppointInfo tempAppointInfo)
{
    // this->AllAppointment.clear();
    int tempFlag = 0;   
    for (vector<AppointInfo>::iterator it = this->AllAppointment.begin();
            it != this->AllAppointment.end(); it++) 
    {
        
        // 同一个人在同意时间的预约状态只能有一个
        if (it->date == tempAppointInfo.date &&
            it->time == tempAppointInfo.time && 
            it->roomId == tempAppointInfo.roomId &&
            it->stuId == tempAppointInfo.stuId)
        {
            it->state = tempAppointInfo.state;
            tempFlag = 1;
            break;
        }                             
    } 
    if (!tempFlag)
    {
        this->AllAppointment.push_back(tempAppointInfo);
    }                      
    
}

/*******************************************
* 函数名：
* 功能：查看所有人预约
* 参数：
* 返回值：
********************************************/
void Identity::checkAllAppointment()
{
    system("clear");
    if (this->judgeFileEmpty(ORDERFILE))
    {
        cout << "暂无预约！" << endl;
        return;
    } 
    AllAppointment.clear(); 
    cout << "预约信息：" << endl;
    this->getPersonalLog(2);
    for (vector<AppointInfo>::iterator it = this->AllAppointment.begin();
            it != this->AllAppointment.end(); it++)
    {
        cout << globalDate[it->date-1] << " "
            << globalTime[it->time-1] << " "
            << it->roomId << "号机房 " << " "
            << "ID:" << it->stuId << " "
            << "姓名:" << it->stuName << " "
            << globalState[it->state] << endl;
    }  
    waitKeyBoard();
}