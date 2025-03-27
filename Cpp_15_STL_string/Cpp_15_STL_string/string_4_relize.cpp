
#include "string_me.h"

void Test1() {
	m_string::string s1("hello world");
	cout << s1.c_str() << endl;

	//无参构造
	m_string::string s2;
	const m_string::string s3("hello Linux");
	/*for (int i = 0; i < s1.size(); ++i) {
		s1[i]++;
	}*/
	for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i] << "";
	}
	cout << endl;
	//迭代器
	//m_string::string::const_iterator cit = s3.begin();
	auto cit = s3.begin();
	/*while (it != s3.end()) {
		cout << *it << "";
		++it;
	}*/
	//范围for底层 会被 替换成迭代器 
	//C++11的语法支持范围for, 可以将自己的数据结构实现迭代器，就支持了范围for
	for (auto& e : s3) {	//底层汇编和上面的while是一样的
		cout << e << "";
	}
	cout << endl;
}
void TestString_2() {
	m_string::string s1("hello world");
	cout << s1.c_str() << endl;
	s1.push_back(' ');
	s1.push_back('#');
	s1.append(" hello Linux");
	cout << s1.c_str() << endl;

	m_string::string s2("hello world");
	cout << s2.c_str() << endl;
	s2 += ' ';
	s2 += '#';
	s2 += " hello Linux";
	cout << s2.c_str() << endl;
}
void TestInsert() {
	m_string::string s1("hello world");
	cout << s1.c_str() << endl;
	s1.insert(0, 3, '#');
	cout << s1.c_str() << endl;

	s1.insert(0, "123456");
	cout << s1.c_str() << endl;
}
void TestErase() {
	m_string::string s1("hello world");
	cout << s1.c_str() << endl;
	s1.erase(2, 2);
	cout << s1.c_str() << endl;
	
	m_string::string s2("hello world");
	s2.erase(3, 60);
	cout << s2.c_str() << endl;

	m_string::string s3("hello world");
	s3.erase(2);
	cout << s3.c_str() << endl;
}
void TestFind() {
	m_string::string url = "https://cplusplus.com/reference/string/string/";
	//分离 协议 域名  资源名
	
	size_t pos1 = url.find("://");
	if (pos1 != m_string::string::npos) {
		m_string::string protocol = url.substr(0, pos1);	//从下标0开始，查找指定长度的字符串
		cout << protocol.substr(0, pos1).c_str() << endl;
	}
	m_string::string domain;
	m_string::string uri;

	size_t pos2 = url.find("/", pos1 + 3);
	if (pos2 != string::npos) {
		domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
		uri = url.substr(pos2 + 1);
	}
	cout << url.c_str() << endl;
	cout  << endl << domain.c_str() << endl << uri.c_str() << endl;
}
int main() {

	//Test1();
	//TestString_2();
	//TestInsert();
	//TestErase();
	TestFind();
	return 0;
}