#include <iostream>
#include <vector>
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
namespace use_1{
	// һ�нԿ���{}��ʼ�������ҿ��Բ�д ��ֵ��=
	void test1() {
		int x = 1;	// ��ֵ
		int y(2);	// C++����������Ҳ�й��캯��
		int z = { 3 };	// �б��ʼ��
		int w{ 4 };		// ��д ��ֵ��= ���б��ʼ��
		// ����д�� ���ʶ�����ù��캯��
		Point p0(0, 0);
		Point p1 = { 1, 1 };
		Point p2{2, 2};
	}
	void test2() {
		int* p1 = new int[3] {1, 2, 3};
		int* p2 = new int[3]{ 2, 4, 6 };

		Point ptr0(0, 0);	// ���ù��캯��*1
		// ֮ǰ�ǵ������Ĺ��캯��֧����ʽ����ת��

		// �����﷨�ı�����  ��������캯������ʽ����ת��
		Point ptr1 = { 1, 1 };	 //���ù��캯��*1
		Point* ptr2 = new Point[2]{Point(1, 2), Point(3, 4)};	 //���ù��캯��*2
		Point* ptr3 = new Point[2]{ptr0, ptr1};		// ����û�е��ù��캯��
		// �������������﷨�ı�����  ��������캯������ʽ����ת��
		Point* ptr4 = new Point[2]{ {2, 2}, {3, 3} };	 //���ù��캯��*2

		// {1, 8}������һ��Point����ʱ������ʱ������г��ԣ���Ҫ�ó�����
		//Point& rp0 = { 1, 8 };
		const Point& rp = { 1, 8 };
	}
	// �����ճ����壬��Ҫȥ��=�����������Լ�Ҫ�ܿ����б��ʼ��������﷨
}

// ����2  std::initializer_list ��������
namespace use_2 {
	void test1() {
		vector<int> v = { 1, 2, 3 };	// ������﷨���� {}�б��ʼ��
		Point p = { 1, 2 };	// vector�����ں����
		// �������� �ǲ�ͬ���﷨
	}
}
int main() {
	//use_1::test1();
	use_1::test2();
	return 0;
}