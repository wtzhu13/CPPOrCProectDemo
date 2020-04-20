#include "Student.h"

Student::Student(string name, int id)
{
    this->name = name;
    this->id = id;
    this->logNum = 0;
    this->appointmentState = audit;
    this->initStuSys();
}

Student::~Student()
{
}

/*******************************************
* 函数名：
* 功能：初始化
* 参数：
* 返回值：
********************************************/
void Student::initStuSys()
{
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
        this->logNum ++;
    }
   ifs.close(); 
}

/*******************************************
* 函数名：
* 功能：学生申请预约
* 参数：
* 返回值：
********************************************/
void Student::appointment()
{
    // 获取预约信息
    osv.showAppointmenDate();
    int choiceDate, choiceTime, choiceRoom;
    cin >> choiceDate;
    osv.showAppointmenTime();
    cin >> choiceTime;
    this->getroomMargin();
    osv.showAppointmenRoom(this->roomMargin);
    cin >> choiceRoom;

    // 检查相同时间段是否有过预约
    int ret = this->checkSameTimeAppointment(choiceDate, choiceTime, this->id);
    cout << "相同时间有预约为1：" << ret <<endl;

    if (!ret)
    {
        cout << "您已成功申请预约！" << endl;
        logNum ++;
        // 将预约信息保存至本地
        ofstream ofs;
        ofs.open(ORDERFILE, ios::app);
        ofs << logNum << " " << choiceDate << " " << choiceTime << " " << this->id
            << " " << this->name << " " << choiceRoom << " " << this->appointmentState << endl;
        ofs.close();
    }
    else
    {
        cout << "您无法预约该时间段" << endl;
    } 
}

/*******************************************
* 函数名：int Student::checkSameTimeAppointment(int date, int time, int stuId)
* 功能：查看同时段改同学的预约情况
* 参数：日期，时间，学生ID
* 返回值：1 相同时间段该同学有过申请，0 改时间段该学生没有申请
********************************************/
int Student::checkSameTimeAppointment(int date, int time, int stuId)
{
    ifstream ifs;
    ifs.open(ORDERFILE, ios::in);
    int fId, fData, fTime, fStuId, fRoomId, fState;
    string fName;
    while (ifs >> fId && ifs >> fData
    && ifs >> fTime && ifs >> fStuId
    && ifs >> fName && ifs >> fRoomId
    && ifs >> fState)   //  提取每条日志的各种状态
    {
        // 相同时间，相同ID，且状态不是取消，则不能再次申请
        if (fStuId == stuId && fData == date && fTime == time && fState != cancle)
        {
            ifs.close();
            return 1;
        }       
    }
    ifs.close();
    return 0;
}

/*******************************************
* 函数名：
* 功能：查看预约信息
* 参数：
* 返回值：
********************************************/
void Student::checkAppointment()
{

}

/*******************************************
* 函数名：
* 功能：查看所有人预约
* 参数：
* 返回值：
********************************************/
void Student::checkAllAppointment()
{

}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void Student::cancelOrder()
{

}
