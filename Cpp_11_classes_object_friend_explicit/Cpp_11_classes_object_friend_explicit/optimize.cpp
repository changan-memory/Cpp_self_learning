#include <iostream>
using namespace std;

class A {
private:
	int _a;
public:
	A(int a = 0)
		:_a(a){
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a){
		cout << "A(const A & a)" << endl;
	}
	A& operator=(const A& a) {
		cout << " A& operator=(const A & a)" << endl;
		if (this != &a) {
			_a = a._a;
		}
		return *this;
	}
	~A() {
		cout << "~A()" << endl;
	}
};
//ֻҪ����const�����;Ͳ�һ��
//�����������Թ������أ�������ͬʱ����
void Func1(A aa) {

}
void Func2(const A& aa) {

}
A Func3() {
	A aa;
	return aa;	//��ֵ���أ�����ÿ������캯��
}
A& Func4() {
	static A aa;
	return aa;	//��ֵ���أ�����ÿ������캯��
}
void TestFunc() {
	//A a1;
	//Func1(a1);	//���ò���ȷ���������������Դ���
	//Func2(a1);

	Func3();
	Func4();
}

A Func5() {
	A aa;
	return aa;	//��ֵ���أ�����ÿ������캯�������ص�����ʱ�����Ŀ���
}
void Test2() {
	//A& ref_a = Func5();	//���ص�����ʱ��������ʱ�������г��ԣ���Ҫ�ó�����
	const A& ref_a = Func5();
}
//int main() {
//	//TestFunc();
//	Test2();
//
//	return 0;
//}