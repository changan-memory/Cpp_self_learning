#include <iostream>
using namespace std;

//���һ������ͳ�Ƶ�ǰ����ʹ�õ�ĳ�������ж��ٸ�
int _scount = 0;
class A {
public:
	A() { ++_scount; }
	A(const A& t) { ++_scount; }
	~A() { --_scount; }
};

A aa0;

namespace test1 {
	A Func(A aa1) {
		cout << __LINE__ << " " << _scount << endl;
		return aa1;
	}
	int main() {
		cout << __LINE__ << " " << _scount << endl;	//1��ȫ�ֶ���
		A aa1;
		static A aa2;
		Func(aa1);
		cout << __LINE__ << ": " << _scount << endl;	//���Func�ĺ���ջ֡��û����Ļ����˴���5��

		return 0;
	}
}
void Func() {
	static A aa2;	//�ֲ���̬����ֻ�ᴴ��һ�Σ����ں���ջ֡�ڣ��ھ�̬��
	cout << __LINE__ << ": " << _scount << endl;	//3

	//ȫ�ֱ��������ƣ��κεط�����������ı䣬����ȫ
	//_scount++;
}

//int main() {
//	cout << __LINE__ << ": " << _scount << endl;	// �� 1 ���˴���û����Func������static ����û����
//	A aa1;
//	Func();	//3
//	Func(); //3
//	return 0;
//}