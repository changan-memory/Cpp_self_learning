#include <iostream>
using namespace std;

class A {
public:
	//不传参的都是默认构造函数，包括：无参构造函数，全缺省的构造函数，我么不写编译器自动生成的构造函数
	A(int a) :_a(a) {

	}
private:
	int _a;
};

class B {
public:
	//建议多使用 初始化列表进行初始化

	//初始化列表  是对象的成员定义的位置
	B(int a, int& ref)
		:_ref(ref)	//防止局部变量的引用
		,_n(1) 
		,_x(2)
		,_obj_a(111)	//无默认构造，在初始化列表中显式调用默认构造(利用默认构造函数定义对象)
	{
		//在构造函数内 是赋值，可以多次赋值，不是初始化，因为初始化只能有一次
		//_n = 0;	//函数体内赋值不能对 const 初始化
		//_ref = ref
	}
private:
	//以下成员变量都是 声明
	A _obj_a;		//自定义类型没有默认构造函数，必须在初始化列表进行初始化

	//特征: 必须在定义的时候初始化   成员变量在对象定义的时候整体定义
	int& _ref;		//引用
	const int _n;	//const

	int _x = 1;	//这里的 1 是缺省值，是给初始化列表的，内置类型有缺省值，就用缺省值取初始化
	//内置类型不做处理，自定义类型会去调用默认构造
};


class Stack {
	typedef int DataType;
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
public:
	Stack(size_t capacity = 10) {
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (_array = nullptr) {
			perror("malloc failed\n");
			return;
		}
		_size = 0;
		_capacity = capacity;
	}
	void Push(const DataType& data) {
		//checkCapacity();
		_array[_size] = data;
		_size++;
	}
	~Stack() {
		free(_array);
		_array = nullptr;
		_size = 0;
		_capacity = 0;
	}
};
class MyQueue {
private:
	Stack _pushst;
	Stack _popst;
	int _size = 0;	//缺省值最舒服的用法
public:
	MyQueue(){}
	//初始化列表，就算我们不写，也会去自动走一遍初始化列表，因为初始化列表是成员变量定义的地方
	MyQueue(int capacity)
		:_pushst(capacity)
		,_popst(capacity)
	{}
};
//int main() {
//	//自定义类型
//	//MyQueue q1;		//调用默认构造函数
//	//MyQueue q2(100);	//显式调用构造函数
//	return 0;
//}

class Stack_1 {
private:
	int* _base;
	int _top;
	int _capacity;
public:
	//初始化列表无法代替在构造函数体内赋值
	//不管是否写初始化列表，都会走一遍初始化列表，以后都建议使用初始化列表
	Stack_1(int capacity = 10)
		:_base((int*)malloc(sizeof(int) * capacity))	//该情况下初始化列表无法对malloc的空间进行检查
		, _top(0)
		, _capacity(capacity) 
		//: _top(0)		// 成员变量在类内的声明的次序 就是 初始化列表初始化的顺序
		//, _capacity(capacity)
		//, _base((int*)malloc(sizeof(int) * _capacity))	//这样写 以为 _capacity 已完成初始化
		//但由于先初始化 _base , 此时_capacity是随机值，因此会malloc失败
		//建议，初始化列表中的初始化次序 和 成员变量的声明顺序保持一致！！！
		
	{
		if (nullptr == _base) {
			perror("malloc failed\n");
			return;
		}
		//要求数组初始化一下
		memset(_base, 0, sizeof(int) * capacity);
	}
};
//初始化列表无法满足的场景 ---------- 动态开辟一个二维数组
class AA {
private:
	int** _base;
	int _row;
	int _col;
public:
	AA(int row = 10, int col = 10)
		:_row(row)
		, _col(col)
	{
		_base = (int**)malloc(sizeof(sizeof(int*) * row));
		if (_base == nullptr) {
			perror("malloc failed\n");
			return;
		}
		for (int i = 0; i < row; ++i) {
			_base[i] = (int*)malloc(sizeof(int) * col);
		}
	}
};

int main() {

	//这是对象整体定义，初始化列表是对象的成员定义的地方
	int num = 10;
	B bb(10, num);
	//自定义类型
	//MyQueue q1;		//调用默认构造函数
	//MyQueue q2(100);	//显式调用构造函数

	return 0;
}