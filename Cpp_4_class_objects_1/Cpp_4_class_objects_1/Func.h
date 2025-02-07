#pragma once
#include <iostream>
//类的定义
class Stack {
public:
	void Init(int defaultCapacity = 4);
	//在类内定义的函数，会直接建议编译器让该函数称为内联函数，
	void Push() {	//类内定义的函数，不管加不加 inline ,都相当于加上了 inline 
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