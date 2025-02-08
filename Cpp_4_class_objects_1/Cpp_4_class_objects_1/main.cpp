#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//类的引入
//C++兼容C语言，同时C++中struct升级成了 类(具有类的所有特性)
struct _Stack {
	//成员方法
	void Init(int defaultCapacity = 4) {
		base = (int*)malloc(sizeof(int) * defaultCapacity);
		if (base == nullptr) {
			perror("malloc failed\n");
			return;
		}
		this->size = 0;
		this->capacity = defaultCapacity;
	}
	void Push() {

	}
	void Destroy() {
		free(this->base);
		this->base = nullptr;
		this->top = this->capacity;
	}
	//成员变量
	int* base;
	int top;
	int capacity;
	int size;
};
void TestStruct() {
	struct _Stack st1;	//C语言的写法
	st1.Init();
	_Stack st2;		//C++的写法
	st2.Init();

	cout << "size: " << st1.size << " capacity: " << st1.capacity << endl;
	cout << "size: " << st2.size << " capacity: " << st2.capacity << endl;
}


//类的定义
class Stack {
public:
	void Init(int defaultCapacity = 4) {
		base = (int*)malloc(sizeof(int) * defaultCapacity);
		capacity = defaultCapacity;
		top = 0;
	}
	void Push() {
		//.......
	}
	void Pop() {
		//.......
	}
private:
	int* base;
	int top;
	int capacity;
};
//class和struct都可以定义类，struct是为了兼容C语言的写法，C++中定义类可以用struct,但C++更喜欢用class
//class中成员函数和变量默认是私有的，strutc中默认是公开的


//类的声明和定义分离
// 头文件中写类的定义包括， 成员的权限限定 成员函数的声明   以及成员变量的声明
// 对应的.cpp文件中，写成员函数的实现， 只不过需要在函数名前加上对应类的 作用域限定
//类的声明和定义分离，需要在函数名前面，加上类的作用域限定
//注意： 1. 在类内进行实现的函数，会被建议成为内联函数，具体是否称为取决于编译器
//		 2. 类中，声明和定义分离的函数，不会是内联函数(内联函数声明和定义不能分离，否则会链接不上)

class Date {
public:
	//根据局部优先的原则，是 函数的形参   赋值给  函数的形参,不会对成员year产生影响
	//但这样写，不易区分
	void setDate(int year, int month, int day) {
		/*year = year;
		month = month;
		day = day;*/
		_year = year;
		_month = month;
		_day = day;
	}
	void getDate() {
		cout << _day << endl;
	}
//private:
	//int year;
	//int month;
	//int day;

	//通常在类的成员变量加上_来区分
	int _year;	//类似的写法都是声明，变量声明和定义的区别是，是否开辟空间
	int _month;
	int _day;
};

//面向对象三大特性：封装、继承、多态
// 先学习封装
// C语言，数据和方法是分离的，封装就是把数据和方法写在一起，是为了更好的管理，可以杜绝一些不文明的代码操作
// 局部域， 全局域，命名空间域(需要指定)，类域
// 局部域和全局域会影响生命周期， 类域和命名空间域不会影响生命周期

//对象的大小只计算成员变量，不计算成员函数
//不同对象，调用成员函数，调用的是同一个函数，这些函数的指针存在一个公共区域

//也就是说，对象中只存储了成员变量，没有存储函数指针
//函数存储在一个公共的区域
void TestClass() {

	// 类实例化对象，整体定义了类内的数据
	// 类就像图纸，实例化出的对象就像是房子
	
	Date d1;
	//Date::_year = 1;	//不能这样写，图纸不能住人。类内没有开辟空空间，不能存放数据。
	d1._day = 2;	//应该这样访问
	cout << sizeof(d1) << endl;		//大小为 12，对象的大小只计算成员变量，不计算成员函数
}
//int main() {
//	TestStruct();
//	TestClass();
//	return 0;
//}

class Empty {};
class Data {
	int num;        // 4字节
	double value;   // 8字节
	char tag;       // 1字节
};// 8 + 8 + 1 = 17 → vs下实际输出24（内存对齐）

int main() {
	cout << sizeof(Empty) << endl;;  // 输出1
	cout << sizeof(Data) << endl;;  // 输出24
}