#include <iostream>
using namespace std;
class A{
private:
	static int k;
	int h;
public:
	//�����ܵ������޶���������
	class B {	// B��������A����Ԫ  �ڲ������ⲿ�����Ԫ
	public:
		void foo(const A& a){
			cout << k << endl; 
			cout << a.h << endl;//OK
		}
	};
};
int A::k = 1;


//int main() {
//	cout << sizeof(A) << endl;	//��СΪ4����ΪA��û��B�Ķ���
//	A aa1;
//	A::B bb1;	//����B����Ҫ ͨ��A��ȥ����
//	return 0;
//}