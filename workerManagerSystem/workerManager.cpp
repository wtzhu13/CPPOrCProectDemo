#include "workerManager.h"

/*******************************************
* 函数名：workerManager::workerManager()
* 功能：workerManager的构造函数，给全局工人数和存放工人的数组赋值
* 参数：
* 返回值：
********************************************/
workerManager::workerManager()
{
	this->workerNum = 0;
	this->workerAray = NULL;
	this->initArray(&(this->workerNum));
}

/*******************************************
* 函数名：workerManager::~workerManager()
* 功能：workerManager的析构函数，释放堆区空间
* 参数：无
* 返回值：无
********************************************/
workerManager::~workerManager()
{
	if (this->workerAray != NULL)
	{
		delete[] this->workerAray;
		this->workerAray = NULL;
	}
}

/*******************************************
* 函数名：workerManager::initArray(int *countP)
* 功能：初始化存储数组
* 参数：员工人数地址，通过地址改变内容
* 返回值：无
********************************************/
void workerManager::initArray(int *countP)
{
	this->getWorkerCount(countP);
	this->workerAray = new Worker *[this->workerNum];	// 	分配已有人数的空间
	ifstream ifs;
	ifs.open(DATAFILEPATH, ios::in);	
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())	// 如果数组为空，则workerAray = NULL并退出
	{
		this->workerAray = NULL;
		ifs.close();
		return;
	}
	ifs.seekg(0, ios::beg);		// 将文件指针重新至于文件开头位置
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)	// 获取文件内容
	{
		switch (did)
		{
		case 1:
			this->workerAray[index] = new Boss(id, name, did);
			break;
		case 2:
			this->workerAray[index] = new Manager(id, name, did);
			break;
		case 3:
			this->workerAray[index] = new Employee(id, name, did);
			break;
		default:
			break;
		}
		index ++;
	}
	ifs.close();
}

/*******************************************
* 函数名：workerManager::showMenu()
* 功能：显示初始界面菜单
* 参数：无
* 返回值：无
********************************************/
void workerManager::showMenu()
{
    cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

/*******************************************
* 函数名：workerManager::exitSys()
* 功能：退出系统
* 参数：无
* 返回值：无
********************************************/
void workerManager::exitSys()
{
    cout << "欢迎下次使用" << endl;
	exit(0);
}

/*******************************************
* 函数名：workerManager::test()
* 功能：debug期间的测试代码，最终功能不用
* 参数：无
* 返回值：无
********************************************/
// void workerManager::test()
// {
// 	cout << "test" << endl;
// 	Worker *worker = new Employee(1, "Tom", 2);
// 	worker->showInfo();
// 	delete worker;

// 	worker = new Manager(2, "Jack", 3);
// 	worker->showInfo();
// 	delete worker;

// 	worker = new Boss(3, "fred", 1);
// 	worker->showInfo();
// 	delete worker;

// }

/*******************************************
* 函数名：workerManager::addWorker()
* 功能：添加员工
* 参数：无
* 返回值：无
********************************************/
void workerManager::addWorker()
{
	while (1)
	{
		cout << "请输入添加的员工人数" << endl;
		int addNum = 0;
		cin >> addNum;
		if (cin.fail() || addNum <= 0 )		// c.fial()判断输入类型是否匹配，不匹配则为false
		{
			cout << "输入错误" << endl;
			cin.clear();	// 清空输入流缓冲区
			cin.ignore();   // 清空cin缓冲区
		}		
		else	// 输入正确
		{
			// 原本的数组大小和现在需要的大小一起就是需要的空间
			int newSize = this->workerNum + addNum;
			Worker **newSpace = NULL;
			newSpace = new Worker *[newSize];		
			if (this->workerAray != NULL)
			{
				// 当原始数组不为空，就得把原始数组中的数据拷贝到新的数组中
				for (int i = 0; i < this->workerNum; i++)
				{
					newSpace[i] = this->workerAray[i];
				}			
			}

			// 输入新的数据
			for (int i = 0; i < addNum; i++)
			{
				int id;             // 员工ID
				string name;		// 员工姓名
				int departmentNum;  // 部门编号

				// 获取新增员工的基本信息
				cout << "请输入第" << i+1 << "个员工编号" << endl;
				cin >> id;

				cout << "请输入第" << i+1 << "个员工姓名" << endl;
				cin >> name;

				cout << "请输入第" << i+1 << "个员工岗位" << endl;
				cout << "1、老板" << endl;
				cout << "2、经理" << endl;
				cout << "3、普通员工" << endl;
				cin >> departmentNum;

				switch (departmentNum)
				{
				case 1:     // 创建老板
					newSpace[this->workerNum + i] = new Boss(id, name, 1);
					break;
				case 2:		// 创建经理
					newSpace[this->workerNum + i] = new Manager(id, name, 2);
					break;
				case 3:		// 创建普通职员
					newSpace[this->workerNum + i] = new Employee(id, name, 3);
					break;			
				default:
					break;
				}
				this->saveDataLocal(id, name, departmentNum);
			}
			cout << "delete workerAray" << endl;
			this->workerAray = newSpace;	// 添加完成后的数组
			delete[] newSpace;
			cout << "delete newspace" << endl;
			newSpace = NULL;
			this->workerNum = newSize;	 	// 添加完成后总员工数
			cout << "添加成功" << addNum << "名员工" << endl;
			// system("clear");
			return;
		}
	}  
}

/*******************************************
* 函数名：workerManager::saveDataLocal()
* 功能：把员工信息存放到本地磁盘文件中
* 参数：员工ID，员工姓名，员工部门编号
* 返回值：无
********************************************/
void workerManager::saveDataLocal(int id, string name, int departmentNum)
{
	ofstream ofs;
	ofs.open(DATAFILEPATH, ios::app);
	ofs << id << " " << name << " " << departmentNum << endl;
	ofs.close();
}

/*******************************************
* 函数名：workerManager::getWorkerCount(int *count)
* 功能：获取本地已经保存好的员工人数
* 参数：员工人数&workerNum
* 返回值：无
********************************************/
void workerManager::getWorkerCount(int *count)
{
	ifstream ifs;
	ifs.open(DATAFILEPATH, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	int id;
    string name;
    int did;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		(*count) ++;	// 统计有多少行就有多少个员工
	}
	ifs.close();
}

/*******************************************
* 函数名：workerManager::showWorker()
* 功能：显示员工信息
* 参数：无
* 返回值：无
********************************************/
void workerManager::showWorker()
{
	if (this->workerAray == NULL)	// 判断当前是否有数据
	{
		cout << "当前暂无数据" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < this->workerNum; i++)	// 有数据，则循环调用worker.showInfo()
		{
			this->workerAray[i]->showInfo();
		}		
	}
	this->waitQuit();	
}

