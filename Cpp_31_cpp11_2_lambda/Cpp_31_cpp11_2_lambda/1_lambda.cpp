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
		auto ComparePriceGreater = [](const Goods gl, const Goods gr)->bool {
			                                return gl._price > gr._price;
			};

	}
	void test3() {
		vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 },
							{ "����", 2.2, 3 }, { "����", 1.5, 4 } };
		// ʹ�� Lambda ���ʽ����Ƚ�����
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
}
int main() {
	//use_1::test1();
	use_1::test3();
	return 0;
}