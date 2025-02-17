#include <iostream>
using namespace std;

class Date {
public:
	//������Ĭ�ϳ�Ա����һ�㲻�����¶��� ��������Ĭ�ϻ����ɡ�
	//�����������һ�㲻��Ҫ�Լ�ʵ�����أ�ʹ�ñ��������ɵ�Ĭ��ȡ��ַ�����ؼ��ɣ�
	// ֻ���������������Ҫ���أ��������ñ��˻�ȡ��ָ�������ݣ�
	Date* operator&() {
		cout << "Date* operator&()" << endl;
		//return this;
		return nullptr;	//���粻���ñ��˷��ʵ����޸Ķ���ĵ�ַ
	}
	//�����������ɺ�������(���� this ���Ͳ�ͬ)
	//Date* const this �� const Date* const this
	const Date* operator&() const {
		cout << "const Date* operator&() const" << endl;
		return this;
	}
private:
	int _year = 2025;
	int _month = 2;
	int _day = 17;
};
int main() {
	Date d1;
	const Date d2;	//const���Ͷ�������ʱ�����ʼ������Ϊֻ����һ�εĳ�ʼ������
	cout << &d1 << endl;
	cout << &d2 << endl;
	return 0;
}

//class Date {
//private:
//	int _year = 2025;
//	int _month = 2;
//	int _day = 17;
//};
//int main() {
//	Date d1;
//	const Date d2;	//const���Ͷ�������ʱ�����ʼ������Ϊֻ����һ�εĳ�ʼ������
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	return 0;
//}