/*******************************************
* 函数名：void workerManager::deleteById()
* 功能：通过ID删除员工
* 参数：无
* 返回值：无
********************************************/
void workerManager::deleteById()
{
	int delID;
	while (1)
	{
		cout << "请输入需要删除的员工编号：";
		cin >> delID;
		
		if (cin.fail())
		{
			cout << "输入有误，请检查是否为整数" << endl;
			cin.clear();
			cin.ignore();
		}
		else
		{
			int index = this->IsExist(delID);
			if (index != -1)
			{
				this->deleteWorker(index);
				cout << "成功删除编号为" << delID << "的员工" << endl;
				return;
			}
			cout << "输入的编号员工不存在" << endl;
		}		
	}
}

/*******************************************
* 函数名：void workerManager::deleteWorker(int index)
* 功能：通过ID删除员工
* 参数：ID
* 返回值：无
********************************************/
void workerManager::deleteWorker(int index)
{	
	for (int i = index; i < this->workerNum-1; i++)
	{
		this->workerAray[i] = this->workerAray[i+1];
	}
	this->workerNum --;
	this->clearFile();
	ofstream ofs;
	for (int i = 0; i < this->workerNum; i++)
	{
		ofs.open(DATAFILEPATH, ios::app);
		if (!ofs.is_open())
		{
			cout << "文件打开失败" << endl;
		}	
		ofs << this->workerAray[i]->m_Id << " " << this->workerAray[i]->m_Name << " " << this->workerAray[i]->m_DeptId << endl;
		ofs.close();
	}
}

/*******************************************
* 函数名：int workerManager::IsExist(int id)
* 功能：判断ID所对应的员工是否存在
* 参数：员工ID
* 返回值：存在则返回员工在数组中的下标，否则返回-1
********************************************/
int workerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->workerAray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

