#include<iostream>
using namespace std;

class A {
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A(){
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
//����Ķ��������ڴ�
int main() {
	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
	// һ��Ҫ new/delete  malloc/free ƥ��ʹ��
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);

	free(p1);
	delete p2;
	cout << endl;
	A* p5 = (A*)malloc(sizeof(A) * 3);
	//�����˹��캯���ģ��ô���Ĳ�����ʼ��
	//û�г�ʼ���ģ�����Ĭ�Ϲ��캯��
	A* p6 = new A[4]{A(1), A(2), A(3)};	//��������������г�ʼ��

	free(p5);
	delete[] p6;
	return 0;
}
