#include <stdio.h>

//����
//�����ռ���

//ȫ��������
//�ֲ�������

#include "Stack.h"
#include "Queue.h"

#include <iostream>

//�ֲ���->ȫ����->  չ���������ռ��� �� ָ�����������ռ���

// 1.
int a = 1;
namespace bit {
	int a = 10;
	int rand = 100000;
}	//�����ռ����������ܼӷֺ�

using namespace bit;
// ::�������޶���
//ͨ���������޶��������� �ض������ռ��еı���
void Test1() {
	int a = 100;
	printf("%d\n", a);
	printf("%d\n", ::a);	//��:: ������ȫ���������µ�ͬ������
	printf("%d\n", bit::a);	//��  namespace:: �������ض������ռ��µı���
}
//2.�����ļ��У���ͬ���ֵ������ռ�ᱻ�ϲ�
void Test2() {
	using namespace test_space;
	printf("%d\n", x);
	printf("%d\n", y);
}

//3. �����ռ����Ƕ��
namespace N1
{
	int a;
	int b;
	int Add(int left, int right) {
		return left + right;
	}
	namespace N2
	{
		int c;
		int d;
		int Sub(int left, int right) {
			return left - right;
		}
	}
}

//3. C���Ժ�C++�ı�׼�� �������ռ�
void Test3() {
	//��һ�ֽ������ using namespace std;
	using namespace std; //չ��ͷ�ļ�
						//ֱ��չ�����з��գ������Լ�����ı������ͱ�׼���е��ظ����ͻᱨ��
						//��Ŀ�н��鲻Ҫչ���� �ճ���ϰ������ô��
						//��Ŀ�н��� ָ�����ʣ���Ҫ����չ�������ռ�
	cout << "hello world" << endl;		

	//�ڶ��ֽ������  ʹ�� ::  �������޶���
	std::cout << "hello world" << std::endl;

	//�����ֽ������  �ѳ��õĴ������ռ���չ��
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "hello world" << endl;
}
//4. C++����������
void Test4() {
	using std::cout;
	using std::endl;
	int x = 100;
	// << �����������
	// cout �����Զ�ʶ������
	cout << "hello world" << x << '\n' << endl;

	// >> ����ȡ�����
	int y = 1000;
	std::cin >> x >> y;
	cout << x << " " << y << endl;

	//��ĳЩ��������Ҫ��ĵط��� printf/scanf �� cout/cin ����Ҫ��һ����(C�����������Ҫ����һ���)
}
int main() {
	Test1();
	//Test2();
	//Test3();
	//Test4();
	return 0;
}


