
#include "string_me.h"

void Test1() {
	m_string::string s1("hello world");
	cout << s1.c_str() << endl;

	//无参构造
	m_string::string s2;
}
int main() {

	Test1();
	return 0;
}