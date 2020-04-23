#include "OrderSystemView.h"

OrderSystemView::OrderSystemView(/* args */)
{
}

OrderSystemView::~OrderSystemView()
{
}

/*******************************************
* 函数名：void OrderSystemView::showMainMenu()
* 功能：显示主菜单
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showMainMenu()
{
    cout << "======================  欢迎来到CAUC机房预约系统  =====================" 
         << endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
    cout << "请输入您的选择：";
}

/*******************************************
* 函数名：void OrderSystemView::loginUserName()
* 功能：显示用户名窗口
* 参数：
* 返回值：
********************************************/
void OrderSystemView::loginUserId()
{
	cout << "请输入用户名ID：" << endl;
}

/*******************************************
* 函数名：void OrderSystemView::loginPassWord()
* 功能：显示密码窗口
* 参数：
* 返回值：
********************************************/
void OrderSystemView::loginPassWord()
{
	cout << "请输入用户密码：" << endl;
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showAdminMenu(string name)
{
	cout << "欢迎管理员："<< name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

/*******************************************
* 函数名：void OrderSystemView::showAddUsrMenu()
* 功能：显示添加用户菜单
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showAddUsrMenu()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
}

/*******************************************
* 函数名：
* 功能：显示查看账号时的提示信息
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showUsrInfoMenu()
{
	cout << "请选择查看内容" << endl;
	cout << "1、查看学生账号" << endl;
	cout << "2、查看老师账号" << endl;
}

/*******************************************
* 函数名：
* 功能：显示学生系统视图
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showStuMenu()
{
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约               |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

/*******************************************
* 函数名：
* 功能：显示预约日期菜单
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showAppointmenDate()
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
}

/*******************************************
* 函数名：
* 功能：显示预约时间
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showAppointmenTime()
{
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
}

/*******************************************
* 函数名：
* 功能：显示机房预约信息
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showAppointmenRoom(int choiceDate, int choiceTime, unsigned int num[5][2][3])
{
	cout << "机房信息" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << ".机房" << i+1 << "剩余容量："<< num[choiceDate-1][choiceTime-1][i] << endl;
	}	
	cout << "请选择机房：" << endl;
}

/*******************************************
* 函数名：
* 功能：显示个人的预约
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showPersonalAppointment(vector<AppointInfo> v)
{
	if (v.size() == 0)
	{
		cout << "无预约记录" << endl;
		return;
	}
	
	for (vector<AppointInfo>::iterator it = v.begin();
         it != v.end(); it++) 
            {
                cout << globalDate[it->date-1] << " "
                     << globalTime[it->time-1] << " "
                     << it->roomId << "号机房 "
                     << globalState[it->state] << endl;
	        }   
}

/*******************************************
* 函数名：
* 功能：显示老师菜单
* 参数：
* 返回值：
********************************************/
void OrderSystemView::showTeacherMenu()
{
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
