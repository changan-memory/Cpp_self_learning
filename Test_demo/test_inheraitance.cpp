#include <iostream>
#include <string>

using namespace std;
class Person {
protected:
	string _name; // 姓名
public:
	// 父类的默认构造
	Person(const char* name = "peter")
	//Person(const char* name)
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)	// 子类对象 可以 赋值给 父类的引用
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p) {
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person() {
		cout << "~Person()" << endl;
	}
};
// 平时只用public继承
class Student : public Person {
public:
	Student(const char* name = "张三", int id = 0)
		:_id(id)
		,Person(name)
	{ }
	Student(const Student& s)
		:Person(s)
		,_id(s._id)
	{}
	Student& operator=(const Student& stu) {
		if (this != &stu) {
			Person::operator=(stu);
			//operator=(stu);
		}
		return *this;
	}
	~Student() {
		// 由于后面多态设计的原因，子类父类中析构函数的函数名被特殊处理了
		// 析构函数的名字被统一处理成立destructor
		// 由于父子类中函数同名，因此触发了隐藏，访问父类的析构函数需要指定作用域
		//Person::~Person();
	}
protected:
	int _id; //学号
};

int main() {
	Student s;
	Student s1(s);
	Student s2("李四", 1);
	s = s2;
	return 0;
}