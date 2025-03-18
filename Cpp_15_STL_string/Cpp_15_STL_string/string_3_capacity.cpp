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
	cout << s1.capacity() << endl;
}
void Test_3_2() {
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	for (int i = 0; i < 100; i++) {
		s.push_back('c');
		if (sz != s.capacity()) {
			sz = s.capacity();
			cout << " capacity changed" << endl;
		}
	}
}
int main() {
	Test_3_1();


	return 0;
}