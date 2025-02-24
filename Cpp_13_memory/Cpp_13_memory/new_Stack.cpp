#include <iostream>
using namespace std;

class Stack {
private:
	int* _base;
	int _capacity;
	size_t _size;
public:
	Stack(int capacity = 4)
		:_capacity(capacity)
		, _size(0) 
	{
		_base = new int[capacity] {0};
	}
	void Push(int data) {
		_base[_size++] = data;
	}
	~Stack() {
		_size = 0;
		_capacity = 0;
		delete[] _base;
		_base = nullptr;
	}

};
//int main() {
//	//对new应该进行这样的检查，因为new失败后不会返回空，而是抛异常
//	try {
//		Stack* p1 = new Stack;
//		delete p1;
//	}
//	catch(const exception& e){
//		cout << e.what() << endl;
//	}
//	return 0;
//}