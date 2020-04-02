#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象基类
class Worker
{
public:

	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	virtual ~Worker() // 虚析构函数必须有，如果用纯虚析构函数则必须要在后面定义函数体
	{}

	int m_Id; //职工编号
	string m_Name; //职工姓名
	int m_DeptId; //职工所在部门名称编号
};