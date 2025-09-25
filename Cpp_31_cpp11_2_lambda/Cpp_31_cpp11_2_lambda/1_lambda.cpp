#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace use_1 {
	struct Goods {
		string _name; // ����
		double _price; // �۸�
		int _evaluate; // ����
		Goods(const char* str, double price, int evaluate)
			:_name(str)
			, _price(price)
			, _evaluate(evaluate)
		{
		}
	};

	// �º���
	struct ComparePriceGreater {
		bool operator()(const Goods& gl, const Goods& gr) {
			return gl._price > gr._price;
		}
	};
	struct ComparePriceLess {
		bool operator()(const Goods& gl, const Goods& gr) {
			return gl._price < gr._price;
		}
	};
	struct CompareEvaluateGreater {
		bool operator()(const Goods& gl, const Goods& gr) {
			return gl._evaluate > gr._evaluate;
		}
	};
	struct CompareEvaluateLess {
		bool operator()(const Goods& gl, const Goods& gr) {
			return gl._evaluate < gr._evaluate;
		}
	};

	struct Compare1 {
		bool operator()(const Goods& gl, const Goods& gr) {
			return gl._price > gr._price;
		}
	};
	struct Compare2 {
		bool operator()(const Goods& gl, const Goods& gr) {
			return gl._price < gr._price;
		}
	};
	struct Compare3 {
		bool operator()(const Goods& gl, const Goods& gr) {
			return gl._evaluate > gr._evaluate;
		}
	};
	struct Compare4{
		bool operator()(const Goods& gl, const Goods& gr) {
			return gl._evaluate < gr._evaluate;
		}
	};

	void test1() {
		vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 },
							{ "����", 2.2, 3 }, { "����", 1.5, 4 } };
		// ��һ�ζԼ۸�����   �ڶ��ζ��������� �����ΰ�����������
		/*std::sort(v.begin(), v.end());
		std::sort(v.begin(), v.end());*/
		// ��� operator< �� operator> ���ܽ������
		// ����������⣬ֻ�зº������ܽ������
		std::sort(v.begin(), v.end(), ComparePriceGreater());	// �۸���
		std::sort(v.begin(), v.end(), ComparePriceLess());		// �۸�����
		std::sort(v.begin(), v.end(), CompareEvaluateGreater());	// ���۽���
		std::sort(v.begin(), v.end(), CompareEvaluateLess());	// ��������
		// ��һ����д�ķº��� Compare1 Compare2 �ɶ��Լ���
		// ���ұȽ���Ŀ���ˣ�д����º�����Ҳ�������Ķ�����
		// ��������д���벻��ע�ͣ��Ķ��Լ���
		std::sort(v.begin(), v.end(), Compare1());	// ����д���Ѹ�
		std::sort(v.begin(), v.end(), Compare2());
		std::sort(v.begin(), v.end(), Compare3());
		std::sort(v.begin(), v.end(), Compare4());
	}
	// ��õĽ����ʽ�� Lambda ���ʽ
	// Lambda �� �ֲ���  ��������  ����
	void test2() {
		// Lambda ���ʽ  ��һ��������������
		//Lambda ���ʽ  �Ļ���ʹ��
		//          �����б�  �����б�   ����ֵ   ������
		auto less = [](int x, int y)->bool { return x < y; };
		cout << less(1, 2) << endl;
		auto ComparePriceGreater = [](const Goods gl, const Goods gr)->bool
			{
				return gl._price > gr._price;
			};
		// ����ֵ����ʡ��
		auto ComparePriceGreater2 = [](const Goods gl, const Goods gr)
			{
				return gl._price > gr._price;
			};

	}
	void test3() {
		vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 },
							{ "����", 2.2, 3 }, { "����", 1.5, 4 } };
		// ʹ�� Lambda ���ʽ����Ƚ�����
		// Lambda ���ʺ�д���������ʺ�дһЩ��С�ĺ���
		std::sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
			return gl._price > gr._price;
			});	// �۸���
		std::sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
			return gl._price < gr._price;
			});		// �۸�����
		std::sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
			return gl._evaluate > gr._evaluate;
			});	// ���۽���
		std::sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
			return gl._evaluate < gr._evaluate;
			});	// ��������
	}

	void test4() {
		int a = 1, b = 3;
		auto add1 = [](int x, int y)->int { return x + y; };
		auto add2 = [](int x, int y) { return x + y; };
		cout << add1(1, 3) << endl;
		cout << add2(1, 3) << endl;
		// ����
		auto swap1 = [](int& left, int& right)->void {
			int tmp = left;
			left = right;
			right = tmp;
			};
		swap1(a, b);
		// lambda ���ʽ�в��ܵ��þֲ������������Ե���ȫ�ֺ���
		auto swap2 = [](int& left, int& right)->void {
			int tmp = left;
			left = right;
			right = tmp;
			test3();	// Lambda ��ȫ�ֺ������Ե���
			//cout << add1(left, right) << endl;	// Lambda �оֲ���������ֱ�ӵ���
			};
		swap2(a, b);
	}
	// Lambda �в����б���÷�
	void test5() {
		// ��ֵ����
		int a = 1, b = 3;
		double rate = 2.5555;
		auto add1 = [rate](int x, int y) { return (x + y) * rate; };
		cout << add1(a, b) << endl;

		// mutable���÷�
		// Ĭ������£���ֵ����� lambda ��������һ��const������mutable����ȡ���䳣����
		// ʹ�ø����η�ʱ�������б���ʡ��(��ʹ����Ϊ��)
		// mutable �ò��񵽵�c �� d ���Ա��޸ģ����� ֵ���ݲ�����Ȼ���ⲿ�����Ŀ���
		// ��������  ֵ����  ���� ��ɶ� c �� d �Ľ���
		int c = 8, d = 9;
		auto swap1 = [c, d]() mutable ->void {
			int tmp = c;
			c = d;
			d = tmp;
			};

		// ���ò���
		auto swap2 = [&c, &d]()->void {
			auto tmp = c;
			c = d;
			d = tmp;
			};
		swap2();
	}

	// �����б���һ����д̫�鷳�ˣ����������������еı���
	void test6() {
		// �����ò���
		int a = 1, b = 2, c = 3, d = 4;
		
		auto func1 = [&]() {
			++a;
			++b;
			++c;
			++d;
			};
		func1();

		// ��ֵ����
		auto func2 = [=]()mutable {
			++a;
			++b;
			++c;
			++d;
			};
		func2();
	}

	// ֵ����  �� ���ò���  ���
	void test7() {
		// �����ò���
		int a = 1, b = 2, c = 3, d = 4;
		const int e = 6;

		// ���ò��� �����������б�����ֵ���� c ����
		cout << &e << endl;
		auto func1 = [&, c]() {
			++a;
			++b;
			//++c;	// Ĭ�� c �����޸�
			++d;
			cout << &e << endl;
			cout << typeid(e).name() << endl;
			};
		func1();
	}

	// Lambda ֮�䲻�ܸ�ֵ
	void test8() {
		auto f1 = [](int x, int y)->int { return x + y; };
		auto f2 = [](int x, int y)->int { return x + y; };
		//f1 = f2;

		cout << typeid(f1).name() << endl;
		cout << typeid(f2).name() << endl;
		cout << f1(1, 2) << endl;
	}


	class Rate {
	public:
		Rate(double rate) : _rate(rate)
		{
		}
		double operator()(double money, int year)
		{
			return money * _rate * year;
		}
	private:
		double _rate;
	};
	void test9() {
		// ��������
		double rate = 0.49;
		Rate r1(rate);
		r1(10000, 2);

		// lambda
		auto r2 = [=](double monty, int year)->double {return monty * rate * year;
			};
		r2(10000, 2);
	}
}
int main() {
	//use_1::test1();
	//use_1::test3();
	//use_1::test4();
	//use_1::test5();
	//use_1::test6();
	//use_1::test7();
	//use_1::test8();
	use_1::test9();

	return 0;
}