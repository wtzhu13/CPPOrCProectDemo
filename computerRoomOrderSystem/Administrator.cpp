#include "Administrator.h"

Administrator::Administrator(string name)
{
    this->name = name;
}

Administrator::~Administrator()
{
}

/*******************************************
* 函数名：void Administrator::showMenu()
* 功能：显示管理员的菜单
* 参数：
* 返回值：
********************************************/
int Administrator::showMenu()
{
    osv.showAdminMenu(this->name);
    int choice;
    cin >> choice;
    return choice;
}

/*******************************************
* 函数名：
* 功能：添加用户信息
* 参数：
* 返回值：
********************************************/
void Administrator::addUser()
{
    osv.showAddUsrMenu();
    int choice;
    string path;
    cin >> choice;
    switch (choice)
    {
        case 1:
            cout << "请输入学号：" << endl;
            path = STUFILE;
            break;
        case 2:
            cout << "请输入教师编号：" << endl;
            path = TEACHERFILE;
            break;
        default:
            break;
    }
    int id;
    cin >> id;
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    int pwd;
    cout << "请输入密码：" << endl;
    cin >> pwd;
    this->saveUsrInfo(path, id, name, pwd);
}

/*******************************************
* 函数名：void Administrator::saveUsrInfo(string path, int id, int pwd)
* 功能：保存添加的用户信息到本地
* 参数：本地文件地址，用户名，密码
* 返回值：无
********************************************/
void Administrator::saveUsrInfo(string path, int id, string name, int pwd)
{
    ofstream ofs;
    ofs.open(path, ios::app);
    ofs << id << " " << name << " " << pwd << endl; 
    ofs.close();
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void Administrator::showUsrInfo()
{
    osv.showUsrInfoMenu();
    int choice;
    string path;
    cin >> choice;
    switch (choice)
    {
    case 1:
        path = STUFILE;
        cout << "所有学生信息：" << endl;
        break;
    case 2:
        path = TEACHERFILE;
        cout << "所有老师信息：" << endl;
        break;
    default:
        break;
    }
    int id, pwd;
    string name;
    int ret = this->judgeFileEmpty(path);
    if (!ret)
    {
        ifstream ifs;
        ifs.open(path, ios::in);
        if (!ifs.is_open())
        {
            cout << path << " open err!" << endl;
        }
        while (ifs >> id && ifs >> name && ifs >> pwd)
        {
            cout << "编号：" << id << " 姓名：" << name << " 密码：" << pwd << endl;
        }   
        ifs.close();
    }  
    else if (ret == 1)
    {
        cout << "暂无数据，请先添加" << endl;
    }
    else
    {
        return;
    }   
}


