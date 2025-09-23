#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <string>
using namespace std;

struct Point {
	//explicit Point(int x, int y)
	Point(int x, int y)
		:_x(x)
		, _y(y)
	{
		cout << "Point(int x, int y)" << endl;
	}
	int _x;
	int _y;
};
// ����1 ͳһ���б��ʼ�� {}
// �����ճ����壬��Ҫȥ��=�����������Լ�Ҫ�ܿ����б��ʼ��������﷨
namespace use_1{
	// һ�нԿ���{}��ʼ�������ҿ��Բ�д ��ֵ�� =
	void test1() {
		int x = 1;	// ��ֵ
		int y(2);	// C++����������Ҳ�й��캯��
		int z = { 3 };	// �б��ʼ��
		int w{ 4 };		// ��д ��ֵ��= ���б��ʼ��

		int a1[] = {1, 2, 3};
		int a2[] {1, 2, 3};		// C++11
		// ����д�� ���ʶ�����ù��캯��
		Point p0(0, 0);
		Point p1 = { 1, 1 };
		Point p2{2, 2};
	}
	void test2() {
		// C++ 11 ���õ�֧��������д��
		int* p1 = new int[3] {1, 2, 3};
		int* p2 = new int[3]{ 2, 4, 6 };

		Point ptr0(0, 0);	// ���ù��캯��*1
		// ֮ǰ�ǵ������Ĺ��캯��֧����ʽ����ת��

		// �����﷨�ı�����  ��������캯������ʽ����ת��
		Point ptr1 = { 1, 1 };	 //���ù��캯��*1
		Point* ptr2 = new Point[2]{Point(1, 2), Point(3, 4)};	 //���ù��캯��*2
		Point* ptr3 = new Point[2]{ptr0, ptr1};		// ����û�е��ù��캯��
		// �������������﷨�ı�����  ֧���� ��������캯������ʽ����ת��
		Point* ptr4 = new Point[2]{ {2, 2}, {3, 3} };	 //���ù��캯�� *2

		Point* ptr5 = new Point[1]{ {1, 1} };	// new ���ù��캯�� * 1
		// {1, 8}������һ��Point����ʱ������ʱ������г��ԣ���Ҫ�ó�����
		//Point& rp0 = { 1, 8 };
		const Point& rp = { 1, 8 };
	}
	// �����ճ����壬��Ҫȥ��=�����������Լ�Ҫ�ܿ����б��ʼ��������﷨
}

// ����2  std::initializer_list 
namespace use_2 {
	void test1() {
		vector<int> v = { 1, 2, 3 };	// ������﷨���� {}�б��ʼ��   ���õ��ǹ��캯��
		Point p = { 1, 2 };			// ������Ĺ��캯��֧����ʽ����ת��
		// �������� �ǲ�ͬ���﷨  vector�����ں���Ӷ��ֵ����Pointֻ������������

		//initializer_list �����͵Ķ����ɱ������� ��ʼ���б����� ���Զ����죬
		// ��ʼ���б��������ô������������Ķ��ŷָ��� �������б� �洢���ڴ�ĳ�����
		auto il = { 1, 2, 5 };
		cout << typeid(il).name() << endl;
		cout << sizeof(il) << endl;

		/*const int* arr = { 1, 2, 3 };
		int* arr = { 1, 2, 3 };*/
		map<string, string> dict = { {"sort", "����"}, {"insert", "����"}};
	}
}

namespace use_3 {
	// auto
	void test_auto() {
		int i = 10;
		auto p = &i;
		auto pf = malloc;	// ����ָ������ Ҳ���� �Զ�ʶ��
		cout << typeid(p).name() << endl;
		cout << typeid(pf).name() << endl;
		map<string, string> dict = { {"sort", "����"}, {"insert", "����"} };
		//map<string, string>::iterator it = dict.begin();
		auto it = dict.begin();
	}

	// decltype

	// ����һ�����ڵĳ�Ա�����Ǹ�����ָ�룬���ǲ���д����ָ�����������������
	class A {
	private:
		decltype(malloc) pf_malloc;
	};
	// ������
	template<class Func>
	class B {
	private:
		Func _pf;	// ���Դ��뺯��ָ��
	};
	// �ؼ���decltype����������������Ϊ���ʽָ��������
	void test_decltype() {
		auto pf = malloc;	// ����ָ������ Ҳ���� �Զ�ʶ��
		cout << typeid(pf).name() << endl;
		// ��ζ���һ����pfͬ���ͱ���
		//typeid(pf).name _ptr;	// typeid().name ֻ�ܻ�ȡ�����������ͣ�������������/�������
		
		// auto �����Ǳ����ʼ��
		auto pf1 = pf;	//
		// decltype		// decltype ������ֻ�����������г�ʼ��
		// decltype �����Ƶ������������� ���ٶ��������������Ϊģ��ʵ��
		decltype(pf) _ptr = malloc;
		decltype(malloc) _ptr2;		// ����������һ������������ʼ��
		// typeid().name   �Ƶ�����������һ���ַ�����ֻ�ܿ�������ʹ��
		// decltype �����Ƶ������������� ���ٶ��������������Ϊģ��ʵ��
		
		// ʵ���� B ��  // decltype ��Ϊģ��ʵ��ʱ�ܺ���
		B<decltype(pf)> b1;

		// decltype ������ʽ������
		const int x = 1;
		double y = 2.2;
		decltype(x * y) ret; // ret��������double
		decltype(&x) p; // p��������int*
		cout << typeid(ret).name() << endl;
		cout << typeid(p).name() << endl;
	}

	// nullptr ���
	void Func(int) {
		cout << "Func(int)" << endl;
	}
	void Func(int*){
		cout << "Func(int*)" << endl;
	}
	void test_nullptr() {
		/*
		#ifndef NULL
		#ifdef __cplusplus
		#define NULL 0
		#else
		#define NULL ((void *)0)
		#endif
		#endif
		*/
		int* p = NULL;	// NULL �Ǻ꣬Ԥ����׶� �ᱻ�滻��0�� ������ȫ  int* p = 0;
		Func(NULL);		// Func(0)  ��������int* �汾��ȴ������int�汾
	}
	// ��Χforѭ�����ײ��� ������ 
}

namespace new_container {
	// std::array
	void test_array() {
		int a1[10];
		std::array<int, 10> a2;
		cout << sizeof(a1) << endl;
		cout << sizeof(a2) << endl;
		//a1[15];		//  ���� �� ָ��Ľ�����   ��ЩԽ�����ԭ�������޷����
		//a2[15];		//  ���� �� operatpr[]�������ã��ڲ������Խ��  Խ���д���ܼ�����

		// vector Ҳ������� array�Ĺ��ܣ����ܳ�ʼ�����Ե�arrat�ܼ���
		vector<int> a3(10, 3);
	}
	// std::forward_list
	// �ײ�ʵ����  ������
}
//int main() {
//	//use_1::test1();
//	//use_1::test2();
//	use_2::test1();
//	//use_3::test_auto();
//	//use_3::test_decltype();
//	//use_3::test_nullptr();
//	//new_container::test_array();
//	return 0;
//}