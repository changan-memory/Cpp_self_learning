//#include <iostream>
//using namespace std;
//
//class AbstractDrinking {
//public:
//	//��ˮ
//	virtual void Boil() = 0;
//	//����
//	virtual void Brew() = 0;
//	//���뱭��
//	virtual void PourCup() = 0;
//	//���븨��
//	virtual void AddSth() = 0;
//	//����
//	void make() {
//		this->Boil();
//		this->Brew();
//		this->PourCup();
//		this->AddSth();
//	}
//};
//
//class Coffee :public AbstractDrinking {
//	virtual void Boil() {
//		cout << "��ũ��ɽȪˮ" << endl;
//	}
//	virtual void Brew() {
//		cout << "�忧�ȷ�" << endl;
//	}
//	virtual void PourCup() {
//		cout << "���뿧�ȱ�" << endl;
//	}
//	virtual void AddSth() {
//		cout << "����ţ��" << endl;
//	}
//};
//
//class Tea :public AbstractDrinking {
//	virtual void Boil() {
//		cout << "���Ȫˮ" << endl;
//	}
//	virtual void Brew() {
//		cout << "���Ҷ" << endl;
//	}
//	virtual void PourCup() {
//		cout << "����豭" << endl;
//	}
//	virtual void AddSth() {
//		cout << "�������" << endl;
//	}
//};
//
//void dowork(AbstractDrinking* abs) {
//	abs->make();
//	delete abs;
//	abs = nullptr;
//}
//
//void test1() {
//	dowork(new Coffee);
//	cout << "------------------" << endl;
//	dowork(new Tea);
//}
//
//int main() {
//
//	test1();
//
//	return 0;
//}