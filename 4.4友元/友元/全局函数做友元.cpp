
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Building {
	//ȫ�ֺ���  �� ��� ��Ԫ
	//���д������˼��  ����һ��ȫ�ֺ���Ϊ �������Ԫ 
	// �����Ԫ  ���Է��� ���˽������
	friend void Good_Gay(Building& B);
public:
	Building() {
		this->_bedroom = "����";
		this->_living_room = "����";
	}
public:
	string _living_room;

private:
	string _bedroom;
};

void Good_Gay(Building& B) {
	cout << "�û������ڷ��� �� " << B._living_room << endl;
	cout << "�û������ڷ��� �� " << B._bedroom << endl;
}


int main() {
	Building B;
	Good_Gay(B);

	return 0;
}



