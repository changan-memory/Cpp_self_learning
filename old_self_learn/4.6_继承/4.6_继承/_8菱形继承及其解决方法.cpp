//#include <iostream>
//using namespace std;
//
////���μ̳�   
//// ����������̳������ ���μ̳е�����
//
//// ������̳п��Խ�� ���μ̳е�����
////������
//class Animal{
//public:
//	int _age;
//};
//
//
////�ڼ̳�֮ǰ���� �ؼ��� virtual ������μ̳� 
//
//// virtual �̳�ʱ, ������ʵ�����Ǽ̳���һ��ָ�� vbptr��virtua; base pointer��
//// ָ��ָ��һ���� ���м�¼�� �̳й��������Ե� ƫ����, ͨ������ƫ���� ��ʵ�����ݵĶ�һ��
//class Sheep:virtual public Animal{};
//class tuo:virtual public Animal{};
//
//class Sheeptuo: public Sheep, public tuo{};
//
//
//
//void test() {
//	Sheeptuo st;
//	//���μ̳� ���Լ�������������  ����ʱҲ��Ҫ��������
//
//	//��������̳е�ʱ�� ����ֻ��һ��
//	st.Sheep::_age = 100;
//	st.tuo::_age = 200;
//	cout << st.Sheep::_age << endl;
//	cout << st.tuo::_age << endl;
//	cout << st._age << endl;
//}
//
//
//
//int main() {
//
//
//	test();
//	return 0;
//}