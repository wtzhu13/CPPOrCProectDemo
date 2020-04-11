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
	this->createCompetitor();
	map<int, Competitor>::iterator pos = mSpeaker.find(10001);
	for (map<int, Competitor>::iterator it = mSpeaker.begin(); it != mSpeaker.end(); it++)
	{
		map<int, Competitor>::iterator pos = mSpeaker.find(it->first);
		if (pos != mSpeaker.end())
		{
			cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second.name << endl;
		}
		else
		{
			cout << "未找到元素" << endl;
		}
		cout << endl;	
	}	
	this->drawLosts();
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
		this->mSpeaker.insert(pair<int, Competitor>(index, Competitor(name, index)));
		this->vPreContest.push_back(index);
		index++;
	}
	this->competitorNum = index;
	ifs.close();
}

/*******************************************
* 函数名：void speechManager::drawLosts()
* 功能：通过抽签决定参赛顺序
* 参数：无
* 返回值：无
********************************************/
void speechManager::drawLosts()
{
	cout << "第 << " << this->turn << " >> 轮比赛选手正在抽签"<<endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (turn == 1)
	{
		random_shuffle(vPreContest.begin(), vPreContest.end()); // 将参赛人员顺序打乱
		int count = 1;
		bool flag = true;
		cout << "第一组人员：";
		for (vector<int>::iterator it = vPreContest.begin(); it != vPreContest.end(); it++)
		{
			if (count <= 6)
			{	
				cout << *it << " ";
				vFirstGroup.push_back(*it);
			}
			else
			{
				if (flag)
				{
					cout << "\n第二组人员：";
					flag = false;
				}				
				cout << *it << " ";
				vSecondGroup.push_back(*it);
			}
			count++;		
		}
		cout << endl;	
		return;
	}	
}

/*******************************************
* 函数名：void speechManager::startCompetition()
* 功能：开始比赛
* 参数：无
* 返回值：无
********************************************/
void speechManager::startCompetition()
{
	system("clear");
	this->createCompetitor();	// 创建初始参赛人员名单
	this->printCompetitorId(vPreContest); // 打印参赛人员ID
	cout << endl;	  
	this->drawLosts();	// 第一轮抽签分组	
	cout << "------------- 第"<< this->turn << "轮正式比赛开始：------------- " << endl;
	this->getKeyboard();	// 等待键盘输入
	system("clear");
	cout << "------------- 第"<< this->turn << "轮比赛结果：------------- " << endl;
	this->giveAMark(vPreContest);		// 给参赛选手打分，最终的分数
	cout << "第一组得分情况" << endl;
	this->printResult(vFirstGroup);		// 显示比赛结果
	cout << "\n第二组得分情况" << endl;
	this->printResult(vSecondGroup);		// 显示比赛结果
	this->getKeyboard();	
	cout << "------------- 第"<< this->turn << "轮晋级人员：------------- " << endl;
	this->promoted(vFirstGroup, vIntermediaryHeat);
	this->promoted(vSecondGroup, vIntermediaryHeat);
	this->turn ++ ;
	cout << "------------- 第"<< this->turn << "轮参赛人员：------------- " << endl;
	this->printCompetitorId(vIntermediaryHeat);
	this->getKeyboard();
	system("clear");
	cout << "------------- 第"<< this->turn << "轮比赛结果：------------- " << endl;
	this->giveAMark(vIntermediaryHeat);
	this->printResult(vIntermediaryHeat);
	system("clear");
	cout << "------------- 比赛胜出者人员：------------- " << endl;
	this->promoted(vIntermediaryHeat, vVictory);
	this->writeCSV();
}

/*******************************************
* 函数名：void speechManager::getKeyboard()
* 功能：获取键盘输入，任意键继续
* 参数：无
* 返回值：无
********************************************/
void speechManager::getKeyboard()
{
	cout << "请输入任意字符继续...";
	char keyInput;
	cin >> keyInput;
}

