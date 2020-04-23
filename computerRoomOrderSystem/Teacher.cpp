#include "Teacher.h"

Teacher::Teacher(int id, string name)
{
    this->id = id;
    this->name = name;
}

Teacher::~Teacher()
{
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void Teacher::validOrder()
{
    int num = 1;
    this->getPersonalLog(2);
    system("clear");
    cout << "待审核的名单如下：" << endl;
    for (vector<AppointInfo>::iterator it = this->AllAppointment.begin();
            it != this->AllAppointment.end(); it++)
    {
        if (it->state == audit)
        {
            cout << num << ". "
            << globalDate[it->date-1] << " "
            << globalTime[it->time-1] << " "
            << it->roomId << "号机房 " << " "
            << "ID:" << it->stuId << " "
            << "姓名:" << it->stuName << " "
            << globalState[it->state] << endl;
            num++;
        }       
    }
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    while (choice < 0 || choice > num)
    {
        cout << "输入错误，请再次选择：" << endl;
    }

    // 将选择的记录设置为通过或不通过
    cout << "1.通过" << endl;
    cout << "2.不" << endl;
    int stateChoice;
    cin >> stateChoice;
    while (stateChoice <= 0 || stateChoice > 2)
    {
        cout << "输入错误请再次输入：" << endl;
        cin >> stateChoice;
    }   
    vector<AppointInfo>::iterator itSetCancle = this->AllAppointment.begin();  
    advance(itSetCancle, choice - 1);  // 提升迭代器，使得只想制定位置
    switch (stateChoice)
    {
    case 1:
        itSetCancle->state = 2;
        break;
    case 2:
        itSetCancle->state = 3;
        break;
    default:
        break;
    }
    
    system("clear");
    cout << itSetCancle->stuName << "的预约已通过：" << endl;
    cout << choice << ". "
            << globalDate[itSetCancle->date-1] << " "
            << globalTime[itSetCancle->time-1] << " "
            << itSetCancle->roomId << "号机房 " << " "
            << "ID:" << itSetCancle->stuId << " "
            << "姓名:" << itSetCancle->stuName << " "
            << globalState[itSetCancle->state] << endl;
            num++;
    this->logNum = getLogNum();

    // 保存到本地
    saveLog(this->logNum, itSetCancle->date, itSetCancle->time, 
            itSetCancle->stuId, itSetCancle->stuName, 
            itSetCancle->roomId, itSetCancle->state);
}
