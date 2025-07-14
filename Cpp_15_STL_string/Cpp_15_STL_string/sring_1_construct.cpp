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
	string s1;	//Ĭ�Ϲ���  string(); //��ʼ��s1�ĳ���Ϊ0
	string s2("zhangsan");	// string (const char* s)
	string s3("hello world");
	string s4(10, 'p');		// string (const char* s, size_t n)
	string s5(s2);	//string (const string& str);	//��������
	string s6(s3, 6, 5);	// string (const string& str, size_t pos, size_t len = npos)
	string s7(s3, 6);	//ȱʡ����ֵ�� -1 size_t = -1 ,�����ε����ֵ���´���������е��ַ���

	cout << s1 << endl << s2 << endl;
	cout << s3 << endl << s4 << endl;
	cout << s5 << endl;
	cout << s6 << " --- " << s7 << endl;
	


	string url("https://cplusplus.com/reference/string/string/string/");
	string sub1(url, 0, 5);		//�øù��캯���з���վ
	string sub2(url, 8, 13);
	string sub3(url, 22);
	cout << sub1 << endl;
	cout << sub2 << endl;
	cout << sub3 << endl;

	// string ��=����
	s3 = s1;				//string& operator= (const string& str);		//��string�����ʼ��
	s2 = "I LOVE YOU";		//string& operator= (const char* s);	//��C����ַ�����ʼ��
	s4 = "X";				//string& operator= (char c);		//��һ���ַ�����ʼ��
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

	//��ʵstring��ϲ���� push_back �� append
	//β��һ���ַ���push_backֻ֧��β��һ���ַ�
	s1.push_back('  ');
	//β��һ���ַ�����append�ж������
	s1.append("world");
	
	//string��ϲ���� += �� + 
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
	//����
	//���õ���������
	std::reverse(xstr.begin(), xstr.end());
	cout << xstr << endl;

}
void capacityDemo() {
	string str = "Hello";
	cout << str.size() << endl;     // 5
	cout << str.capacity() << endl; // 15��VS2022ʵ��ֵ��

	str.reserve(50);
	cout << str.capacity() << endl; // 63

	str.resize(3);
	cout << str << endl;            // "Hel"

	str.resize(10, 'x');
	cout << str << endl;            // "Helxxxxxxx"
	str.clear();
	cout << "clear���sizeΪ: " << str.size() << endl;
	cout << str << endl;            // "Helxxxxxxx"
}
//int main() {
//	capacityDemo();
//	//Test_use_construct();
//	//Test_use_2();
//	return 0;
//}