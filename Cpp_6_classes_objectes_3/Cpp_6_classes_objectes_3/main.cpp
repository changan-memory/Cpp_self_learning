#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <assert.h>
//C语言 初始化和销毁经常忘记写
//C语言 这些操作写起来很繁琐
//类和对象
//类的六个默认成员函数 初始化 清理 拷贝 赋值(前四个) 很重要

//这些函数是特殊的成员函数


class Stack {
	typedef int StackDataType;		//括号匹配需要把 int 换成char
private:
	StackDataType* base;
	int top;	//top表示栈顶元素的下一个位置
	int capacity;
public:
	//栈有了构造和析构函数，就不怕忘记初始化和释放内存了
	//使用构造函数初始化，构造函数可以重载
	
	//构造函数
	/*	1. 函数名与类名相同。
		2. 无返回值，也不需要写void。
		3. 对象实例化时 自动调用对应的构造函数。
		4. 构造函数可以重载。
		5. 如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦
		   用户显式定义编译器将不再生成。 
		6. 构造函数不开辟空间，只完成对象的初始化			*/

	//构造函数，替代init, 构造函数可以是私有的，但外部就不能自动调用了
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


	/*void Init() {		//构造函数可以代替Init()函数
		this->base = (StackDataType*)malloc(sizeof(StackDataType) * 4);
		if (this->base = NULL) {
			cout << "malloc failed" << endl;
		}
		this->capacity = 4;
		this->top = 0;
	}*/
	void Push(StackDataType ele) {
		assert(this->base);
		if (this->top == this->capacity) {
			StackDataType* newSpace = (StackDataType*)realloc(this->base, 
															sizeof(StackDataType) * 2 * this->capacity);
			if (newSpace == nullptr) {
				std::perror("realloc 失败");
				return;
			}
			this->base = newSpace;
			this->capacity *= 2;
		}
		this->base[this->top++] = ele;
	}
	void Pop() {
		assert(this->base);
		this->top--;
	}
	StackDataType Top() {
		return this->base[top-1];
	}

	//析构函数 完成的是对象资源的清理，功能类似Destroy,对象的销毁由系统完成

	/*1. 1. 析构函数名是在类名前加上字符 ~。
		 2. 无参数  (因此不能重载)  无返回值类型。
		 3. 一个类  只能有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。注意：析构函数不能重载

		 //析构函数也一样，对内置类型不做处理，对自定义类型回去调用他的析构函数

		 4. 在对象生命周期结束时，C++编译系统自动调用析构函数
				对象在销毁时会自动调用析构函数，完成对象中资源的清理工作。
		 5. 析构函数，是为了释放 堆区的空间， 栈区的空间不需要释放 */
	
	//系统自动生成的析构函数做了什么？  
	//对内置类型不做处理，对自定义类型回去调用他的析构函数
	
	//有了构造函数和析构函数，就不怕忘记初始化和释放内存了！！！
	~Stack() {
		cout << "~Stack" << endl;
		free(this->base);
		this->base = nullptr;
		this->capacity = 0;
		this->top = 0;
	}

};
void TestStackClass() {
	Stack st;
	st.Push(4);
	cout << st.Top() << endl;
	st.Pop();
	st.Push(3);
	cout << st.Top() << endl;
	st.Pop();
	st.Push(2);
	cout << st.Top() << endl;
	st.Pop();
	st.Push(1);
	cout << st.Top() << endl;
	st.Pop();
}


//自动生成的构造函数
class Date {
public:
	//无参构造函数和全缺省构造函数，在调用时会产生歧义
	//无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。
	//注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认构造函数。
	// 这三个只能存在一个
	// 总结，不传参就可以调用的函数，就是默认构造函数(编译器生成的，全缺省的，无参的)
	
	
	//区分 默认成员函数  和 默认构造函数
	//默认构造函数 就是
	//默认成员函数 是 编译器生成的六个默认成员函数

	Date(int year = 2, int month = 2, int day = 2) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	//Date() {		//语法上，该重载函数可以存在，但是，无参调用时会存在歧义，因此不能存在
	//	this->_year = 3;
	//	this->_month = 3;
	//	this->_day = 3;
	//}

	/*Date(int year, int month, int day) {	//和缺省值参数相比，这个函数就没有存在的必要了
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}*/
	
	void Print() {
		cout << this->_year << "--" << this->_month << "--" << this->_day << endl;
	}
	//如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，
	// 一旦用户显式定义编译器将不再生成


private:
	//内置类型
	//注意：C++11 中针对内置类型成员不初始化的缺陷，又打了补丁
	// 即：内置类型成员变量在, 类中声明时可以给缺省值， 
	// 这里给的是缺省值， 是给编译器生成默认构造函数使用

	int _year = 2025;
	int _month = 1;
	int _day = 1;

	/* C++把类型分成内置类型(基本类型)和自定义类型。内置类型就是语言提供的数据类型，如：
	int / char / double ...
	自定义类型就是我们使用class / struct / union等自己定义的类型
	编译器生成默认的构造函数,对内置类型不做处理，对自定义数据类型会调用 他的  默认构造函数*/

	/*int _year;
	int _month;
	int _day;*/

	//自定义类型  
	Stack _st;     //vs的编译器，对构造函数进行了处理
					 // 有自定义类型时，会调用自定义类型的构造函数，并初始化内置类型，但C++标准并未这样规定

	//一般情况下， 有内置类型成员，需要自己写构造函数，不能用编译器默认生成的
	//类内全部都是自定义类型时， 可以考虑让编译器自己生成
};
void TestNULLparameter() {
	Date d1;
	Date d2;
	d2.Print();
}
//构造函数的调用
void TestCallConstruct() {
	//构造函数的调用和普通函数不同，构造函数是对象+初始化参数 或者 自动调用
	Date d1;
	//Date d1();	//不能这样写，这样会和函数声明区分不开
	Date d2(2025, 2025, 2025);		//构造函数的调用，对象名接参数列表

	d1.Print();
	d2.Print();

	Date d3;
	//d3.Date(2025, 2025, 2025);
	 //这样写毫无意义，首先这种写法忽视了自动调用的问题，其次，这种写法Date为什么不叫Init
}
int main() {
	//TestStackClass();
	//TestNULLparameter();
	//TestCallConstruct();
	return 0;
 


//#include <iostream>
//using namespace std;
//
//class Date {
//public:
//	/*Date(int year = 2, int month = 2, int day = 2) {
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}*/
//	void Print() {
//		cout << this->_year << "--" << this->_month << "--" << this->_day << endl;
//	}
//private:
//	int _year = 2025;	
//	int _month = 1;
//	int _day = 1;
//};
//int main() {
//	Date d1;
//	d1.Print();
//	return 0;
//}