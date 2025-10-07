#include <iostream>
#include <string>

using namespace std;

//// 1. �ֶ� new �� delete ���� �쳣 ʱ���ֵ�����
//int div() {
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//
//	return a / b;
//}
//
//void Func() {
//	// 1�����p1����new ���쳣����Σ�
//	// 2�����p2����new ���쳣����Σ�
//	// 3�����div���������ֻ����쳣����Σ�
//	int* p1 = new int;
//	int* p2 = new int;
//
//	div();
//
//	delete p1;
//	delete p2;
//}
//
//int main() {
//	try {
//		Func();
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}


int div() {
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("��0����");

	return a / b;
}
// Ϊ�˽���������⣬C++���������ָ��
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{
	}
	~SmartPtr() {
		cout << "delete: " << _ptr << endl;
		delete _ptr;
	}
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}
private:
	T* _ptr;
};
void f()
{
	// RAII
	// ��Դ������������������������ڣ���Դ��Ч�������������ڵ��ˣ��ͷ���Դ
	// 1��RAII�ܿ���Դ�ͷ�
	// 2����ָ��һ�� ֧�ַ�����Դ
	// 3. ָ��Ŀ�������
	SmartPtr<pair<string, string>> sp1(new pair<string, string>("1111", "22222"));
	//div();
	SmartPtr<pair<string, string>> sp2(new pair<string, string>);
	SmartPtr<pair<string, string>> sp3(new pair<string, string>);
	SmartPtr<string> sp4(new string("xxxxx"));

	cout << *sp4 << endl;
	cout << sp1->first << endl;
	cout << sp1->second << endl;
	div();

	//delete p1;
	//cout << "delete:" << p1 << endl;
}

//int main() {
//	try {
//		f();
//	}
//	catch (const exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//// ����ָ����鷳�ĳ���
//int main() {
//	SmartPtr<string> sp1(new string("xxxxx"));
//	SmartPtr<string> sp2(new string("yyyyy"));
//	
//	// Ĭ�����ɵ� ǳ������ֵ
//	sp1 = sp2;
//	return 0;
//}

 //Ϊʲô������Ƴ����
 //1. ֻ��ָ��ģ�����ԭ��ָ�����Ϊ��ԭ��ָ����е��� ֵ����
 //2. ������ģ��ʵ�֣����Ҫ����������Զ������͵ģ��ڲ�ȷ�����͵�����£��޷�ʵ�� ���