/*******************************************
* 函数名：double speechManager::computeScore()
* 功能：给每个选手打分，随机生成是个分数，去掉最高分和最低分后计算平均分
* 参数：无
* 返回值：无
********************************************/
double speechManager::computeScore()
{
	deque<int> sScore;	// 定义临时容器存放分数，便于排序和删除
	for (int i = 0; i < 10; i++)
	{
		sScore.push_back(rand() % 41 + 60); // 生成一个60-100之间的分数
	}
	sort(sScore.begin(), sScore.end());
	sScore.pop_back();
	sScore.pop_front();  // 去掉最高分和最低分
	int sum = 0;
	for (deque<int>::iterator dit = sScore.begin(); dit != sScore.end(); dit++)
	{
		sum += *dit; //累加每个评委的分数
	}
	double avg = (double)sum / (double)(sScore.size());
	return avg;	// 返回平均分
}

/*******************************************
* 函数名：void speechManager::giveAMark()
* 功能：给参赛选手打分，最终的分数
* 参数：
* 返回值：
********************************************/
void speechManager::giveAMark(vector<int> & vCP)
{
	map<int, double> sScore;	// 定义临时变量存放ID和对应的分数
	for (vector<int>::iterator i = vCP.begin(); i != vCP.end(); i++)
	{
		sScore.insert(pair<int, double>(*i, this->computeScore()));
	}	
	// 把得分打给具体的参赛人员
	for (map<int, double>::iterator it = sScore.begin(); it != sScore.end(); it++)
	{
		map<int, Competitor>::iterator pos = mSpeaker.find(it->first);
		if (pos != mSpeaker.end())
		{
			(*pos).second.score = it->second;
		}
		else
		{
			cout << "err" << endl;
		}	
	}	
}

/*******************************************
* 函数名：void speechManager::printResult()
* 功能：打印比赛结果
* 参数：无
* 返回值：无
********************************************/
void speechManager::printResult(vector<int> & vCP)
{
	
	for (vector<int>::iterator i = vCP.begin(); i != vCP.end(); i++)
	{
		map<int, Competitor>::iterator pos = mSpeaker.find(*i);
		cout << "编号" << *i << "\t姓名" << setw(10) << left 
			<< (*pos).second.name << "\t得分" << (*pos).second.score << endl;
	}	
}

/*******************************************
* 函数名：void speechManager::printCompetitorId(vector<int> & vCP)
* 功能：打印参赛选手名单（ID）
* 参数：
* 返回值：
********************************************/
void speechManager::printCompetitorId(vector<int> & vCP)
{
	switch (this->turn)
	{
	case 0:
		cout << "第一轮参赛人员：";
		break;
	case 1:
		cout << "第二轮参赛人员：";
		break;
	case 2:
		cout << "胜出者名单：";
		break;
	default:
		break;
	}
	for (vector<int>::iterator it = vCP.begin(); it != vCP.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*******************************************
* 函数名：
* 功能：计算晋级名单
* 参数：
* 返回值：
********************************************/
void speechManager::promoted(vector<int> & contestant, vector<int> & vV)
{
	set<Competitor, MyCompare> sScore;	// 定义临时变量存放ID和对应的分数
	for (vector<int>::iterator i = contestant.begin(); i != contestant.end(); i++)
	{
		map<int, Competitor>::iterator pos = mSpeaker.find(*i);
		sScore.insert(pos->second);
	}		
	set<Competitor, MyCompare>::iterator iter1 = sScore.begin();	// 指向第一个位置
	advance(iter1, 3);	// 指向第4个位置
	sScore.erase(iter1, sScore.end());
	for (set<Competitor, MyCompare>::iterator i = sScore.begin(); i != sScore.end(); i++)
	{
		cout << i->id << " " << i->name << " " << i->score << endl;
		vV.push_back(i->id);
	}	
}

/*******************************************
* 函数名：
* 功能：将比赛结果记录在表格中
* 参数：
* 返回值：
********************************************/
void speechManager::writeCSV()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件  -- 写文件

	//将每个人数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		map<int, Competitor>::iterator pos = mSpeaker.find(*it);
		ofs << *it << ","
			<< (*pos).second.name << "," << (*pos).second.score << ",";
	}
	ofs << endl;
    
	//关闭文件
	ofs.close();
    
	cout << "记录已经保存" << endl;
}
