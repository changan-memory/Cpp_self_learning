#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//类实例化对象，类相当于图纸，对象相当于根据图纸建造出来的房子
class A {
public:
	void Print_1() {
		cout << "_1" << endl;
	}
	void Print_2() {
		cout << "_2" << endl;
	}
private:
	int a;
	char b;
};
void TestClassSize() {
	A a1;
	A a2;
	A a3;
	cout << "A size" << sizeof(A) << endl;
	cout << "a1 size" << sizeof(a1) << endl;
	cout << "a2 size" << sizeof(a2) << endl;
}
//1. 第一个成员在与结构体偏移量为0的地址处。
//2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
//注意：对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
//VS中默认的对齐数为8
//3. 结构体总大小为：最大对齐数（所有变量类型最大者与默认对齐参数取最小）的整数倍。
//4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整
//体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。

//为什么要内存对齐？
//和硬件的设计有关，CPU读取数据，只能读4 or 8的整数倍
class A1 {
public:
	void print_() {
		cout << "A1" << endl;
	}
};
class A2 {};
//没有成员变量的类，编译器给了一个字节，用于占位，表示该类的对象存在
void TestEmptyClass() {	
	cout <<"A1 " << sizeof(A1) << endl;
	cout << "A2 " << sizeof(A2) << endl;
}

// this指针
class Date {
public:
	//this不能在形参和实参显示传递，但可以在函数内部调用
	void Init(int year, int month, int day) {
		/*_year = year;
		_month = month;
		_day = day;*/
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	void Print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//编译器会对成员函数进行处理，会给成员函数加上参数this
	/*void Print(Date* const this) {
		cout << _year << "-" << _month << "-" << _day << endl;
	}*/
private:
	int _year;
	int _month;
	int _day;
};
void Test_this() {
	Date d1, d2;
	//加了函数形参this指针后，对象在调用成员函数时，也会先传入对象的地址。这些都是编译器做的处理
	//d1.Init(&d1, 2025, 1, 21);s
	d1.Init(2025, 1, 21);
	d1.Print();
	d2.Init(2024, 1, 21);
	d2.Print();
}
//Date类中有 Init 与 Print 两个成员函数，d1和d2调用的是同一个函数函数体中没有关于不同对象的区分
//那当d1调用 Init 函数时，该函数是如何知道应该设置d1对象，而不是设置d2对象呢？
//C++中通过引入this指针解决该问题，即：C++编译器给每个“非静态的成员函数“增加了一个隐藏的指针参数
//让该指针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有“成员变量”
//的操作，都是通过该指针去访问。只不过所有的操作对用户是透明的，即用户不需要来传递，编
//译器自动完成。

//思考this指针存在哪里？ 对象内  栈区  堆区  静态区  常量区
//this是形参，因此和普通形参一样，存放在函数调用时的栈帧中，
//this指针在函数内部是要反复调用的, vs的编译器对this指针传递做了优化，对象地址放在ecx寄存器中
//exc中存储this指针的值

//对空指针解引用会在运行时报错
//关于this指针的思考题
class TestThis {
public:
	void Print() {
		cout << "Print" << endl;
	}
	void PrintA() {
		cout << _A << endl;
	}
private:
	int _A;
};
void Test_This_1() {
	TestThis* p = nullptr;
	p->Print();
}
void Test_This_2() {
	TestThis* p = nullptr;
	p->PrintA();
}
//调用两个函数的结果分别是什么  1.编译时报错   2. 运行时崩溃   3. 正常运行
int main() {
	//TestClassSize();
	//TestEmptyClass();
	//Test_this();
	Test_This_1();
	//Test_This_2();
	return 0;
}