#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

namespace m_string {
	class string {
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	public:
		//构造函数
		//string(const char* str)	//初始化列表是按照成员变量在类中声明的次序进行初始化的
		//	:_size(strlen(str))
		//	,_capacity(_size)
		//	,_str(new char[_capacity+1])
		//{
		//	strcpy(_str, str);	//别人调整了初始化列表的顺序会容易出错
		//}
		
		//用c_str构造
		//尽可能使用初始化列表初始化，但有些功能初始化列表完成不了。
		// 内置类型在 初始化列表/函数体内 初始化无所谓，自定义类型尽量在初始化列表
		//string(const char* str = '\0')
		//string(const char* str = nullptr)
		//string(const char* str = "\0")
		string(const char* str = "") {
			_size = strlen(str);
			_capacity = _size;	//capacity表示可以存放的下的字符个数
			_str = new char[_capacity + 1];		//开空间
			strcpy(_str, str);	//拷贝数据
		}
		//将无参构造通过缺省参数合并
		//string() {	//三种默认构造  无参的 全缺省的  我们不写编译器自己生成的
		//	_str = new char[1];
		//	_size = 0;
		//	_capacity = 0;
		//	_str[0] = '\0';
		//}

		//析构函数
		~string() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//返回c_str
		const char* c_str() {
			return _str;
		}
		
	};
}