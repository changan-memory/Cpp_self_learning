#include <iostream>
#include <string>
using namespace std;

//C strxxx ϵ�п⺯��
//Cpp string �� 
// basic use
void Test_use_construct() {
	/*string s1;
	std::string s2(s1);
	std::string name("yuxiang qin");
	name = "qin yuxiang";
	cout << name << endl;*/

	// string �Ĺ���
	string s1;	//Ĭ�Ϲ���  string();
	string s2("zhangsan");	// string (const char* s)
	string s3("hello world");
	string s4(10, 'p');		// string (const char* s, size_t n)
	string s5(s2);	//string (const string& str);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	string s6(s3, 6, 5);	// string (const string& str, size_t pos, size_t len = npos)
	string s7(s3, 6);	//ȱʡ����ֵ�� -1 size_t = -1 ,�����ε����ֵ
	cout << s6 << " " << s7 << endl;

	string url("https://cplusplus.com/reference/string/string/string/");
	string sub1(url, 0, 5);
	string sub2(url, 8, 13);
	string sub3(url, 22);
	cout << sub1 << endl;
	cout << sub2 << endl;
	cout << sub3 << endl;

	// string ��=����
	s3 = s1;	//string& operator= (const string& str);
	s2 = "I LOVE YOU";		//string& operator= (const char* s);
	s4 = "X";				//string& operator= (char c);
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
	//��
	string s1("hello world");
	//β��һ���ַ�
	s1.push_back('  ');
	//β��һ���ַ���
	s1.append("world");

	s1 += ' ';
	s1 += "world";
	cout << s1 << endl;

	// Ҫ���xת��Ϊstring����
	size_t x = 0;
	cin >> x;
	string xstr;
	while (x) {
		size_t val = x % 10;
		xstr += ('0' + val);
		x /= 10;
	}
	cout << xstr << endl;
}
int main() {
	//Test_use_construct();
	Test_use_2();
	return 0;
}