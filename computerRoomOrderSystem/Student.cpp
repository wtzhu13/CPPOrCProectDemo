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
    logNum ++;

    // 将预约信息保存至本地
    ofstream ofs;
    ofs.open(ORDERFILE, ios::app);
    ofs << logNum << " " << choiceDate << " " << choiceTime << " " << this->id
        << " " << this->name << " " << choiceRoom << " " << this->appointmentState << endl;
    ofs.close();
}

/*******************************************
* 函数名：
* 功能：查看同时段改同学的预约情况
* 参数：
* 返回值：
********************************************/
void Student::checkSameTimeAppointment()
{

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
