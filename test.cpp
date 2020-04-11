#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;

};
class comparePerson
{
public:
	bool operator()(const Person& p1, const Person &p2)
	{
		//按照年龄进行排序  降序
		return p1.m_Age > p2.m_Age;
	}
};

void test01()
{
	map<Person, int> s;

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

    s[p1] = 1;
    // s.insert(pair<Person, int>(p1, 1));
	// s.insert(make_pair(1, p1));
	// s.insert(make_pair(2, p2));
	// s.insert(make_pair(3, p3));
	// s.insert(make_pair(4, p4));

	// for (map<int, Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	// {
	// 	cout << "姓名： " << it->second.m_Name << " 年龄： " << it->second.m_Age << endl;
	// }
}
int main() {

	test01();

	return 0;
}