#include <iostream>
using namespace std;

//类模板
template<class T>
class Stack {
private:
	T* _array;
	int _size;
	size_t _capacity;
public:
	Stack(size_t capacity = 4) {
		_array = new T[capacity];
		//检测指针是否为空，要抛异常
		_size = 0;
		_capacity = capacity;
	}
	void push(const T& data) {
		_array[size++] = data;
	}
	~Stack() {
		delete[] _array;
		_size = 0;
		_capacity = 0;
	}
};

// Stack是类名，Stack<int>才是类型
// Stack<int> st1; // int
// Stack<double> st2; // double
// 类模板和函数模板的声明和定义分离：第12集的55分钟 ----- 1小时5分钟

int main() {
	Stack<int> s1;	// int类型的栈
	Stack<double> s2;	// double类型的栈
	Stack<char> s3;	// char类型的栈
	return 0;
}