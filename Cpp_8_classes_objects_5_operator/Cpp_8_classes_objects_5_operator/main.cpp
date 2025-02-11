#include "Date.h"

namespace TestSpace_operator {
	//运算符重载
	class Date {
	public:
		Date(int year = 2025, int month = 2, int day = 22) {
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}
		void Print() {
			cout << this->_day << "--" << this->_month << "--" << this->_day << endl;
		}

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
		//用一个已经存在的对象初始化另一个对象  -----  调用拷贝构造函数
		Date d6 = d5;

		//已经存在的两个对象之间复制拷贝  -----  赋值运算符重载函数
		d1 = d6;

		

	}
}


int main() {
	TestSpace_operator:: Test_operator();
	return 0;
}