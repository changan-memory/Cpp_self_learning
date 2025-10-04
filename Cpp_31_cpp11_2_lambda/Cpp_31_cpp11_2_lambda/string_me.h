#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
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
		// 如果加了const会导致，非const对象只能返回const_iterator，失去修改元素的能力（违反直觉）。
		iterator begin() {		
			//return &_str[0];
			return _str;	//数组名是第一个元素的地址
		}
		iterator end() {
			//return &_str[_size];
			return _str+_size; 
		}
		//const对象迭代器
		const_iterator begin() const { return _str; }
		const_iterator end() const { return _str + _size; }

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
		// 内置类型在 初始化列表/函数体内 初始化无所谓，自定义类型尽量在初始化列表初始化
		//string(const char* str = '\0')
		//string(const char* str = nullptr)
		//string(const char* str = "\0")	//这个写法会让结尾有两个"\0"
		//字符串的结束位置必须有\0
		string(const char* str = "") {	//用c风格的字符串进行构造，默认以\0为结束符
			 cout << "string(const char* str = "") -- 直接构造" << endl;

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

		//拷贝构造  要实现深拷贝，开一块新的空间，拷贝数据，并初始化
		string(const string& str) {
			cout << "string(const string& str) -- 深拷贝" << endl;
			_str = new char[str._capacity + 1];
			//strcpy(_str, str._str);
			memcpy(_str, str._str, str._size + 1);
			_size = str._size;
			_capacity = str._capacity;
		}
		// 移动拷贝构造
		string(string&& str) {
			cout << "string(string&& str) -- 移动拷贝构造" << endl;
			swap(str);
		}


		//以下是string的构造函数的现代写法，这种写法在遇到中间含有\0字符串会有问题
		//s2(s1)
		//string(const string& s) 
		//	:_str(nullptr)
		//	,_size(0)
		//	,_capacity(0)
		//{
		//	string tmp(s.c_str());	//tmp内存放有s1的_str空间地址，_size和_capacity
		//	this->swap(tmp);			//交换tmp和s2内的三个成员变量，
		//						//交换后tmp内的_str为nullptr,局部对象出了函数作用域销毁后，析构tmp对象

		//	//构造tmp时使用s.c_str()初始化，而c_str返回以\0结尾的C风格字符串
		//	//若s._str中间含有\0，tmp的构造会截断数据，导致拷贝不完整
		//}
		
		// 传统写法
		//	s1 = s3
		//string& operator=(const string& str) {
		//	if (this != &str) {
		//		char* newSpace = new char[str._capacity + 1];	//开空间
		//		memcpy(newSpace, str._str, str._size + 1);		//拷数据
		//		delete[] _str;			//被赋值前可能为非空string，因此要释放原空间
		//		_str = newSpace;

		//		_size = str._size;
		//		_capacity = str._capacity;
		//	}
		//	return *this;
		//}

		//赋值的现代写法
		string& operator=(const string& str) {
			string tmp(str);
			this->swap(tmp);
			return *this;
		}
		
		//string& operator=(string tmp) {
		//	cout << "string& operator=(string str) -- 深拷贝赋值" << endl;
		//	//可以直接
		//	this->swap(tmp);
		//	return *this;
		//}

		// 用右值引用 实现移动赋值 的写法
		string& operator=(string&& str) {
			cout << "string& operator=(string&& str) -- 移动赋值" << endl;
			swap(str);
			return *this;
		}
		

		// 交换两个string对象成员变量的内容
		void swap(string& str) {		
			std::swap(_str, str._str);		//不能直接交换两个对象
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}
		//// s1 = s3
		//string& operator=(string tmp) {		//直接利用函数参数，深拷贝s3，函数结束后,形参自动析构
		//	this->swap(tmp);			// 将s3的拷贝和s1 也就是 *this 交换
		//	return *this;		// 返回*this, 也就是 s1
		//}
		

		//析构函数
		~string() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//返回c_str			const 修饰this指针指向的对象，可以让普通对象和const对象都可以调
		//函数内不修改对象，建议加上const
		const char* c_str() const { return _str; }

		size_t size() const { return _size; }
		size_t capacity() const { return _capacity; }

		//清空数据
		void clear() {
			_str[0] = '\0';
			_size = 0;
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
		void reserve(size_t request_capacity) {	//request_size指的是要存放的字符的个数
			if (request_capacity > _capacity) {	//请求的空间大于_capacity时，才扩容
				char* newSpace = new char[request_capacity + 1];	//多开一个空间存放\0
				//strcpy(newSpace, _str);		//new是异地扩容
				memcpy(newSpace, _str, _size + 1);		//拷贝\0
				delete[] _str;
				_str = newSpace;
				_capacity = request_capacity;
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
			assert(str != nullptr); // 确保str非空
			size_t len = strlen(str);
			//扩容
			if (_size + len > _capacity)
				reserve(_size + len);

			size_t end = _size;		//从末尾的 \0 开始挪动
			//如果在 0 位置插入 end最后会变成 size_t -1 也就是npos 整形的最大值
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
			assert(pos <= _size);
			if (len == 0)
				return;
			// pos + len == _size时，pos + len位置放的是\0,大于时才全部删完
			if (len == npos || pos + len > _size) {		//这两种都是删完的情况
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				size_t end = pos + len;
				while (end < _size) {	//end = '\0'时，可以把'\0'也挪过来
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
			_str[_size] = '\0';	//统一设置结尾符
		}
		//查找字符
		size_t find(char ch, size_t pos = 0) const {
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i) {
				if (_str[i] == ch) 
					return i;
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0) const {
			assert(pos <= _size);	//允许查找空串，查找空串返回npos
			const char* ptr = strstr(_str + pos, str);	//可以从不同的位置开始查找
			if (ptr)
				return ptr - _str;
			else
				return npos;
		}
		//substr到底找的是什么？？？
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
				//reserve会判断newSize和_capacity的大小，超过扩容，小于 等于时不做处理
				reserve(newSize);
				//扩容后进行初始化
				for (size_t i = _size; i < newSize; ++i)
					_str[i] = ch;
				_size = newSize;
				_str[_size] = '\0';
			}
		}

		// hello hello false
		// helloxxx hello false
		// hello helloxxx true
		bool operator<(const string& str) const {
			size_t i1 = 0, i2 = 0;
			//先比较同样的长度
			while (i1 < _size && i2 < str._size) {
				if (_str[i1] < str._str[i2])
					return true;
				else if (_str[i1] > str._str[i2])
					return false;
				else {
					++i1;
					++i2;
				}
			}
			//到这里 i1 == _size 且 i2 == str._size
			// i1 == _size && i2 != str_size时，代表str后面还有字符串，说明后面的更大
			return i1 == _size && i2 != str._size;
		}
		//复用库的方式
		//bool operator<(const string& str) const {
		//	int ret = memcmp(_str, str._str, _size < str._size ? _size : str._size);
		//	return ret == 0 ? _size < str._size : ret < 0;
		//	//return ret < 0 ? true : false;   错误方式
		//}
		bool operator==(const string& str) const {
			return _size == str._size			//两个字符串相等，其长度一定相等
				&& memcmp(_str, str._str, _size) == 0;		//再比较其内容是否相等
		}
		bool operator<=(const string& str) const {
			return *this < str || *this == str;
		}
		bool operator>(const string& str) const {
			return !(*this <= str);
		}
		bool operator>=(const string& str) const {
			return (*this < str);
		}
		bool operator!=(const string& str) const {
			return !(*this == str);
		}
	private:
		char* _str = nullptr;
		size_t _size;
		size_t _capacity;	//_capacity一般不包含\0
		//static::size_t npos = -1;	//静态成员变量不能给缺省值，缺省值是给初始化列表用的
		//可以这么用，但是不建议
	public:
		const static size_t npos = -1;	//建议静态成员变量，声明和定义分离
	};
	//类内声明、类外初始化
	//const size_t string::npos = -1;
}

//// 成员函数的第一个参数是this
//// 我们希望第一个参数是流对象，因此要重载成全局的
//// c的字符数组，以\0为终止算长度
//// string不看\0，以size为终止算长度
//ostream& operator<<(ostream& out, const m_string:: string& s) {
//	//ostream这个类做了一件事，做了防拷贝，因此 ostream 类对象 做参数或返回值时要用引用
//
//	//实现方式 1
//	//out << s.c_str();		// 调用c_str() 可以直接打印
//	//out << s.c_str;			// 访问s._str 实现字符串打印
//	// 以上两种方式，打印 c_str 遇到 "hello world\0hello Linux" 中间含有\0的字符串时，是错误的
//	// 流插入的要求是，有多少内容，打印多少内容 因此不能遇到\0终止
//	
//
//	// 使用一个一个遍历字符的方式  实现打印
//	/*for (int i = 0; i < s.size(); ++i)
//		out << s[i];*/
//	for (auto& e : s)
//		out << e;
//	return out;
//}
//
//// 流提取 的string形参不能加 const，引入数据要流入 m_string::string& s
////istream& operator>>(istream& in, m_string::string& str) {
////	//一个一个字符读
////	/*char ch;
////	in >> ch;*/
////
////	//用cin和scanf输入数据时，要以空格和换行进行分割多个值，注定cin和scanf默认读取不到空格和换行
////	// 可用 istream 类对象的 get 方法来解决这个问题,get可以读入任意的字符
////	//用in.get() 读
////	char ch = in.get();
////	str.clear();	// 对同一个string进行多次输入时，每次输入前要进行初始化。
////	// 如果不初始化，会出现字符串堆叠
////
////	//以空格或换行分割字符串
////	while (ch != ' ' && ch != '\n') {
////		str += ch;
////		//in >> ch;
////		ch = in.get();
////	}
////	return in;
////}
//
//// istream v2版本
//istream& operator>>(istream& in, m_string::string& s) {
//	s.clear();	//每次读取要先清空缓冲区,防止 多次输入数据时，数据重叠
//	char ch = in.get();
//	char buff[127] = { '\0' };
//
//	//清空 第一个有效数据 来临前的空格和换行
//	while (ch == ' ' || ch == '\n')
//		ch = in.get();		// 读了之后，直接去读下一个字符，就可以表示清除了
//
//	int i = 0;
//	//while (ch != '\n') {				// 这种写法,类似于getline的实现，以换行符作为多个字符串的分隔
//	while (ch != ' ' && ch != '\n') {	//这种写法读不到字符串中的空格或换行
//										//可以选择 使用 \n 还是 ' '作为字符串的分隔符
//		//s += ch;		//+=，当输入的字符串非常大时，会不断扩容,利用buff减少扩容的次数
//		buff[i++] = ch;
//		if (i == 127) {
//			buff[i] = '\0';
//			s += buff;
//			i = 0;
//		}
//		ch = in.get();
//	}
//	// i != 0 说明里面还有数据
//	if (i != 0) {
//		buff[i] = '\0';
//		s += buff;
//	}
//	return in;
//}

