#if 0

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Stu {

public:
	Stu(int age) {
		this->_age = age;
	}
	Stu& add_age(Stu s) {	//�������ֵ����������, ����ʽ����ʱ, ����ջ�������µĿռ�,��� *this  
		this->_age += s._age;
		return *this;
	}
	int _age;
};

void test_1() {
	Stu s1(100);
	cout << s1._age << endl;

}
int main() {


	//test_1();
	Stu s1(10);
	Stu s2(10);
	//����Ա�����ķ���ֵΪ *this ʱ, ����ʵ����ʽ����
	s2.add_age(s1).add_age(s1).add_age(s1).add_age(s1);
	cout << s2._age << endl; // 50(&)   20 
	return 0;
}

#endif 