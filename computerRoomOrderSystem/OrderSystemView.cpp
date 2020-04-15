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
}