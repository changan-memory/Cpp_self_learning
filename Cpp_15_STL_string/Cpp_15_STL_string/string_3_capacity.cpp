#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using namespace std;

//capacity相关接口
// string 的底层是一个类似于顺序表的结构
void Test_3_1() {
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;	//查看当前字符串的容积，capacity的结果一般比size大一点
	//但具体大多少 和  capacity 扩容的结果取决于编译器的实现

	cout << s1.max_size() << endl;	//这个最大长度，在不同的平台下结果不一样，实际使用时毫无意义
}

void Test_3_2() {
	string s;
	// reserve 会改变 string 对象的 capacity, 
	// 预先知道了字符串的长度时，可以预先开辟空间，减少插入时的扩容开销
	s.reserve(100);		//设置100一般会比100要更大，但具体实现取决于平台和编译器
	size_t sz = s.capacity();
	cout << sz << endl;		//reserve一般不进行缩容，具体取决于编译器的实现
	for (int i = 0; i < 100; i++) {
		s.push_back('c');
		if (sz != s.capacity()) {
			sz = s.capacity();
			cout << " capacity changed" << endl;
		}
	}
}

// test resize
void Test_resize() {
	string s1("hello world");

	s1.reserve(100);	//单纯的改变空间大小,但不一定是100
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	//s1.resize(100);	//开空间+填值进行初始化，默认填'\0'
	s1.resize(120, 'x');	//开空间+填值进行初始化，默认填'\0'
	// 一般情况下不会缩容，缩容的代价比较大。缩容是一种以时间换空间的说法，拷贝源数据，释放原有空间
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

// test access
void Test_access() {
	string s1("hello world");
	s1.at(0) = 'i';
	//at和[]的功能几乎一样，但对于越界的处理不同，at越界时是抛异常，[]越界时是assert暴力断言
	//[]的可读性比较强
	cout << s1 << endl;
	cout << s1.front() << endl;
	string s2;
	//string s2("");	//两种方式都会被暴力断言
	//cout << s2.front() << endl;	//空串调用时会被暴力断言
	cout << s2.back() << endl;	//空串调用时会被暴力断言
}

//Test_insert_erase()
//按照文档中的重载接口说明练一练，insert和erase要谨慎使用，插入/删除时数据的挪动，效率较低
//中间和头部位置的插入和删除，效率比较低
void Test_insert_erase() {
	//insert
	string s1("hello world");
	s1.assign("hello Linux");
	cout << s1 << endl;


	//erase
}

//test_replace
//replace 的效率同样也比较低
void Test_replace() {
	string s1("hello world hello Linux");
	s1.replace(6, 5, "xxxxxxxxxx");
	cout << s1 << endl;

	s1.replace(6, 23, "yyyy");
	cout << s1 << endl;
}
int main() {
	//Test_3_1();
	//Test_3_2();
	//Test_resize();
	//Test_access();
	//Test_insert_erase();
	Test_replace();

	return 0;
}