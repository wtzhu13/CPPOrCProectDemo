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
    osv.loginUserName();
    string name;
    cin >> name;
    osv.loginPassWord();
    int pwd;
    cin >> pwd;
    if (this->judgeExist(name, pwd, "adminConfig.cfg"))
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
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 0: // 注销并退回到主菜单
                return;
                break;
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
bool ComputerOrderSystem::judgeExist(string name, int pwd, string path)
{
    ifstream ifs;
    ifs.open(path, ios::in);
    string fName;
    int fPwd, fId;
    while (ifs >> fId && ifs >> fName && ifs >> fPwd)
    {
        cout << fId << fName << fPwd << endl;
        if (fName == name && fPwd == pwd)
        {
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
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void ComputerOrderSystem::stuSys()
{
    osv.loginUserName();
    string name;
    cin >> name;
    osv.loginPassWord();
    int pwd;
    cin >> pwd;
    if (this->judgeExist(name, pwd, STUFILE))
    {
        cout << "登录成功！" << endl;
    }
    else
    {
        cout << "用户名或密码不正确" << endl;
    }  
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void ComputerOrderSystem::teacherSys()
{
    osv.loginUserName();
    string name;
    cin >> name;
    osv.loginPassWord();
    int pwd;
    cin >> pwd;
    if (this->judgeExist(name, pwd, TEACHERFILE))
    {
        cout << "登录成功！" << endl;
    }
    else
    {
        cout << "用户名或密码不正确" << endl;
    }  
}
