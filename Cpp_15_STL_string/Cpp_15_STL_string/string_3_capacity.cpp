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
int main() {
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	return 0;
}