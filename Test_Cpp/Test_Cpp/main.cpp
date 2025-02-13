//#include <iostream>
//using namespace std;
//
////运算符重载
//class Date {
//public:
//	Date(int year = 2025, int month = 2, int day = 22) {
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	//操作符是几个操作数，operator函数就有几个参数(应该包括上隐含的this指针参数)
//	//也可以全局重载，但在类内重载更方便，可以直接访问私有成员
//	bool operator<(const Date& d) {	//自定义类型，最好传引用，类内不能修改，加上const
//		if (this->_year < d._year)
//			return true;
//		else if (this->_year == d._year && this->_month < d._month)
//			return true;
//		else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
//			return true;
//		else
//			return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 运算符重载
//void Test_operator() {
//	Date d1(2025, 6, 20);
//	Date d2(2024, 3, 10);
//
//	//全局版本	//全局运算符重载不能访问private成员
//	//d1 < d2;	//会被转换成 operator<(d1, d2);
//	//operator<(d1, d2);	//也可以直接调用
//
//	//成员函数版本
//	d1 < d2;	//转换成 d1.operator(d2);
//	d1.operator<(d2);	//本质上都是 d1.operator(d2)
//	//自定义类型的运算符重载，本质上是在调用函数
//
//	//是否需要重载运算符，要看这些运算符对类型是否有意义 
//	//d1 + d2;	// + 没意义
//	//d1 - d2;	// - 有意义
//
//	//对象需要赋值，因此=需要重载
//	d1 = d2;
//	Date d3, d4;
//	d4 = d3 = d1; //d4.operator=(d3.operator=(d1));	//因此应该返回调用该函数的对象，也就是*this
//
//	Date d5(2025, 6, 6);
//	d5 = d1;
//	//用一个已经存在的对象初始化另一个对象  -----  调用拷贝构造函数
//	Date d6 = d5;
//
//	//已经存在的两个对象之间复制拷贝  -----  赋值运算符重载函数
//	d1 = d6;
//}
//
//int main() {
//	Date d1(2025, 2, 12);
//	Date d2(2024, 2, 12);
//	cout << (d2 < d1) << endl;
//}

#include <iostream>
using namespace std;

class Stack {
	typedef int DataType;
public:
	Stack(size_t capacity = 10) {
		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array) {
			perror("malloc申请空间失败");
			return;
		}
		_size = 0;
		_capacity = capacity;
	}
	void Push(const DataType& data) {
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	~Stack() {
		if (_array) {
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};
int main() {
	Stack s1;
	s1.Push(1);
	s1.Push(2);
	Stack s2;
	s2 = s1;
	return 0;
}