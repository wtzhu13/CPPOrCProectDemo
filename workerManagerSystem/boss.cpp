#include "boss.h"

Boss::Boss(int id, string name, int dID)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dID;
}

void Boss::showInfo()
{
    cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t\t岗位：" << this->getDeptName()
		<< " \t岗位职责：给员工非分配任务任务" << endl;
}

string Boss::getDeptName()
{
    return string("老板");
}

Boss::~Boss(){}