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

    // 判断账户是否存在
    switch (this->judgeAccountExit(path, id))
    {
    case -1:
        cout << "文件打开失败！" << endl;
        break;
    case 0:
        this->saveUsrInfo(path, id, name, pwd);
        break;
    case 1:
        cout << "该账户已存在" << endl;
        break;
    default:
        break;
    }   
}

/*******************************************
* 函数名：int Administrator::judgeAccountExit(string path, int id)
* 功能：添加账户是判断用户是否存在
* 参数：
* 返回值：-1:文件打开失败 0:账户不存在 1:账户已存在
********************************************/
int Administrator::judgeAccountExit(string path, int id)
{
    ifstream ifs;
    ifs.open(path, ios::in);
    if (!ifs.is_open())
    {
        return -1;
    }
    int fId;
    string fName;
    while (ifs >> fId)
    {
        // ID不可以重复，姓名和密码可能相同，所以只需判断ID是否在文件中存在
        if (fId == id)
        {
            return 1;
        }      
    }    
    ifs.close();
    return 0;
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
* 函数名：void Administrator::showUsrInfo()
* 功能：查看账号信息
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
        // 如果文件不为空则将数据读出来并显示
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
        // 文件为空则提示
        cout << "暂无数据，请先添加" << endl;
    }
    else
    {
        // 文件打开失败直接退出
        return;
    }   
}

/*******************************************
* 函数名：void Administrator::showRoomInfo()
* 功能：查看机房信息
* 参数：
* 返回值：
********************************************/
void Administrator::showRoomInfo()
{
    ifstream ifs;
    ifs.open(ROMMINFOFILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    int roomId, roomCap;
    while (ifs >> roomId && ifs >> roomCap)
    {
        cout << "机房" << roomId << "\t容量" << roomCap << "人" << endl;
    }
    ifs.close();
}

/*******************************************
* 函数名：void Administrator::clearOrder()
* 功能：清空预约信息
* 参数：
* 返回值：
********************************************/
void Administrator::clearOrder()
{
    ofstream ofs;
    ofs.open(ORDERFILE, ios::out);
    ofs.close();
    cout << "预约信息已清空！" << endl;
}

