//
//#include <iostream>
//#include <string>	//string��һ����
//using namespace std;
//
////�������ʹ�������
////��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
////�������ʹ������� ��Ϊ�˽������ָ�����ͷ�ʱ�޷����õ��������������
////���԰Ѹ����е���������дΪ������  
//
//
//
//
//class Animal {
//public:
//	Animal() {
//		cout << "Animal ���캯������" << endl;
//	}
//	virtual void speak() {
//		cout << "������˵��" << endl;
//	}
//
//	virtual ~Animal() {
//		cout << "Animal ������������" << endl;
//	}
//};
//
//class Cat :public Animal {
//public:
//	Cat(string name) {
//		cout << "Cat���캯������" << endl;
//		this->_name = new string(name);
//	}
//	virtual void speak() {
//		cout << *this->_name<<"Сè��˵��" << endl;
//	}
//	~Cat() {
//		if (this->_name != nullptr) {
//			cout << "Cat��������������" << endl;
//			delete this->_name;
//			this->_name = nullptr;
//		}
//			
//	}
//	string* _name;
//};
//
//void test1() {
//	Animal* ani = new Cat("Tom");
//	ani->speak();
//	delete ani;
//}
//
//
//
//int main() {
//
//	test1();
//	system("pause");
//	return 0;
//}