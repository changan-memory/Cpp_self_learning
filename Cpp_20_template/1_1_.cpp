#include <iostream>
#include <vector>
#include <list>
using namespace std;
// 模板 的两大 控制作用
// 1. 控制容器中存放的数据的类型  实现容器中的类型的通配化
// 2. 控制代码的逻辑: 适配器模式：传入不同的容器或迭代器类型，可以适配出不同的容器和迭代器
// 只要是 传类型，就可以用模板，模板不仅仅是 类型参数化，还有更多的用法和功能，比如适配器
// 或者通过传入不同的类型   实现不同的功能

// 1. 
// 模板中 typename 和 class 的区别
// 场景1  遍历容器 假设有一个vector需要遍历
void Print(const vector<int>& v) {
	vector<int>::const_iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// 使用T有些不够优雅  因为这样使用  只能遍历vector
//template<class T>
//void Print(const vector<T>& v) {
//	vector<T>::const_iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

// 实现一个泛型的Print
//template<class Container>	   // STL中大部分用的都是class	    // 该场景下 
// 作模板参数中，使用typename和class效果一样
////template<class Container>

// 这里的 Container 不知到是什么，但是知道是一个容器
// 且可以支持所有的容器
template<typename Container>			
void Print(const Container& con) {
	// 不加 typename 时，编译前要先进行词法分析，此时模板参数 Container 尚未实例化，
	// 编译器不知道 Container::const_iterator 表示 类中的 静态成员变量
	// 还是类中 typedef 的类型，不能确定
	// 实例化之后才能确定类型
	
	// 报错的本质 是 不知道 Container::const_iterator 表示的是类型 还是对象

	//  这里必须加上typename 如果不加typename, Container::const_iterator 这种写法，
	// const_iterator 可能是静态成员变量，也可能是变量类型，不加typename编译器无法分辨，因此需要加上
	// 不加 typename 时， Container::const_iterator 这一堆，既可以是类型，也可以是对象()
	typename Container::const_iterator it = con.begin();	// 所有容器支持 const_iterator const迭代器
	//Container::const_iterator it = con.begin();	// 所有容器支持 const_iterator const迭代器
	// 这里Container 未实例化时，编译器不确定  Container::const_iterator 是类型还是static成员变量
	// typename  告诉编译器 这里 Container::const_iterator 是类型，让编译器知道这样的写法是合理的
	// 但具体是 等模板实例化后，再去 Container 类内找 类型
	// 只要是 取 未实例化的 类模板内 的内容，都不能确定 取的是 类型 还是 成员变量
	
	//auto it = con.begin();	可以用使用 auto auto的推导结果，表示的一定是类型
	// 但 auto 并不能解决所有场景的这个问题  因为 auto 不能用于模板参数列表中
	while (it != con.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

////template<class Container>
//template<typename Container>
//void Print(const Container& con) {
//	Container::const_iterator it = con.begin();	// 所有容器支持 const_iterator const迭代器
//	while (it != con.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
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
	list<double> l1;
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);
	l1.push_back(8);
	Print(l1);
}

// 场景2 非类型模板参数
// 有时 我们的模板会需要 不作为类型的模板参数，也就是非类型模板参数 

// 传统方式 利用宏定义一个静态栈
//#define N 20
//template<class T>
//class Stack {
//public:
//	
//private:
//	T _base[N];
//	int _top;
//};
//void test2() {	
//  // 定义的栈无法更改大小, 我想要一个10个空间 和 20 个空间的栈
//	Stack<int> st1;
//	Stack<int> st2;
//}

// 使用非类型 模板参数定义一个静态栈
// 非类型模板参数， 1 必须是常量， 2 必须是整形家族的 (size_t  char  int  unsigned int)
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
// 非类型模板参数 最开始的设计 就是为了 类似于 静态数组这样的实现

//int main() {
//
//	test1();
//	//test2();
//	return 0;
//}