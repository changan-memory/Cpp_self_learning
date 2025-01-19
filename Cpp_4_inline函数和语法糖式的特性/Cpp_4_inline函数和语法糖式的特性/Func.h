#pragma once
#include <iostream>
using namespace std;

//inline int F(int x, int y);

//内联函数的声明和定义直接写在头文件中， 就不会产生链接问题
//所有用到内联函数的地方，直接声明和定义同时写
inline void F(int x, int y) {
	cout << x << " " << y << endl;

}