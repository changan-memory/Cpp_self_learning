#include <iostream>
using namespace std;
#include <queue>
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->_age = age;
		this->_name = name;
	}

public:
	int _age;
	string _name;
};

// 队列   先进先出
void test1()
{

	queue<Person> q;
	Person p1("唐僧", 100);
	Person p2("悟空", 400);
	Person p3("八戒", 300);
	Person p4("悟净", 200);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	while (!q.empty())
	{
		// 查看队头队尾
		cout << "队头为" << q.front()._name << "年龄 " << q.front()._age << endl;
		cout << "队尾为" << q.back()._name << "年龄 " << q.back()._age << endl;
		cout << "大小为" << q.size() << endl;
		q.pop();
	}
	cout << "队列大小为" << q.size() << endl;
}

int main()
{

	test1();
	return 0;
}