/*******************************************
* 函数名：workerManager::modifyWorkerInfo()
* 功能：根据输入的员工编号修改员工信息
* 参数：无
* 返回值：无
********************************************/
void workerManager::modifyWorkerInfo()
{
	if (this->workerAray == NULL)
	{
		cout << "目前没有数据" << endl;
		return;
	}
	int modifyNum;
	cout << "请输入需要修改信息的员工的编号：";
	cin >> modifyNum;
	if (this->IsExist(modifyNum) == -1)
	{
		cout << "输入的员工编码不存在" << endl;
		return;
	}
	else
	{
		for(int i = 0; i <this->workerNum; i++)
		{
			if(this->workerAray[i]->m_Id == modifyNum)
			{
				string name;
				int did;
				cout << "请输入员工姓名：";
				cin >> name;

				cout << "请输入员工部门岗位" << endl;
				cout << "1、老板" << endl;
				cout << "2、经理" << endl;
				cout << "3、普通员工" << endl;
				cin >> did;

				switch (did)
				{
					case 1:
						this->workerAray[i] = new Boss(i+1, name, did);
						break;
					case 2:
						this->workerAray[i] = new Manager(i+1, name, did);
						break;
					case 3:
						this->workerAray[i] = new Employee(i+1, name, did);
						break;
					default:
						break;
				}
			}

		}
		ofstream ofs;
		ofs.open(DATAFILEPATH, ios::out);	// 	清空文本内容
		if (!ofs.is_open())
		{
			cout << "文件打开失败" << endl;
		}
		ofs.close();
		for (int i = 0; i <this->workerNum; i++)
		{
			this->saveDataLocal(
				this->workerAray[i]->m_Id,
				this->workerAray[i]->m_Name,
				this->workerAray[i]->m_DeptId
			);
		}
		
	}	
}

/*******************************************
* 函数名：void workerManager::findWorker()
* 功能：查询人员信息
* 参数：无
* 返回值：无
********************************************/
void workerManager::findWorker()
{
	int choice;
	cout << "请选择查询方式：" << endl;
	cout << "1.通过ID号查询" << endl;
	cout << "2.通过姓名查询" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		this->searcheByID();
		break;
	case 2:
		this->searchByName();
		break;
	default:
		break;
	}
}

/*******************************************
* 函数名：workerManager::searcheByID()
* 功能：通过ID查询员工信息
* 参数：无
* 返回值：无
********************************************/
void workerManager::searcheByID()
{
	int id;
	cout << "请输入ID：";
	cin >> id;
	int index = this->IsExist(id);
	if (index != -1)
	{
		this->workerAray[index]->showInfo();
		this->waitQuit();
	
	}
	else
	{
		cout << "查找的ID不存在" << endl;
		return;
	}	
}

/*******************************************
* 函数名：workerManager::searchByName()
* 功能：通过姓名查询员工信息
* 参数：无
* 返回值：无
********************************************/
void workerManager::searchByName()
{
	string name;
	cout << "请输入员工姓名：";
	cin >> name;
	int flag = 0;
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->workerAray[i]->m_Name == name)
		{
			this->workerAray[i]->showInfo();
			flag = 1;
			this->waitQuit();
		}		
	}
	if (!flag)
	{
		cout << "查找的姓名不存在" << endl;
	}	
}

/*******************************************
* 函数名：void workerManager::waitQuit()
* 功能：等待键盘退出
* 参数：无
* 返回值：无
********************************************/
void workerManager::waitQuit()
{
	cout << "返回菜单按‘q’" << endl;
	while (1)	// 等待返回菜单命令
	{
		char backMenu;
		cin >> backMenu;
		if (cin.fail() || (backMenu != 'q'))
		{
			cout << "无效命令,返回菜单按‘q’" << endl;
			cin.clear();
			cin.ignore();
		}
		else
		{
			system("clear");
			return;
		}	
	}	
}

/*******************************************
* 函数名：void workerManager::sortById()
* 功能：同构ID来进行排序
* 参数：无
* 返回值：无
********************************************/
void workerManager::sortById()
{
	Worker *p = this->workerAray[0];
	cout << "请选择排序顺序：" << endl;
	cout << "1.从小到大排序" << endl;
	cout << "2.从大到小排序" << endl;
	int choice;
	cin >> choice;
	
	for (int i = 0; i < this->workerNum - 1; i++)
	{
		for (int j = i + 1; j < this->workerNum; j++)
		{				
			switch (choice)
			{
				case 1:
					if (this->workerAray[i]->m_Id > this->workerAray[j]->m_Id)
					{
						p = this->workerAray[i];
						this->workerAray[i] = this->workerAray[j];
						this->workerAray[j] = p;
					}		
					break;
				case 2:
					if (this->workerAray[i]->m_Id < this->workerAray[j]->m_Id)
					{
						p = this->workerAray[i];
						this->workerAray[i] = this->workerAray[j];
						this->workerAray[j] = p;
					}		
					break;
				default:
				break;
			}							
		}		
	}
	this->showWorker();	
}

/*******************************************
* 函数名：void workerManager::clear()
* 功能：清除数据
* 参数：无
* 返回值：无
********************************************/
void workerManager::clear()
{
	this->clearFile();
	this->workerAray = NULL;
	cout << "清除完毕" << endl;
}

/*******************************************
* 函数名：workerManager::clearFile()
* 功能：清空本地文件
* 参数：无
* 返回值：无
********************************************/
void workerManager::clearFile()
{
	ofstream ofs;
	ofs.open(DATAFILEPATH, ios::out);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	ofs.close();
}