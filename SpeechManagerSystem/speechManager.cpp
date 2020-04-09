#include "speechManager.h"

speechManager::speechManager(/* args */)
{
	this->initSys();
	this->getCompetitorNum();
}

speechManager::~speechManager()
{}

/*******************************************
* 函数名：void speechManager::initSys()
* 功能：系统初始化，初始是保证各个容器都为空
* 参数：无
* 返回值：无
********************************************/
void speechManager::initSys()
{
	// 清空容器
	this->vPreContest.clear();  
	this->vIntermediaryHeat.clear();
	this->vVictory.clear();
	this->mSpeaker.clear();
	this->turn = 1;
}

/*******************************************
* 函数名：void speechManager::showMenu()
* 功能：显示主菜单
* 参数：无
* 返回值：无
********************************************/
void speechManager::showMenu()
{
    cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

/*******************************************
* 函数名：void speechManager::exit()
* 功能：退出系统
* 参数：无
* 返回值：无
********************************************/
void speechManager::exitSys()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}

/*******************************************
* 函数名：void speechManager::getCompetitorNum()
* 功能：获取参赛人员数
* 参数：无
* 返回值：无
********************************************/
void speechManager::getCompetitorNum()
{
	ifstream ifs;
	string name;
	int index = 0;
	ifs.open(COMPETITOELISTPATH, ios::in);
	if (!ifs.is_open())
	{
		cout << "getCompetitorNum文件代开失败" << endl;
	}
	while (ifs >> name)
	{
		index++;
	}
	this->competitorNum = index;
	ifs.close();
}

/*******************************************
* 函数名：test
* 功能：测试函数
* 参数：
* 返回值：
********************************************/
void speechManager::test()
{
	this->drawLosts();
	for (vector<int>::iterator it = vPreContest.begin(); it != vPreContest.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*******************************************
* 函数名：void speechManager::createCompetitor()
* 功能：创建员工,并将员工姓名和ID存入map中
* 参数：
* 返回值：
********************************************/
void speechManager::createCompetitor()
{
	ifstream ifs;
	string name;
	int index = 10001;
	ifs.open(COMPETITOELISTPATH, ios::in);
	if (!ifs.is_open())
	{
		cout << "getCompetitorNum文件代开失败" << endl;
	}
	while (ifs >> name)
	{
		// 将参赛人员与ID匹配放入map中
		this->mSpeaker.insert(pair<int, Competitor>(index, Competitor(name)));
		index++;
	}
	this->competitorNum = index;
	ifs.close();
}

/*******************************************
* 函数名：void speechManager::drawLosts()
* 功能：通过抽签决定参赛顺序
* 参数：
* 返回值：
********************************************/
void speechManager::drawLosts()
{
	cout << "第 << " << this->turn << " >> 轮比赛选手正在抽签"<<endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (turn == 1)
	{
		random_shuffle(vPreContest.begin(), vPreContest.end());
		for (vector<int>::iterator it = vPreContest.begin(); it != vPreContest.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;	
	}	
}
