#include <iostream>
#include <assert.h>

using namespace std;
class Stack {
	typedef int StackDataType;
private:
	StackDataType* base;
	int top;	//top表示栈顶元素的下一个位置
	int capacity;
public:
	//构造函数
	Stack(int defaultCapacity = 4) {	//可能需要多种方式的初始化，因此构造函数可以重载
		cout << "Stack defaultCapacity = 4" << endl;
		this->base = (StackDataType*)malloc(sizeof(StackDataType) * defaultCapacity);
		if (this->base == nullptr) {
			cout << "malloc failed" << endl;
		}
		this->capacity = defaultCapacity;
		this->top = 0;
	}
	Stack(StackDataType* array, int num) {	//重载版本，用现有的数组进行初始化
		cout << "Stack(array, num)" << endl;
		this->base = (StackDataType*)malloc(sizeof(StackDataType) * num);
		if (this->base == nullptr) {
			cout << "malloc failed" << endl;
		}
		assert(this->base);
		memcpy(this->base, array, sizeof(StackDataType) * num);
		this->capacity = num;
		this->top = 0;
	}
	//析构函数，稍后介绍。
	~Stack() {
		cout << "~Stack" << endl;
		free(this->base);
		this->base = nullptr;
		this->capacity = 0;
		this->top = 0;
	}
};

//int main() {
//	Stack st1;
//	Stack st2(4);
//	int arr[] = { 1, 2,3,4,6,6,7 };
//	Stack st3(arr, sizeof(arr) / sizeof(arr[0]));
//	return 0;
//}


//自动生成的构造函数
//class Date {
//public:
//	Date(int year = 2, int month = 2, int day = 2) {
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	//Date() {		//语法上，该重载函数可以存在，但是，无参调用时会存在歧义，因此不能存在
//	//	this->_year = 3;
//	//	this->_month = 3;
//	//	this->_day = 3;
//	//}
//
//	/*Date(int year, int month, int day) {	//和缺省值参数相比，这个函数就没有存在的必要了
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main() {
//
//	//构造函数的调用和普通函数不同，构造函数是对象+初始化参数 或者 自动调用
//	Date d1;
//	//Date d1();	//不能这样写，这样会和函数声明区分不开
//	Date d2(2025, 2025, 2025);		//构造函数的调用，对象名接参数列表
//
//	Date d3;
//	//d3.Date(2025, 2025, 2025);
//	 //这样写毫无意义，首先这种写法忽视了自动调用的问题，其次，这种写法Date为什么不叫Init
//}

class Time {
public:
	~Time() {
		cout << "~Time()" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date {
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
	Time _time;
};

int main() {
	Date d;
	return 0;
}





