#include <iostream>
using namespace std;

//��ģ��
template<class T>
class Stack {
private:
	T* _array;
	int _size;
	size_t _capacity;
public:
	Stack(size_t capacity = 4) {
		_array = new T[capacity];
		//���ָ���Ƿ�Ϊ�գ�Ҫ���쳣
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

// Stack��������Stack<int>��������
// Stack<int> st1; // int
// Stack<double> st2; // double
// ��ģ��ͺ���ģ��������Ͷ�����룺��12����55���� ----- 1Сʱ5����

int main() {
	Stack<int> s1;	// int���͵�ջ
	Stack<double> s2;	// double���͵�ջ
	Stack<char> s3;	// char���͵�ջ
	return 0;
}