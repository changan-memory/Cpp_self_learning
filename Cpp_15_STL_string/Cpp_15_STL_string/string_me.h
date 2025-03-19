#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

namespace string_me {

	class string {
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		//初始化列表是按照变量在类中  声明的顺序 初始化的
		string(const char* str)
			//:_str(str)	//这样写是权限的放大
			:_str(new char[strlen(str)+1])
			,_size(strlen(str))
			,_capacity(strlen(str))
		{
			strcpy(_str, str);
		}
	};
}