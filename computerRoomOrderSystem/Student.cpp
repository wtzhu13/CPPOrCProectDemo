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
    cout << "请输入申请预约的时间：" << endl;
    osv.showAppointmenDate();
    int choiceDate, choiceTime, choiceRoom;
    cin >> choiceDate;
    cout << "请输入申请预约的时间段：" << endl;
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
    vMyAppointment.clear(); 
    cout << "预约信息：" << id << endl;
    this->getPersonalLog();   
    osv.showPersonalAppointment(this->vMyAppointment);
}

/*******************************************
* 函数名：
* 功能：获取个人的记录
* 参数：
* 返回值：
********************************************/
void Student::getPersonalLog()
{
    ifstream ifs;
    ifs.open(ORDERFILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    int fId, fDate, fTime, fStuId, fRoomId, fState;
    string fName;
    int tempFlag = 0;
    while (ifs >> fId && ifs >> fDate
    && ifs >> fTime && ifs >> fStuId
    && ifs >> fName && ifs >> fRoomId
    && ifs >> fState)   //  提取每条日志的各种状态
    {
        tempFlag = 0;
        AppointInfo tempAppointInfo;    // 临时存放每一条日志信息
        tempAppointInfo.date = fDate;
        tempAppointInfo.time = fTime;
        tempAppointInfo.roomId = fRoomId;
        tempAppointInfo.state = fState; 
        if (fStuId == this->id) // id相同就可以加入容器
        {
            for (vector<AppointInfo>::iterator it = this->vMyAppointment.begin();
         it != this->vMyAppointment.end(); it++) 
            {
                // 同一个人在同意时间的预约状态只能有一个
                if (it->date == fDate && it->time == fTime && it->roomId == fRoomId)
                {
                    it->state = fState;
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
    ifs.close(); 
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
* 功能：取消预约，取消的只能是状态为审核中，通过审核的
* 参数：
* 返回值：
********************************************/
void Student::cancelOrder()
{
    vMyAppointment.clear();
    // 获取一下记录
    this->getPersonalLog();
    vector<AppointInfo> canBeCancle;
    AppointInfo canBeCancleInfo;
    cout << "您的可取消预约：" << endl;
    for (vector<AppointInfo>::iterator it = this->vMyAppointment.begin();
        it != this->vMyAppointment.end(); it++) 
        {
            if (it->state == audit || it->state == success)
            {
                canBeCancleInfo.date = it->date;
                canBeCancleInfo.time = it->time;
                canBeCancleInfo.roomId = it->roomId;
                canBeCancleInfo.state = it->state;
                canBeCancle.push_back(canBeCancleInfo);
                
            }                                              
        } 
    for (vector<AppointInfo>::iterator it = canBeCancle.begin();
        it != canBeCancle.end(); it++) 
        {
            cout << globalDate[it->date-1] << " "
                 << globalTime[it->time-1] << " "
                 << it->roomId << "号机房 "
                 << globalState[it->state] << endl;
        }
    cout << "请输入日期" << endl;
    osv.showAppointmenDate();
    int inputDate;
    cin >> inputDate;
    cout << "请输入时间" << endl;
    osv.showAppointmenTime();
    int inputTime;
    cin >> inputTime;
    cout << "请输入机房" << endl;
    int inputRoomId;
    cin >> inputRoomId;

    /***
     * 
     * 需要添加一个输入的判断，判断输入是否和可取消的吻合
     * 
     */


    for (vector<AppointInfo>::iterator it = canBeCancle.begin();
        it != canBeCancle.end(); it++) 
        {
            if (it->date == inputDate && it->time == inputTime
            && it->roomId == inputRoomId)
            {
                it->state = cancle;
            }  
        }
    for (vector<AppointInfo>::iterator it = canBeCancle.begin();
        it != canBeCancle.end(); it++) 
        {
            cout << globalDate[it->date-1] << " "
                 << globalTime[it->time-1] << " "
                 << it->roomId << "号机房 "
                 << globalState[it->state] << endl;
        }
    /***
     * 
     * 需要添加一个保存到本地的功能
     * 
     */
