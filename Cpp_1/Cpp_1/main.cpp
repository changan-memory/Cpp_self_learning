#include <stdio.h>

//类域
//命名空间域

//全局作用域
//局部作用域

#include "Stack.h"
#include "Queue.h"

#include <iostream>

//局部域->全局域->  展开了命名空间域 或 指定访问命名空间域

// 1.
int a = 1;
namespace bit {
	int a = 10;
	int rand = 100000;
}	//命名空间的作用域后不能加分号

using namespace bit;
// ::域作用限定符
//通过作用域限定符来访问 特定命名空间中的变量
void Test1() {
	int a = 100;
	printf("%d\n", a);
	printf("%d\n", ::a);	//用:: 来访问全局作用域下的同名变量
	printf("%d\n", bit::a);	//用  namespace:: 来访问特定命名空间下的变量
}
//2.所有文件中，相同名字的命名空间会被合并
void Test2() {
	using namespace test_space;
	printf("%d\n", x);
	printf("%d\n", y);
}

//3. 命名空间可以嵌套
namespace N1
{
	int a;
	int b;
	int Add(int left, int right) {
		return left + right;
	}
	namespace N2
	{
		int c;
		int d;
		int Sub(int left, int right) {
			return left - right;
		}
	}
}

//3. C语言和C++的标准库 与命名空间
void Test3() {
	//第一种解决方案 using namespace std;
	using namespace std; //展开头文件
						//直接展开会有风险，可能自己定义的变量名和标准库中的重复，就会报错
						//项目中建议不要展开， 日常练习可以这么玩
						//项目中建议 指定访问，不要轻易展开命名空间
	cout << "hello world" << endl;		

	//第二种解决方案  使用 ::  域作用限定符
	std::cout << "hello world" << std::endl;

	//第三种解决方案  把常用的从命名空间中展开
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "hello world" << endl;
}
//4. C++的输入和输出
void Test4() {
	using std::cout;
	using std::endl;
	int x = 100;
	// << 流插入运算符
	// cout 可以自动识别类型
	cout << "hello world" << x << '\n' << endl;

	// >> 流提取运算符
	int y = 1000;
	std::cin >> x >> y;
	cout << x << " " << y << endl;

	//在某些对性能有要求的地方， printf/scanf 比 cout/cin 性能要好一丢丢(C语言输入输出要更快一点点)
}
int main() {
	Test1();
	//Test2();
	//Test3();
	//Test4();
	return 0;
}


