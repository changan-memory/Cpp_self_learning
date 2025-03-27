#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
using namespace std;

namespace m_string {
	class string {
	public:
		//STL中的迭代器，可能是指针，也可能不是指针
		//string的迭代器本质上是char*
		typedef char* iterator;
		typedef const char* const_iterator;
		
		//普通对象的迭代器
		iterator begin() {		
			//return &_str[0];
			return _str;	//数组名是第一个元素的地址
		}
		iterator end() {
			//return &_str[_size];
			return _str+_size;
		}
		//const对象迭代器
		const_iterator begin() const {
			return _str;	
		}
		const_iterator end() const {
			return _str + _size;
		}
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
		//string(const char* str = "\0")	//这个写法会让结尾有两个"\0"
		//字符串的结束位置必须有\0
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
		//返回c_str			const 修饰this指针指向的对象，可以让普通对象和const对象都可以调
		//函数内不修改对象，建议加上const
		const char* c_str() const {
			return _str;
		}
		//返回_size
		size_t size() const {
			return _size;
		}

		char& operator[](size_t pos) {	//返回引用，读写版本
			assert(pos < _size);
			return _str[pos];
		}	//const对象调const版本[]    普通对象调普通版本[]

		const char& operator[](size_t pos) const {	//只读版本
			assert(pos < _size);
			return _str[pos];
		}

		//可以用reserve来实现扩容
		void reserve(size_t spaceSize) {	//spaceSize指的是字符的个数
			if (spaceSize > _capacity) {
				char* newSpace = new char[spaceSize + 1];	//多开一个空间存放\0
				strcpy(newSpace, _str);
				delete[] _str;
				_str = newSpace;
				_capacity = spaceSize;
			}
		}
		//+=的本质是push_back因此先实现push_back
		void push_back(char ch) {
			//先考虑扩容
			if (_size == _capacity) {
				//二倍扩容
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size++] = ch;	//放字符
			_str[_size] = '\0';	//加上\0
		}
		void append(const char* str) {
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				//至少扩容到_size + len
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
	};
}