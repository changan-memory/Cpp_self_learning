#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
//using std::cout;
//using std::endl;
//using std::string;
//using std::vector;
//using std::list;
using namespace std;


//test operator[]
void Test_1() {
	string s0;
	string s1("hello world");	//�ײ���һ���ַ����飬��β��һ��\0
	cout << s1 << endl;

	//����string,ʹ��[]
	//[] ����ͨ�������ذ汾  ��  const����  ���ذ汾
	cout << s1.size() << endl;	// \0�����С��size�� 11,\0��һ����ʶ�ַ��������������ַ���������Ч�ַ�
	//size������Ĵ�СΪ 11,������ '\0',��˲�����ʵ�'\0'
	for (size_t i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < s1.size(); ++i) {
		s1[i] += 1;
		cout << s1[i] << " ";
	}

	char s3[] = "hello world";
	//��������
	s3[0]++;	//�ײ�: *(s3+0)
	s1[0]++;	//�ײ�: s1.operator[](&s1, 0)
}

//������������������ָ��һ���Ķ���
void Test_2() {
	string s1("hello world");	//�ײ���һ���ַ����飬��β��һ��\0
	string::iterator str_it = s1.begin();
	while (str_it != s1.end()) {
		cout << *str_it;
		++str_it;
	}
	cout << endl;
	
	//�������ĵײ������ָ�룬Ҳ�����Ǳ��ʵ��
	//��Χfor���auto
	//��Χfor �ײ�ᱻ�滻Ϊ��������ֻҪ֧�ֵ���������������֧�ַ�Χfor
	//for (char& ch : s1) {
	for (auto& ch : s1) {
		cout << ch;
	}
	cout << endl;

	//�����Ŀռ������[�±�]������
	//�������������������ķ��ʷ�ʽ
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(6);
	vector<int>::iterator vit = vec.begin();
	while (vit != vec.end()) {
		cout << *vit << " ";
		vit++;
	}
	cout << endl;
	//�κ�������֧�ֵ����������ҷ��ʷ�ʽ����
	list<int> ls;
	ls.push_back(20);
	ls.push_back(40);
	ls.push_back(60);
	list<int>::iterator lsit = ls.begin();
	while (lsit != ls.end()) {
		cout << *lsit << " ";
		lsit++;
	}
	cout << endl;
	//[]ֻ�����ڷ�������ṹ�������������������Է����κ�����,(��,��ϣ���)
	//���������������㷨�������
	std::reverse(vec.begin(), vec.end());
	std::reverse(ls.begin(), ls.end());
	for (auto& e : vec) {
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : ls) {
		cout << e << " ";
	}
	cout << endl;
	//std::sort(ls.begin(), ls.end());	//���ܶ������������
	std::sort(vec.begin(), vec.end());
	for (auto& e : vec) {
		cout << e << " ";
	}
	cout << endl;

}

// ���������
void Test_3() {
	string s1("hello world");

	//������ĵ��������ͣ�auto��������
	//string::reverse_iterator rit = s1.rbegin();
	auto rit = s1.rbegin();
	//��Χfor���ܵ��ű�����������Χforֻ��ʹ�����������
	while (rit != s1.rend()) {
		cout << (*rit) << " ";
		++rit;
	}
	cout << endl;
}

// const������Ҫ��const������
void Test_4(const string& str) {
	//string::reverse_iterator rit = str.rbegin();
	//string::const_reverse_iterator rit = str.rbegin();		//���������
	// it���ǳ�����(*it)���ǳ���
	auto it = str.cbegin();		//const ���������
	while (it != str.cend()) {
		cout << (*it) << "";
		++it;
	}
	cout << endl;

	//���ֵ�����
	// iterator		��ͨ������
	// const_iterator	const���� ������
	// 
	// reverse_itreator		���������
	// const_reverse_itreator		const���� ���������
}

//int main() {
//	//Test_1();
//	//Test_2();
//	//Test_3();
//	const string cstring("hello Linux");
//	Test_4(cstring);
//	return 0;
//}