#include <iostream>
#include <string>
using namespace std;

//C strxxx 系列库函数
//Cpp string 类 
// basic use
void Test_use_construct() {
	/*string s1;
	std::string s2(s1);
	std::string name("yuxiang qin");
	name = "qin yuxiang";
	cout << name << endl;*/

	// string 的构造
	string s1;	//默认构造  string(); //初始化s1的长度为0
	string s2("zhangsan");	// string (const char* s)
	string s3("hello world");
	string s4(10, 'p');		// string (const char* s, size_t n)
	string s5(s2);	//string (const string& str);	//拷贝构造
	string s6(s3, 6, 5);	// string (const string& str, size_t pos, size_t len = npos)
	string s7(s3, 6);	//缺省参数值是 -1 size_t = -1 ,是整形的最大值，会拷贝后面所有的字符串

	cout << s1 << endl << s2 << endl;
	cout << s3 << endl << s4 << endl;
	cout << s5 << endl;
	cout << s6 << " --- " << s7 << endl;
	


	string url("https://cplusplus.com/reference/string/string/string/");
	string sub1(url, 0, 5);		//用该构造函数切分网站
	string sub2(url, 8, 13);
	string sub3(url, 22);
	cout << sub1 << endl;
	cout << sub2 << endl;
	cout << sub3 << endl;

	// string 的=重载
	s3 = s1;				//string& operator= (const string& str);		//用string对象初始化
	s2 = "I LOVE YOU";		//string& operator= (const char* s);	//用C风格字符串初始化
	s4 = "X";				//string& operator= (char c);		//用一个字符来初始化
}
//class string {
//operator+=(char ch);
//operator+=(const char* str);
//private:
//	char* _str;
//	size_t _size;
//	size_t capacity;
//};
void Test_use_2() {
	//增
	string s1("hello world");

	//其实string不喜欢用 push_back 和 append
	//尾插一个字符，push_back只支持尾插一个字符
	s1.push_back('  ');
	//尾插一个字符串，append有多个重载
	s1.append("world");
	
	//string更喜欢用 += 和 + 
	s1 += ' ';
	s1 += "world";
	cout << s1 << endl;

	// 要求把x转换为string对象
	size_t x = 0;
	cin >> x;
	string xstr;
	while (x) {
		size_t val = x % 10;
		xstr += ('0' + val);
		x /= 10;
	}
	cout << xstr << endl;
	//逆置
	//利用迭代器逆置
	std::reverse(xstr.begin(), xstr.end());
	cout << xstr << endl;

}
void capacityDemo() {
	string str = "Hello";
	cout << str.size() << endl;     // 5
	cout << str.capacity() << endl; // 15（VS2022实测值）

	str.reserve(50);
	cout << str.capacity() << endl; // 63

	str.resize(3);
	cout << str << endl;            // "Hel"

	str.resize(10, 'x');
	cout << str << endl;            // "Helxxxxxxx"
	str.clear();
	cout << "clear后的size为: " << str.size() << endl;
	cout << str << endl;            // "Helxxxxxxx"
}
//int main() {
//	capacityDemo();
//	//Test_use_construct();
//	//Test_use_2();
//	return 0;
//}