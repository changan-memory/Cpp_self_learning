#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
#include <cstring>
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
			_str = new char[_capacity + 1];		//开空间+1  要存放'\0'
			//strcpy(_str, str);	//拷贝数据,遇到中间含有\0的字符串会有Bug
			//strcpy默认会 拷贝\0， 因此使用memcpy，需要将拷贝的字节数+1，是\0的位置
			memcpy(_str, str, _size + 1);	
		}
		//将无参构造通过缺省参数合并
		//string() {	//三种默认构造  无参的 全缺省的  我们不写编译器自己生成的
		//	_str = new char[1];
		//	_size = 0;
		//	_capacity = 0;
		//	_str[0] = '\0';
		//}

		//拷贝构造  简单实现深拷贝
		string(const string& str) {
			_str = new char[str._capacity + 1];
			//strcpy(_str, str._str);
			memcpy(_str, str._str, str._size + 1);
			_size = str._size;
			_capacity = str._capacity;
		}
		
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

		//[]重载		//const对象调const版本[]    普通对象调普通版本[]
		char& operator[](size_t pos) {	//返回引用，读写版本
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const {	//只读版本
			assert(pos < _size);
			return _str[pos];
		}

		//可以用reserve来实现扩容
		//考虑特殊情况的话，memcpy会更好
		void reserve(size_t request_size) {	//request_size指的是要存放的字符的个数
			if (request_size > _capacity) {	//请求的空间大于_capacity时，才扩容
				char* newSpace = new char[request_size + 1];	//多开一个空间存放\0
				//strcpy(newSpace, _str);		//new是异地扩容
				memcpy(newSpace, _str, _size + 1);
				delete[] _str;
				_str = newSpace;
				_capacity = request_size;
			}
		}
		//+=的本质是push_back因此先实现push_back
		void push_back(char ch) {
			//先考虑扩容
			if (_size == _capacity) {
				//二倍扩容,并防止空构造的字符串
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
			//strcpy(_str + _size, str);
			memcpy(_str + _size, str, len + 1);
			_size += len;	//插入后_size要改变
		}
		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str) {
			append(str);
			return *this;
		}

		void insert(size_t pos, size_t n, char ch) {
			assert(pos <= _size);	//_size位置是字符串的末尾，可以在字符串的末尾插入
			//扩容
			if (_size + n > _capacity)
				reserve(_size + n);
			//挪动数据
			//当传入的pos为0时，end会变成-1，end是size_t,-1会变成整形的最大值，会一直进入循环
			//size_t end = _size;	
			//int end = _size;	
			//while (end >= (int)pos) {	//运算符两端 两个操作数类型不一致时，会进行提升
			//						// 一般是范围小的向范围大的进行提升
			//	_str[end + n] = _str[end];
			//	--end;
			//}
			size_t end = _size;
			while (end >= pos && end != npos) {
				_str[end + n] = _str[end];
				--end;
			}
			for (size_t i = 0; i < n; ++i) {
				_str[pos + i] = ch;
			}
			_size += n;
			_str[_size] = '\0';		//添加字符串结束标志
		}
		void insert(size_t pos, const char* str) {
			assert(pos <= _size);	//_size位置是字符串的末尾，可以在字符串的末尾插入
			size_t len = strlen(str);
			//扩容
			if (_size + len > _capacity)
				reserve(_size + len);

			size_t end = _size;
			while (end >= pos && end != npos) {
				_str[end + len] = _str[end];
				--end;
			}
			for (size_t i = 0; i < len; ++i)
				_str[pos + i] = str[i];

			_size += len;
			_str[_size] = '\0';		//添加字符串结束标志
		}
		//从pos位置开始删，删除len个字符，不传参默认删完
		void erase(size_t pos, size_t len = npos) {
			assert(pos);
			if (len == npos || pos + len > _size) {		//这两种都是删完的情况
				_str[pos] = '\0';
				_size = pos;
				_str[_size] = '\0';
			}
			else {
				size_t end = pos + len;
				while (end < _size) {	//end = '\0'时，可以把'\0'也挪过来
					_str[pos++] = _str[end++];
					//++end;
				}
				_size -= len;
				_str[_size] = '\0';
			}
		}
		//查找字符
		size_t find(char ch, size_t pos = 0) const {
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0) const {
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, str);	//可以从不同的位置开始查找
			if (ptr)
				return ptr - _str;
			else
				return npos;
		}

		string substr(size_t pos = 0, size_t len = npos) const {
			assert(pos < _size);
			size_t n = len;
			if (len == npos || (pos + len) > _size)
				n = _size - pos;
			string tmp;
			tmp.reserve(n);
			for (size_t i = pos; i < pos + n; ++i) {
				tmp += _str[i];
			}
			return tmp;	//出了作用域，对象销毁，要用值传递
		}

		void resize(size_t newSize, char ch = '\0') {
			if (newSize < _size) {
				_size = newSize;
				_str[_size] = '\0';
			}
			else {
				//reserve会判断newSize和_capacity的大小，超过扩容，小于不做处理
				reserve(newSize);
				//扩容后进行初始化
				for (size_t i = _size; i < newSize; ++i)
					_str[i] = ch;
				_size = newSize;
				_str[_size] = '\0';
			}
		}
		//清空数据
		void clear() {
			_str[0] = '\0';
			_size = 0;
		}

		bool operator<(const string& str) {
			//return strcmp(_str, str.c_str());	//strcmp遇到\0终止，可能会对特定的字符串有意外
			/*if (_size == str._size)
				return memcmp(_str, str.c_str(), _size) < 0;
			const string* pstr_low = this;
			const string* pstr_high = &str;
			if (_size > str._size) {
				std::swap(pstr_low, pstr_high);
			}
			
			bool res1 = memcmp(pstr_low->c_str(), pstr_high->c_str(), pstr_low->_size);
			bool res2 = memcmp(pstr_low->c_str(), pstr_high->c_str(), pstr_low->_size);*/
				
		}
	private:
		size_t _size;
		size_t _capacity;	//_capacity一般不包含\0
		char* _str;
		//static::size_t npos = -1;	//静态成员变量不能给缺省值，缺省值是给初始化列表用的
		//可以这么用，但是不建议
	public:
		const static size_t npos;	//建议静态成员变量，声明和定义分离
	};
	const size_t string::npos = -1;
}

