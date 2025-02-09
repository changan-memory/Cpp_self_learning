#include <iostream>
using std::cout;
using std::cin;
using std::endl;


class Stack {
private:
	int* _base = nullptr;	//C++11支持的成员变量缺省值
	int _top = 0;
	int _capacity = 0;
public:
	Stack(int defaultCapacity = 4) {
		this->_base = (int*)malloc(sizeof(int) * defaultCapacity);
		if (this->_base == nullptr) {
			perror("malloc failed\n");
			return;
		}
		this->_capacity = defaultCapacity;
		this->_top = 0;
	}
	//注意：类中如果没有涉及资源申请时，拷贝构造函数是否写都可以；
	// 一旦涉及到资源申请时，则拷贝构造函数是一定要写的，否则就是浅拷贝。

	//简单实现一个深拷贝  st2(st1)
	Stack(const Stack& stack) {
		this->_base = (int*)malloc(sizeof(int) * stack._capacity);
		if (this->_base == nullptr) {
			perror("malloc failed\n");
			return;
		}
		memcpy(this->_base, stack._base, sizeof(int) * stack._top);
		this->_top = stack._top;
		this->_capacity = stack._capacity;
	}
	~Stack() {
		cout << " ~Stack" << endl;
		free(this->_base);
		this->_base = nullptr;
		this->_capacity = 0;
		this->_top = 0;
	}
};
//拷贝构造  函数
class Date {
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 2024, int month = 10, int day = 28) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	//传参时， 内置类型无要求，直接拷贝；自定义类型  值传参，必须调用拷贝构造函数
	//拷贝构造函数是构造函数的一个重载形式。
	//拷贝构造函数的参数只有一个且必须是类类型对象的引用，使用传值方式编译器直接报错，因为会引发无穷递归调用。
	// 可以用指针 解决以上问题，因为所有类型的指针都是内置类型，  但是引用更香
	//调用一个函数，要先传参，而自定义类型的传参  必须  调用拷贝构造函数

	Date(const Date& date) {	
		this->_year = date._year;
		this->_month = date._month;
		this->_day = date._day;
	}
};
//默认拷贝构造函数
class Date_1 {
private:
	int _year;
	int _month;
	int _day;
public:
	Date_1(int year = 2023, int month = 10, int day = 28) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	//若未显式定义，编译器会生成默认的拷贝构造函数。 
	// 默认的拷贝构造函数对象按内存存储按字节序完成拷贝，这种拷贝叫做浅拷贝，或者值拷贝。
	//默认拷贝构造函数 做了什么？
	//内置类型成员完成  值拷贝/浅拷贝     自定义类型，调用各自的构造函数，如果没有拷贝构造函数，则值拷贝

	/*Date_1(const Date_1& date) {
		this->_year = date._year;
		this->_month = date._month;
		this->_day = date._day;
	}*/
};
void Func(int i) {
	return;
}
void Func(Date d) {
	return;
}
int main() {
	//日期类可以不写拷贝构造，默认生成的就可以
	Date d1(2025, 2, 8);
	Date d2(d1);

	Func(d1);
	Func(10);	//形参的拷贝，
	
	//值拷贝(浅拷贝)，有问题，两个指针存下了同一块空间的地址，析构时会对一块空间析构两次
	// st1.push , 对 d1 对象的操作，也会影响 d2 对象
	//会引发错误。  类似于  栈这样的对象，必须自己实现深拷贝
	Stack st1;
	Stack st2(st1);		//可以认为深拷贝 是为了  有资源的对象 的拷贝而设计的
	return 0;
}

//建议加上 const
		//const 是为了防止别人写错，防止别人写成以下代码
		//date._year = _year;		//不仔细看真看不出来，赔了夫人又折兵，会出现随机值
		//date._month = _month;
		//date._day = _day;