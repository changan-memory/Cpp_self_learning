
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
void TestString_2() {
	m_string::string s1("hello world");
	cout << s1.c_str() << endl;
	s1.push_back(' ');
	s1.push_back('#');
	s1.append(" hello Linux");
	cout << s1.c_str() << endl;

	m_string::string s2("hello world");
	cout << s2.c_str() << endl;
	s2 += ' ';
	s2 += '#';
	s2 += " hello Linux";
	cout << s2.c_str() << endl;
}
void TestInsert() {
	m_string::string s1("hello world");
	cout << s1.c_str() << endl;
	s1.insert(0, 3, '#');
	cout << s1.c_str() << endl;

	s1.insert(0, "123456");
	cout << s1.c_str() << endl;
}
void TestErase() {
	m_string::string s1("hello world");
	cout << s1.c_str() << endl;
	s1.erase(2, 2);
	cout << s1.c_str() << endl;
	
	m_string::string s2("hello world");
	s2.erase(3, 60);
	cout << s2.c_str() << endl;

	m_string::string s3("hello world");
	s3.erase(2);
	cout << s3.c_str() << endl;
}
void TestFind() {
	m_string::string url = "https://cplusplus.com/reference/string/string/";
	//���� Э�� ����  ��Դ��
	
	size_t pos1 = url.find("://");
	if (pos1 != m_string::string::npos) {
		m_string::string protocol = url.substr(0, pos1);	//���±�0��ʼ������ָ�����ȵ��ַ���
		cout << protocol.c_str() << endl;
	}

	size_t pos2 = url.find("/", pos1 + 3);
	if (pos2 != string::npos) {
		m_string::string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
		cout << domain.c_str() << endl;
		m_string::string uri = url.substr(pos2 + 1);
		cout << uri.c_str() << endl;
	}
	cout << url.c_str() << endl;
}
void TestResize() {
	//std::string s("hello world");
	m_string::string s("hello world");
	s.resize(8,'x');
	cout << s.c_str() << endl;
	cout << s << endl;
	s.resize(13, 'y');
	cout << s.c_str() << endl;
	cout << s << endl;
	s.resize(20, 'z');
	cout << s.c_str() << endl;
	cout << s << endl;

	// c���ַ����飬��\0Ϊ��ֹ�㳤��
	// string����\0, ��sizeΪ��ֹ�㳤��

	m_string::string s2("hello world");
	s2 += '\0';
	s2 += "!!!!!!!!!";
	//�ó����� cout<<s2 �� cout<<s2.c_str ��������
	cout << s2 << endl;		//���ȫ������
	cout << s2.c_str() << endl;		//����\0��ֹͣ��  cstringϵ�еĿ⺯��
	cout << endl;

	//s2�м���\0
	m_string::string copy(s2);	//����������ʹ��strcpy,����\0��ֹ
	cout << s2 << endl;
	cout << copy << endl;

	s2 += "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	cout << s2 << endl;

}

void Test_cin() {
	//char buff[128];
	//for (size_t i = 0; i < 5; ++i) {
	//	cin >> buff[i];		
	//	//cin��ȡ����ʱ���Կո�ͻ��н��зָ���ֵ�����Ĭ�϶�ȡ�����ո�ͻ���
	//}
	m_string::string s;
	/*for (int i = 0; i < 3; ++i) {
		cin >> s;
		cout << s << endl;
	}*/
	cin >> s;
	cout << s << endl;
}
void TestCompare() {

}
int main() {

	//Test1();
	//TestString_2();
	//TestInsert();
	//TestErase();
	//TestFind();
	//TestResize();
	Test_cin();
	return 0;
}