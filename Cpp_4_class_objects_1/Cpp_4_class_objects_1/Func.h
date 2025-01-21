#pragma once
#include <iostream>
//类的定义
class Stack {
public:
	void Init(int defaultCapacity = 4);
	void Push() {
		//.......
	}
	void Pop() {
		//.......
	}
private:
	int* base;
	int top;
	int capacity;
};