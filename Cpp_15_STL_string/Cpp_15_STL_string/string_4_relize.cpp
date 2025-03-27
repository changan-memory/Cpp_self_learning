
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
int main() {

	Test1();
	return 0;
}