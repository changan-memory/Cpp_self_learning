#include <iostream>
using namespace std;

const double PI = 3.14;

//���һ��Բ�࣬��Բ���ܳ�
class Circle {
	
public:
	//����
	int r;

	//��Ϊ
	//����Բ���ܳ�
	double calculate_ZC() {
		return 2 * PI * r;
	}

};

//int main() {
//	Circle c1;
//	c1.r = 10;
//
//	cout << "Բ���ܳ�Ϊ" << c1.calculate_ZC() << endl;
//	system("pause");
//	return 0;
//}