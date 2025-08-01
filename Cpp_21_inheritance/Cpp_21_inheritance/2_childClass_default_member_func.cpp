#include <iostream>
using namespace std;

namespace question2 {
	class Person {
	protected:
		string _name; // 姓名
	public:
		Person(const char* name = "peter")
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
	class Student : public Person {
	public:
		// 1. 构造函数
		// 调用父类的构造函数 是在初始化列表调用的
		// 类似于 把子类中父类的那部分成员，当成了一个自定义类型在处理，
		// 自定义类型初始化调用其默认构造函数
		// 派生类只能初始化自己的那部分成员，子类中的父类的那部分成员，交给父类的构造函数处理
		// 如果基类没有默认构造函数，则必须在派生类构造函数的初始化列表阶段显式调用
		Student(const char* name = "张三", int id = 0)
			: Person(name)	// 手动初始化父类那部分成员的语法，类似于构造一个匿名对象来初始化
			, _id(id)		// 建议初始化列表的顺序和 声明的顺序(初始化的顺序)保持一致
			//,_name(name)	// 不能显式 在初始化列表中 
		{
			// 这里初始化列表中出现的顺序和初始化顺序无关
			// 初始化列表中，是按照成员的声明顺序初始化的，继承的类，相当于先声明了基类，
			// 因此先初始化Person ， 再初始化子类的成员变量 _id  
		}

		// 2. 拷贝构造函数
		Student(const Student& stu)
			// 不能手动初始化父类的成员，必须要调用父类的拷贝构造函数
			:Person(stu)	// 子类对象 可以 传给 父类的引用   显式调用拷贝构造
			,_id(stu._id)
			// 如果不手动写父类的拷贝构造，会调用默认构造，没有默认构造，会报错
		{ }
		// 3. 派生类的operator=必须要调用基类的operator=完成基类的复制
		// 不要用现代写法
		Student& operator=(const Student& stu) {
			if (this != &stu) {
				Person::operator=(stu);
				//Person& operator=(const Person & p)  p引用子类对象中父类的那一部分
				_id = stu._id;
			}
			return *this;
		}
	protected:
		int _id; //学号
	};
}
int main() {
	question2::Student s;
	question2::Student s1(s);

	return 0;
}