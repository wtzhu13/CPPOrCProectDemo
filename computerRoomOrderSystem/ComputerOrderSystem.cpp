#include "ComputerOrderSystem.h"
#include "OrderSystemView.h"

ComputerOrderSystem::ComputerOrderSystem(/* args */)
{
    
}

ComputerOrderSystem::~ComputerOrderSystem()
{
}

void ComputerOrderSystem::startSys()
{
    while (1)
    {
        osv.showMainMenu();
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                this->stuSys();
                break;
            case 2:
                this->teacherSys();
                break;
            case 3:
                this->adminSys();
                break;
            case 0:
                this->exitSys();    //  退出系统
                break;
            default:                
                system("clear");
                cout << "选择错误，请再次选择" << endl;
                break;
        }
    }  
}

/*******************************************
* 函数名：void ComputerOrderSystem::exitSys()
* 功能：退出系统
* 参数：
* 返回值：
********************************************/
void ComputerOrderSystem::exitSys()
{
    cout << "欢迎下次使用！" << endl;
    exit(0);    // 退出系统
}

/*******************************************
* 函数名：void ComputerOrderSystem::adminSys()
* 功能：开启管理员系统
* 参数：
* 返回值：
********************************************/
void ComputerOrderSystem::adminSys()
{
    osv.loginUserId();
    int id;
    cin >> id;
    osv.loginPassWord();
    int pwd;
    cin >> pwd;
    string name ;
    if (this->judgeExist(&name, id, pwd, ADMININFOFILE))
    {
        Administrator ad(name);
        while (1)
        {
            int choice = ad.showMenu();
            switch (choice)
            {
            case 1:
                ad.addUser();
                break;
            case 2:
                ad.showUsrInfo();
                break;
            case 3:
                ad.showRoomInfo();
                break;
            case 4:
                ad.clearOrder();
                break;
            case 0: // 注销并退回到主菜单
                system("clear");
                return;
            default:
                break;
            }
        }
    }
    else
    {
        cout << "用户名或密码不正确" << endl;
    }  
}

/*******************************************
* 函数名：bool ComputerOrderSystem::judgeExist(string name, int id, string path)
* 功能：判断用户和密码是否正确
* 参数：string name, int id, string path
* 返回值：bool,用户名和密码都正确返回true，否则返回false
********************************************/
bool ComputerOrderSystem::judgeExist(string * name, int id, int pwd, string path)
{
    ifstream ifs;
    ifs.open(path, ios::in);
    string fName;
    int fPwd, fId;
    while (ifs >> fId && ifs >> fName && ifs >> fPwd)
    {
        // cout << fId << fName << fPwd << endl;
        if (fId == id && fPwd == pwd)
        {
            * name = fName;
            ifs.close();
            // 如果文件中存在该用户名和密码则返回true，并退出遍历
            return true;
        }      
    }
    ifs.close();
    // 文件遍历完了还没有匹配的则返回false
    return false;   
}

/*******************************************
* 函数名：void ComputerOrderSystem::stuSys()
* 功能：学生子系统
* 参数：
* 返回值：
********************************************/
void ComputerOrderSystem::stuSys()
{
    osv.loginUserId();
    int id;
    cin >> id;
    osv.loginPassWord();
    int pwd;
    cin >> pwd;
    string name;
    if (this->judgeExist(&name, id, pwd, STUFILE))
    {
        system("clear");
        cout << "欢迎学生" << name << "登录" << endl;
        Student stu(name, id);
        while (1)
        {
            osv.showStuMenu();
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                stu.appointment();
                break;
            case 2:
                stu.checkAppointment();
                break;
            case 3:
                stu.checkAllAppointment();
                break; 
            case 4:
                stu.cancelOrder();
                break;
            case 0:
                system("clear");
                return;       
            default:
                break;
            }
        }        
    }
    else
    {
        system("clear");
        cout << "用户名或密码不正确,请再次输入" << endl;
    }  
}

/*******************************************
* 函数名：void ComputerOrderSystem::teacherSys()
* 功能：教师子系统
* 参数：
* 返回值：
********************************************/
void ComputerOrderSystem::teacherSys()
{
    osv.loginUserId();
    int id;
    cin >> id;
    osv.loginPassWord();
    int pwd;
    cin >> pwd;
    string name;
    if (this->judgeExist(&name, id, pwd, TEACHERFILE))
    {
        system("clear");
        cout << "欢迎老师" << name << "登录" << endl;
        Teacher teacher(id, name);
        while (1)
        {
            osv.showTeacherMenu();
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                teacher.checkAllAppointment();
                break;
            case 2:
                teacher.validOrder();
                break;
            case 0:
                system("clear");
                return;       
            default:
                break;
            }
        }        
    }
    else
    {
        system("clear");
        cout << "用户名或密码不正确,请再次输入" << endl;
    }   
}
