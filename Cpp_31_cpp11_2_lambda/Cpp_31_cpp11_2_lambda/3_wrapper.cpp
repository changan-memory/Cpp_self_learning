// ��װ����ɱ�ģ�����
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

// ret = func(x);
//����func������ʲô�أ���ôfunc�����Ǻ�����������ָ�룿��������(�º�������)��Ҳ�п���
//��lamber���ʽ����������Щ���ǿɵ��õ����ͣ���˷ḻ�����ͣ����ܻᵼ��ģ���Ч�ʵ��£�
//Ϊʲô�أ����Ǽ������¿�

template<class F, class T>
T useF(F f, T x) {
	static int count = 0;
	cout << "count: " << ++count << " ";
	cout << "count: " << &count << endl;
	return f(x);
}
double f(double i) {
	return i / 2;
}
struct Functor {
	double operator()(double d) {
		return d / 3;
	}
};

void test1() {
	// ������
	cout << useF(f, 11.11) << endl;

	// ��������
	cout << useF(Functor(), 11.11) << endl;

	// lambda ���ʽ
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;

	function<double(double)> f1 = f;
	function<double(double)> f3 = Functor();
	function<double(double)> f2 = [](double d)->double { return d / 4; };
}

void test2() {
	// ������
	cout << useF(f, 11.11) << endl;

	// ��������
	cout << useF(Functor(), 11.11) << endl;

	// lambda ���ʽ
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;

	std::function<double(double)> f1 = f;
	std::function<double(double)> f2 = Functor();
	std::function<double(double)> f3 = [](double d)->double { return d / 4; };
}

void test3() {
	std::function<double(double)> f1 = f;
	std::function<double(double)> f2 = Functor();
	std::function<double(double)> f3 = [](double d)->double { return d / 4; };
	// �ɵ��ö���洢�������У��������������
	std::vector<std::function<double(double)>> v1 = { f1, f2, f3 };	
	std::vector<std::function<double(double)>> v2 = 
	{ 
		f, Functor(), [](double d)->double { return d / 4; }
	};
	double n = 3.4;
	for (auto& e : v2) {
		cout << e(n++) << endl;
	}
}

void test4() {
	std::function<double(double)> func1 = f;	// ����ָ��
	std::function<double(double)> func2 = Functor();	// �º���
	std::function<double(double)> func3 = [](double d)->double { return d / 4; };	// Lambda

	// ͳһ�����װ�����е���
	cout << useF(func1, 11.11) << endl;
	cout << useF(func2, 11.11) << endl;
	cout << useF(func3, 11.11) << endl;
}
//int main() {
//	//test3();
//	test4();
//	return 0;
//}