#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <assert.h>
//C语言初始化和销毁经常忘记
//类和对象
//类的六个默认成员函数

//这些函数式特殊的成员函数


class Stack {
	typedef int StackDataType;		//括号匹配需要把 int 换成char
public:
	//栈有了构造和析构函数，就不怕忘记初始化和释放内存了
	//使用构造函数初始化，构造函数可以重载
	
	//构造函数
	/*	1. 函数名与类名相同。
		2. 无返回值。
		3. 对象实例化时编译器自动调用对应的构造函数。
		4. 构造函数可以重载。
		5. 如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦
		   用户显式定义编译器将不再生成。 */

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

	//析构函数
	/*1. 1. 析构函数名是在类名前加上字符 ~。
		 2. 无参数无返回值类型。
		 3. 一个类只能有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。注意：析构函数不能重载
		 4. 对象生命周期结束时，C++编译系统系统自动调用析构函数*/
	//有了构造函数和析构函数，就不怕忘记初始化和释放内存了！！！
	~Stack() {
		cout << "~Stack" << endl;
		if(this->base){
			free(this->base);
			this->base = nullptr;
			this->capacity = 0;
			this->top = 0;
		}
	}
private:
	StackDataType* base;
	int top;	//top表示栈顶元素的下一个位置
	int capacity;
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
class Date {
public:
	//无参构造函数和全缺省构造函数，在调用时会产生歧义
	//无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。
	//注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认构造函数。
	//这三个只能存在一个
	
	//区分 默认成员函数  和 默认构造函数
	//默认构造函数 就是
	//默认成员函数 是 编译器生成的六个默认成员函数
	Date(int year = 1, int month = 1, int day =1) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	/*Date() {}*/

	/*Date(int year, int month, int day) {	//和缺省值参数相比，这个函数就没有存在的必要了
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}*/
	
	void Print() {
		cout << this->_year << "--" << this->_month << "--" << this->_day << endl;
	}
	//我们不写构造函数，编译器会生成默认构造函数，
	/* C++把类型分成内置类型(基本类型)和自定义类型。内置类型就是语言提供的数据类型，如：int / char...
		自定义类型就是我们使用class / struct / union等自己定义的类型
		编译器生成默认的构造函数,对内置类型不做处理，对自定义数据类型会调用他的默认构造函数*/
private:
	//内置类型
	//注意：C++11 中针对内置类型成员不初始化的缺陷，又打了补丁，即：内置类型成员变量在
	// 类中声明时可以给缺省值， 缺省值是给默认构造函数使用
	int _year = 2025;
	int _month = 1;
	int _day = 1;

	//自定义类型
	Stack _st;

	//一般情况下， 有内置类型成员，需要自己写构造函数，不能用编译器默认生成的
	//类内全部都是自定义类型时， 可以考虑让编译器自己生成
};
void TestNULLparameter() {
	Date d1;
	Date d2;
	d2.Print();
}
void TestCallConstruct() {
	//构造函数的调用和普通函数不同，构造函数是对象+初始化参数 或者 自动调用
	Date d1;
	//Date d1();	//不能这样写，这样会和函数声明区分不开
	Date d2(2025, 1, 1);
}
int main() {
	//TestStackClass();
	//TestNULLparameter();
	TestCallConstruct();
	return 0;
}