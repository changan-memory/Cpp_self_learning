#include <iostream>
using namespace std;

// C++�У����������� ռλ���������ô��ຯ��ʽ������� ռλ���� ��ֵ
//����ռλ���� ��ռλ����Ҳ������Ĭ�ϲ���
void func(int a, int = 10) {
	cout << "this is func" << endl;
}

int main() {

	func(10, 10); //ռλ���������

	system("pause");

	return 0;
}