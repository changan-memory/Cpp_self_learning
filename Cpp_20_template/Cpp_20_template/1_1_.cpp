// 1. 非类型模板参数


#include <iostream>
#include <vector>
#include <list>
using namespace std;
// 模板 的两大好处
// 1. 控制容器中存放的数据的类型
// 2. 适配器模式：传入不同的容器或迭代器类型，可以适配出
//只要是传类型，就可以用模板，模板不仅仅是类型参数化，还有更多的用法和功能，比如适配器


// 模板中 typename 和 class 的区别
// 场景1  遍历容器 假设有一个vector需要遍历
//void Print(const vector<int>& v) {
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

// 实现一个泛型的Print
//template<class Container>	   // STL中大部分用的都是class	    // 该场景下 
// 模板参数中，使用typename和class效果一样
template<typename Container>			
void Print(const Container& con) {
	// 所有容器都有 const_iterator
	typename Container::const_iterator it = con.begin();
	//  这里必须加上typename 如果不加typename, Container::const_iterator 这种写法，
	// const_iterator 可能是静态成员变量，也可能是变量类型，不加typename编译器无法分辨，因此需要加上
	// 不加 typename 时， Container::const_iterator 这一堆，既可以是类型，也可以是对象
	
	// 这里Container模板还没实例化，编译器不确定  Container::const_iterator 是类型还是static成员变量
	// typename  告诉编译器 这里是类型，等模板实例化再去找
	while (it != con.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test1() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	for (auto e : v1)
		cout << e << " ";
	cout << endl;
	Print(v1);
}

// 场景2 非类型模板参数
// 传统方式 利用宏定义一个静态栈
//#define N 20
//template<class T>
//class Stack {
//public:
//	
//private:
//	T _array[N];
//	int _top;
//};
//void test2() {	
//  // 定义的栈无法更改大小
//	Stack<int> st1;
//	Stack<int> st2;
//}

// 使用非类型 模板参数定义一个静态栈
// 非类型模板参数， 1 必须是常量， 2 必须是整形家族 (size_t  char  int  unsigned int)
template<class T, size_t N>
class Stack {
public:
	void func() {
		//N = 20;			//  N 是常量，不能修改
	}
private:
	T _array[N];
	int _top;
};
void test2() {
	Stack<int, 10> st1;
	Stack<int, 20> st2;
	// 有些编译器会进行按需实例化，如果我没有调用func，那么就不会对func进行检查。此行为称为按需实例化
	st1.func();
}

//int main() {
//
//	//test1();
//	test2();
//	return 0;
//}