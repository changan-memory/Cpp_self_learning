#include <iostream>
using namespace std;

class A {
private:
	int _a;
public:
	//���캯���������Թ������ʼ�����󣬶��ڽ��յ��������Ĺ��캯��������������ת��������
	// ��explicit���ι��캯���������ֹ���캯������ʽת����
	//explicit A(int a)	//���� explicit �ؼ��ֺ󣬾Ͳ��������� A aa2 = 2 ����ʽ����ת����
	//	: _a(a)
	//{
	//	cout << "A(int a)" << endl;
	//}
	A(int a)
		: _a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa) 
		: _a(aa._a)
	{
		cout << " A(const A& aa) " << endl;
	}
};
int main() {
	A aa1(1);	//���캯��
	A aa2 = 2;		//��ʽ����ת��������ת�����Զ�������
	// 2����һ��A����ʱ������ʱ�����ٿ�������aa2  -> ������������ι����Ż��� ��2ֱ�ӹ���
	// A temp = 2  //2�ȵ���A�Ĺ��캯��������ʱ����temp  ->  A aa2 = temp  //temp���ù��캯��ȥ��������

    //error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��A &��
	//A& refa = 2;
	const A& refa = 2;
	return 0;
}