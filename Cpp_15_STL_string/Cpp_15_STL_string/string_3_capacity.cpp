#define _CRT_SECURE_NO_WARNINGS 1
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

//capacity��ؽӿ�
// string �ĵײ���һ��������˳���Ľṹ
void Test_3_1() {
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;	//�鿴��ǰ�ַ������ݻ���capacity�Ľ��һ���size��һ��
	//���������� ��  capacity ���ݵĽ��ȡ���ڱ�������ʵ��

	cout << s1.max_size() << endl;	//�����󳤶ȣ��ڲ�ͬ��ƽ̨�½����һ����ʵ��ʹ��ʱ��������
}

void Test_3_2() {
	string s;
	// reserve ��ı� string ����� capacity, 
	// Ԥ��֪�����ַ����ĳ���ʱ������Ԥ�ȿ��ٿռ䣬���ٲ���ʱ�����ݿ���
	s.reserve(100);		//����100һ����100Ҫ���󣬵�����ʵ��ȡ����ƽ̨�ͱ�����
	size_t sz = s.capacity();
	cout << sz << endl;		//reserveһ�㲻�������ݣ�����ȡ���ڱ�������ʵ��
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

	s1.reserve(100);	//�����ĸı�ռ��С,����һ����100
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	//s1.resize(100);	//���ռ�+��ֵ���г�ʼ����Ĭ����'\0'
	s1.resize(120, 'x');	//���ռ�+��ֵ���г�ʼ����Ĭ����'\0'
	// һ������²������ݣ����ݵĴ��۱Ƚϴ�������һ����ʱ�任�ռ��˵��������Դ���ݣ��ͷ�ԭ�пռ�
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

// test access
void Test_access() {
	string s1("hello world");
	s1.at(0) = 'i';
	//at��[]�Ĺ��ܼ���һ����������Խ��Ĵ���ͬ��atԽ��ʱ�����쳣��[]Խ��ʱ��assert��������
	//[]�Ŀɶ��ԱȽ�ǿ
	cout << s1 << endl;
	cout << s1.front() << endl;
	string s2;
	//string s2("");	//���ַ�ʽ���ᱻ��������
	//cout << s2.front() << endl;	//�մ�����ʱ�ᱻ��������
	cout << s2.back() << endl;	//�մ�����ʱ�ᱻ��������
}

//Test_insert_erase()
//�����ĵ��е����ؽӿ�˵����һ����insert��eraseҪ����ʹ�ã�����/ɾ��ʱ���ݵ�Ų����Ч�ʽϵ�
//�м��ͷ��λ�õĲ����ɾ����Ч�ʱȽϵ�
void Test_insert_erase() {
	//insert
	string s1("hello world");
	s1.assign("hello Linux");
	cout << s1 << endl;


	//erase
}

//test_replace
//replace ��Ч��ͬ��Ҳ�Ƚϵ�
void Test_replace() {
	string s1("hello world hello Linux");
	s1.replace(6, 5, "xxxxxxxxxx");
	cout << s1 << endl;

	s1.replace(6, 23, "yyyy");
	cout << s1 << endl;		//�ײ�ǳ���ʱ

	string s2("hello world hello Linux");	//�����еĿո��滻��%
	//������replace��������Ϊ������ķ���
	string s3;
	for (auto& ch : s2) {
		if (ch != ' ')
			s3 += ch;
		else
			s3 += '%';
	}
	s2 = s3;
	cout << s2 << endl;		//����s2�����<<����
	cout << s2.c_str() << endl;		//����const char*
	// c_str ��Ϊ�˸��õ���C���ԵĽӿ����
	string filename = "test.cpp";
	filename += ".zip";
	FILE* fout = fopen(filename.c_str(), "r");
}
void Test_find() {
	string url = "https://cplusplus.com/reference/string/string/";
	//���� Э�� ����  ��Դ��
	string protocol;
	size_t pos1 = url.find("://");
	if (pos1 != string::npos) {
		protocol += url.substr(0, pos1);	//���±�0��ʼ������ָ�����ȵ��ַ���
	}
	string domain;
	string uri;
	size_t pos2 = url.find("/", pos1 + 3);
	if (pos2 != string::npos) {
		domain += url.substr(pos1 + 3, pos2 - (pos1 + 3));
		uri = url.substr(pos2+1);
	}
	cout << url << endl;
	cout << protocol << endl << domain << endl << uri << endl;

}
void Test_rfind() {
	//�����ļ��ĺ�׺ʱ������rfind   �Ӻ���ǰ��
}
//�ַ���ת���ͱ���
void Test_convert() {
	/*string str1 = to_string(1234);
	string str2 = to_string(12.34);
	string str3 = to_string(1234);*/

	//������У��ַ��洢����ascii��
	char str1[] = "abcd";
	char str2[2];
	str2[0] = 98;
	cout << str2[0] << endl;

	char str3[] = "���";
	cout << sizeof(str3) << endl;
	cout << str3 << endl;

	str3[1]--;
	cout << sizeof(str3) << endl;
	cout << str3 << endl;
}

//int main() {
//	//Test_3_1();
//	//Test_3_2();
//	//Test_resize();
//	//Test_access();
//	//Test_insert_erase();
//	//Test_replace();
//	//Test_find();
//	Test_convert();
//	return 0;
//}

////#include <cstddef>
//#include <iostream>
//using namespace std;
//
//int main() {
//	string str;
//	//cin >> str;	//cin��scanf��ȡ����ʱ�������ո���߻��У���������������������ַ����еĿո�
//	getline(cin, str);	//Ĭ���������з�������Ҳ�����Լ�����
//	size_t pos = str.rfind(' ');
//	if (pos != string::npos) {
//		cout << str.size() - (pos + 1) << endl;
//	}
//	else {
//		cout << str.size() << endl;
//	}
//	return 0;
//}
