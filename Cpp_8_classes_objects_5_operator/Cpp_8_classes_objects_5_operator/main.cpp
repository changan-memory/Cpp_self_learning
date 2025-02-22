#include "Date.h"

namespace TestSpace_operator {
	//运算符重载
	class Date {
	public:
		Date(int year = 2025, int month = 2, int day = 22) {
			//检查数据的合理性
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}
		void Print() {
			cout << this->_day << "--" << this->_month << "--" << this->_day << endl;
		}
		//内置类型，转换成
		//操作符是几个操作数，operator函数就有几个参数(应该包括上隐含的this指针参数)
		//也可以全局重载，但在类内重载更方便，可以直接访问私有成员
		bool operator<(const Date& d) {	//自定义类型，最好传引用，类内不能修改，加上const
			if (this->_year < d._year)
				return true;
			else if (this->_year == d._year && this->_month < d._month)
				return true;
			else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
				return true;
			else
				return false;
		}
		//赋值运算符=重载
		// d3 = d1;
		//我们不写，编译器也会默认生成=重载，
		// 对内置数据类型，采用的是 值拷贝/浅拷贝
		// 对自定义数据类型，调用各自的 赋值运算符重载
		//d4 = d3 = d2 // d4.operator=(d3.operator=(d1));	//因此应该返回调用该函数的对象，也就是*this

		//赋值运算符重载是默认成员函数，编译器会自己生成， 不能写成全局的，
		Date& operator=(const Date& d) {	//返回(*this)的别名
			//if (*this != d)	// 这样子比较，代价有点大，将 != 重载后是可以实现的，但是没必要
			if (this != &d) {		//防止这样的赋值 d1 = d1   如果自己给自己赋值，可以不复制
				this->_year = d._year;
				this->_month = d._month;
				this->_day = d._day;
			}
			return *this;	//返回对象的别名，除了作用域，*this生命周期还在
		}

		/*Date(const Date& d) {
			cout << "Date(const Date& d) " << endl;
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}*/

	private:
		int _year;
		int _month;
		int _day;
	};
	// 运算符重载
	void Test_operator() {
		Date d1(2025, 6, 20);
		Date d2(2024, 3, 10);

		//全局版本	//全局运算符重载不能访问private成员
		//d1 < d2;	//会被转换成 operator<(d1, d2);
		//operator<(d1, d2);	//也可以直接调用

		//成员函数版本
		d1 < d2;	//转换成 d1.operator(d2);
		d1.operator<(d2);	//本质上都是 d1.operator(d2)
		//自定义类型的运算符重载，本质上是在调用函数

		//是否需要重载运算符，要看这些运算符对类型是否有意义 
		//d1 + d2;	// + 没意义
		//d1 - d2;	// - 有意义

		//对象需要赋值，因此=需要重载
		d1 = d2;
		Date d3, d4;
		d4 = d3 = d1; //d4.operator=(d3.operator=(d1));	//因此应该返回调用该函数的对象，也就是*this

		Date d5(2025, 6, 6);
		d5 = d1;
		
		//区分拷贝构造和赋值运算符重载
		//用一个已经存在的对象初始化另一个对象  -----  调用拷贝构造函数
		Date d6 = d5;	//等价于 Date d6(d5);

		//已经存在的两个对象之间复制拷贝  -----  赋值运算符重载函数
		d1 = d6;
	}
}

void TestDate() {
	Date d1(2024, 3, 6);
	Date d2(2025, 3, 6);
	d2 += 100;
	d2.Print();
	d2 = d1 + 10000;
	d1.Print();
	d2.Print();

	/*Date d3(2025, 2, 12);
	Date d4 = d3 - 100;
	d3.Print();
	d4.Print();
	d3 -= 100;
	d4.Print();*/
}
void TestDate2() {
	Date d1(2025, 2, 12);
	// 都要++，前置++返回++后的对象， 后置++返回++前的对象
	++d1;	//d1.operator();
	d1.Print();
	d1++;	//d1.operator(0);
	d1.Print();

}
void TestDate3() {
	Date d1(2025, 2, 13);
	d1 -= 50;
	d1.Print();

	Date d2(2025, 2, 13);
	d2 += -10000;
	d2.Print();
}
void TestDate4() {
	Date d1(2025, 2, 13);
	Date ret1 = d1--;
	ret1.Print();
	d1.Print();

	Date d2(2024, 2, 13);
	Date ret2 = --d2;
	ret2.Print();
	d2.Print();
}
void TestDate5() {
	Date d1(2025, 2, 13);
	Date d2(1949, 10, 1);
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;
}
void TestDate6() {
	Date d1(2025, 2, 13);
	Date d2(1949, 10, 1);
	Date d3(2020, 3, 3);
	//流插入运算符 <<  ,操作数是两个对象， cout 是ostream的一个类对象
	//流插入不能写成成员函数？
	//因为Date对象默认占用第一个参数，就是做了左操作数
	//写出来就一定是下面这样子，不符合使用习惯
	//d1 << cout;		// d1.operator<<(cout);  //第一个参数是左操作数，第二个参数是右操作数
	//d1.operator<<(cout);
	
	cout << d1;
	//从左往右执行，d2, d1, d1 依次流入cout，因此每次调用后都需要返回cout
	cout << d3 << d2 << d1;		//解决连续cout的问题

	//数据流入 d1 后，返回in对象，接着流入d2，流提取运算符，就是把终端的内容提取到内存中
	cin >> d1 >> d2;
}

void Test_const() {
	//问题的根源是形参this和实参的权限不匹配
	Date d1(2025, 2, 14);
	d1.Print();	//转换 -> d1.Print(&d1); 

	const Date d2(2024, 2, 14);	//d2的类型是const Date，它的地址是const Date* 类型的
	d2.Print();	//转换 -> d2.Print(&d2);

	//实际上 Print() 为  Print(Date* this)， 隐含的this指针类型是 Date*，也就是指向非const Date对象的指针
	//d1   Date* this = &d1;
	//d2   Date* this = &d2;	// d2的地址是const Date* 类型的，因此不匹配
	//如何解决?   
	//将 Date* this 变成 const Date* this
	//const Date* this = &d1;
	//const Date* this = &d2;

	//const Date* this = &d1, 加上const后会影响d1原来的可修改性吗

	//这里的 const 修饰的是指针指向的内容，即 this 指针所指向的 Date 对象是 const 的，
	//意味着你   不能通过 this 指针来修改 d1 对象的内容
	//加上后， 无法通过 this 指针来修改 d1 的数据成员，但这不会影响 d1 本身。
	//你仍然可以通过其他非 const 指针或者引用来修改 d1，只要 d1 不是本身是 const 对象。

	//const 修饰 this 后， 普通对象可以传(权限缩小)，const对象也可以传(权限平移)
	//只要成员函数内部不修改成员变量，都应该加const
	//这样const对象和普通对象都可以调用

	//const Date* this = &d1; 只会限制通过 this 指针修改 d1 的内容，不会影响 d1 自身的可修改性。

	//结论：
	// 不能所有的成员函数都加const ,要修改成员变量的函数不能加
	// 只要成员函数内部不修改成员变量，都应该加const, 这样const对象和普通对象都可以调用
}
int main() {

	//TestDate();
	//TestDate2();
	//TestDate3();
	//TestDate4();
	//TestDate5();
	//TestDate6();


	/*int i = 1, j = 11;
	Date d1(2025, 2, 13);
	Date d2(2024, 2, 13);

	bool ret1 = d1 < d2;
	bool ret2 = i < j;*/
	return 0;
}

