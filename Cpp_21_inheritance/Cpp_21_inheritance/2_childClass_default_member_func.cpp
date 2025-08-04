#include <iostream>
using namespace std;

namespace question2 {
	class Person {
	protected:
		string _name; // 姓名
	public:
		// 父类的默认构造
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
	// 平时只用public继承
	class Student : public Person {
	public:
		// 1. 构造函数
		// C++规定，派生类必须调用基类的构造函数(默认构造)，去初始化派生类中基类的那部分
		// 如果基类没有默认的构造函数，则必须在派生类构造函数的初始化列表阶段显示调用父类的构造
		// 写起来就像定义了一个匿名对象一样
		// 调用父类的构造函数 是在初始化列表调用的
		// 类似于 把子类中父类的那部分成员，当成了一个自定义类型在处理，
		// 自定义类型初始化调用其默认构造函数
		// 派生类初始化，只初始化自己的那部分成员，子类中的父类的那部分成员，交给父类的构造函数处理
		// 如果基类没有默认构造函数，则必须在派生类构造函数的初始化列表阶段显式调用
		Student(const char* name = "张三", int id = 0)
			//: Person(name)	// 手动初始化父类那部分成员的语法，类似于构造一个匿名对象来初始化
			//, _id(id)		// 建议初始化列表的顺序和 声明的顺序(初始化的顺序)保持一致
			//,_name(name)	// 不能显式 在初始化列表中 初始化父类或基类成员，在函数体内中可以
			:_id(id)
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
				//operator=(stu);	// 这里发生了派生类对父类同名函数的隐藏
				// 不指明作用域调用时，默认调用自己的operator=，引发了无限递归，最终栈溢出
				//Person& operator=(const Person & p)  p引用子类对象中父类的那一部分
				_id = stu._id;	// 自己的自定义成员可以考虑现在写法
			}
			return *this;
		}
		// 4. 析构函数
		// 派生类的析构函数会在被调用完成后自动调用基类的析构函数清理基类成员。
		// 因为这样才能保证派生类对象先清理派生类成员再清理基类成员的顺序
		~Student() {
			// 由于后面多态的原因，基类和派生类的析构函数的函数名被特殊处理了
			// 被统一处理成了 destructor
			// 由于函数名相同，因此触发了隐藏，需要指明类域
			//~Person();  // 这种写法会报错，应该指明类域
			// 显式调用父类析构，无法保证 先析构子 再析构负
			// 所以 子类析构函数完成后，自动调用父类析构，这样就保证了先子后父
			//Person::~Person();
			delete _ptr;
			// 要先析构子类，再析构父类的原因
			// 1. 保证父子对象在栈中定义的顺序，在栈中，一般是先定义父类对象，在定义子类对象
				// 栈帧退出时，会先析构子类对象，再析构父类对象
			// 2. 如果先析构父类对象，子类可能还会访问父类中的成员，这时就会报错
				// 而 先析构子类后，对父类无影响，因为父类永远不会访问 子类的成员
		}
	protected:
		int _id; //学号
		int* _ptr;
	};
	// 测试 构造 拷贝构造 operator=
	void test1() {
		question2::Student s;
		/*question2::Student s1(s);
		question2::Student s3("你好", 666);
		s = s3;*/
	}
}

//int main() {
//	question2::test1();
//	return 0;
//}