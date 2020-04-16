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
    cout << "======================  欢迎来到传智播客机房预约系统  =====================" 
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
void OrderSystemView::loginUserName()
{
	cout << "请输入用户名：" << endl;
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
