#include <iostream>
using namespace std;

namespace use_2 {
	class Car {
	public:
		// 1. final: һ�����λ�����麯������ʾ���麯�������ٱ���д
		virtual void Drive() final
		{ }
	};
	class Benz :public Car {
	public:
		// ������virtual���麯��������̳й����ĺ���Ҳ�����麯������
		// ����final �Ͳ�����д��
		void Drive(int i) { cout << "Benz-����" << endl; }
	};
}

namespace use_3 {
	class Car {
	public:
		// 1. final: һ�����λ�����麯������ʾ���麯�������ٱ���д
		virtual void Drive()	// final
		{}
	};
	class Benz :public Car {
	public:
		//override : ����������麯���Ƿ���д�˻���ĳ���麯�������û����д���뱨��
		void Drive() override  { 
			cout << "Benz-����" << endl; 
		}
	};
}


//int main() {
//
//	return 0;
//}