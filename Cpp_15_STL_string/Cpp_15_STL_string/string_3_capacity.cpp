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