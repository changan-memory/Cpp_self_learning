#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int Sub(int a, int b) {
	return a - b;
}
void test5() {
	function<int(int, int)> rSub1 = bind(Sub, placeholders::_1, placeholders::_2);
	cout << rSub1(7, 3) << endl;

	function<int(int, int)> rSub2 = bind(Sub, placeholders::_2, placeholders::_1);
	cout << rSub2(7, 3) << endl;
}
double Plus(int a, int b, double rate) {
	return (a + b) * rate;
}
double PPlus(double rate, int a, int b) {
	return (a + b) * rate;
}
double PPPlus(int a, double rate, int b) {
	return (a + b) * rate;
}
void test6() {
	// ȱʡ������д���ģ�ֻ����һ��ֵ��bind ���Դ������ֵͬ�Ĳ���
	function<double(int, int)> plus1 = bind(Plus, placeholders::_1, placeholders::_2, 4.1);
	function<double(int, int)> plus2 = bind(Plus, placeholders::_1, placeholders::_2, 5.1);
	function<double(int, int)> plus3 = bind(Plus, placeholders::_1, placeholders::_2, 6.1);
	cout << plus1(5, 3) << endl;
	cout << plus2(5, 3) << endl;
	cout << plus3(5, 3) << endl;
	cout << endl;

	function<double(int, int)> plus = bind(Plus, placeholders::_1, placeholders::_2, 4.1);
	function<double(int, int)> pplus = bind(PPlus, 4.2, placeholders::_1, placeholders::_2);
	function<double(int, int)> ppplus = bind(PPPlus, placeholders::_1, 4.3, placeholders::_2);

	cout << plus(5, 3) << endl;
	cout << pplus(5, 3) << endl;
	cout << ppplus(5, 3) << endl;
}
class SubClass {
public:
	// ��̬��Ա����
	static int s_sub(int a, int b) {
		return a - b;
	}
	// �Ǿ�̬��Ա����
	int sub(int a, int b) {
		return a - b;
	}
};
void test7() {
	// �󶨾�̬����������ȡ��ַ��Ҳ���Բ�ȡ
	function<int(int, int)> sub1 = bind(SubClass::s_sub, placeholders::_1, placeholders::_2);
	function<int(int, int)> sub2 = bind(&SubClass::s_sub, placeholders::_1, placeholders::_2);
	cout << sub1(5, 3) << " " << sub2(3, 5) << endl;
}
void test8() {
	// �󶨷Ǿ�̬����������ȡ��ַ������Ҫ �ֶ� ��thisָ�봫��
	SubClass s;
	// ������ �������ָ�붼���Ե���
	// ͨ�������ָ����� operator()
	function<int(int, int)> sub1 = bind(&SubClass::sub, &s, placeholders::_1, placeholders::_2);
	// ͨ������ֱ�ӵ��� operator()
	function<int(int, int)> sub2 = bind(&SubClass::sub, s, placeholders::_1, placeholders::_2);
	cout << sub1(5, 3) << " " << sub2(3, 5) << endl;

	// ����������Ҳ����
	// ������������� operator()
	function<int(int, int)> sub3 = bind(&SubClass::sub, SubClass(), placeholders::_1, placeholders::_2);
	cout << sub3(9, 4) << " " << sub3(4, 9) << endl;
	// ���ϵĵײ�ʵ�� ���Ƿº���
	// ���ʶ������� operator()
}
//int main() {
//	//test5();
//	//test6();
//	//test7();
//	test8();
//
//	return 0;
//}