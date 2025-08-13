#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Point {
	//explicit Point(int x, int y)
	Point(int x, int y)
		:_x(x)
		, _y(y)
	{
		cout << "Point(int x, int y)" << endl;
	}
	int _x;
	int _y;
};
// 特性1 统一的列表初始化 {}
namespace use_1{
	// 一切皆可用{}初始化，并且可以不写 赋值的=
	void test1() {
		int x = 1;	// 赋值
		int y(2);	// C++中内置类型也有构造函数
		int z = { 3 };	// 列表初始化
		int w{ 4 };		// 不写 赋值的= 的列表初始化
		// 以下写法 本质都会调用构造函数
		Point p0(0, 0);
		Point p1 = { 1, 1 };
		Point p2{2, 2};
	}
	void test2() {
		int* p1 = new int[3] {1, 2, 3};
		int* p2 = new int[3]{ 2, 4, 6 };

		Point ptr0(0, 0);	// 调用构造函数*1
		// 之前是单参数的构造函数支持隐式类型转换

		// 这里语法的本质是  多参数构造函数的隐式类型转换
		Point ptr1 = { 1, 1 };	 //调用构造函数*1
		Point* ptr2 = new Point[2]{Point(1, 2), Point(3, 4)};	 //调用构造函数*2
		Point* ptr3 = new Point[2]{ptr0, ptr1};		// 这里没有调用构造函数
		// 下面这行这里语法的本质是  多参数构造函数的隐式类型转换
		Point* ptr4 = new Point[2]{ {2, 2}, {3, 3} };	 //调用构造函数*2

		// {1, 8}会生成一个Point的临时对象，临时对象具有常性，需要用常引用
		//Point& rp0 = { 1, 8 };
		const Point& rp = { 1, 8 };
	}
	// 简易日常定义，不要去掉=，但是我们自己要能看懂列表初始化的这个语法
}

// 特性2  std::initializer_list 先跳过了
namespace use_2 {
	void test1() {
		vector<int> v = { 1, 2, 3 };	// 这里的语法不是 {}列表初始化
		Point p = { 1, 2 };	// vector可以在后面加
		// 以上两行 是不同的语法
	}
}
int main() {
	//use_1::test1();
	use_1::test2();
	return 0;
}