// 成员函数的第一个参数是this
// 我们希望第一个参数是流对象，因此要重载成全局的
ostream& operator<<(ostream& out, const m_string:: string& s) {
	//ostream做了一件事，做了防拷贝，因此ostream做参数或返回值时要用引用
	for (int i = 0; i < s.size(); ++i)
		out << s[i];
	/*for (auto& e : s)
		out << e;*/
	return out;
}

//流提取不能加 const
istream& operator>>(istream& in, m_string::string& s) {
	/*char ch;
	in >> ch;*/
	//s.clear();	//每次读取要先清空,防止 多次输入数据时，数据重叠
	char ch = in.get();
	char buff[128];

	//清空 第一个有效数据来临前的空格和换行
	while (ch == ' ' || ch == '\n') {
		ch = in.get();
	}
	int i = 0;
	while (ch != ' ' && ch != '\n'){	//这种写法读不到字符串中的空格或换行,认为
										//可以选择 使用 \n 还是 ' '作为字符串的分隔符
		//s += ch;		//+=，当输入的字符串非常大时，会不断扩容,利用buff减少扩容的次数
		buff[i++] = ch;
		if (i == 127) {
			buff[i] = '\0';
			s += buff;
			i = 0;
		}
		//in >> ch;
		ch = in.get();
	}
	if (i != 0) {
		buff[i] = '\0';
		s += buff;
	}
	return in;
}