
#include "string_me.h"

void Test1() {
	m_string::string s1("hello world");
	cout << s1.c_str() << endl;

	//�޲ι���
	m_string::string s2;
	const m_string::string s3("hello Linux");
	/*for (int i = 0; i < s1.size(); ++i) {
		s1[i]++;
	}*/
	for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i] << "";
	}
	cout << endl;
	//������
	//m_string::string::const_iterator cit = s3.begin();
	auto cit = s3.begin();
	/*while (it != s3.end()) {
		cout << *it << "";
		++it;
	}*/
	//��Χfor�ײ� �ᱻ �滻�ɵ����� 
	//C++11���﷨֧�ַ�Χfor, ���Խ��Լ������ݽṹʵ�ֵ���������֧���˷�Χfor
	for (auto& e : s3) {	//�ײ���������while��һ����
		cout << e << "";
	}
	cout << endl;
	
}
int main() {

	Test1();
	return 0;
}