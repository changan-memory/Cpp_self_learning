#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace use_1 {
	struct Goods {
		string _name; // 名字
		double _price; // 价格
		int _evaluate; // 评价
		Goods(const char* str, double price, int evaluate)
			:_name(str)
			, _price(price)
			, _evaluate(evaluate)
		{
		}
	};

	// 仿函数
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
		vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 },
							{ "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
		// 第一次对价格排序   第二次对评价排序 第三次按照名字排序
		/*std::sort(v.begin(), v.end());
		std::sort(v.begin(), v.end());*/
		// 因此 operator< 或 operator> 不能解决问题
		// 针对以上问题，只有仿函数才能解决问题
		std::sort(v.begin(), v.end(), ComparePriceGreater());	// 价格降序
		std::sort(v.begin(), v.end(), ComparePriceLess());		// 价格升序
		std::sort(v.begin(), v.end(), CompareEvaluateGreater());	// 评价降序
		std::sort(v.begin(), v.end(), CompareEvaluateLess());	// 评价升序
		// 万一别人写的仿函数 Compare1 Compare2 可读性极差
		// 而且比较条目多了，写多个仿函数，也会增加阅读困难
		// 或者有人写代码不加注释，阅读性极差
		std::sort(v.begin(), v.end(), Compare1());	// 这种写法难搞
		std::sort(v.begin(), v.end(), Compare2());
		std::sort(v.begin(), v.end(), Compare3());
		std::sort(v.begin(), v.end(), Compare4());
	}
	// 最好的解决方式是 Lambda 表达式
	// Lambda 是 局部的  匿名函数  对象
	void test2() {
		// Lambda 表达式  是一个匿名函数对象
		//Lambda 表达式  的基本使用
		//          捕获列表  参数列表   返回值   函数体
		auto less = [](int x, int y)->bool { return x < y; };
		cout << less(1, 2) << endl;
		auto ComparePriceGreater = [](const Goods gl, const Goods gr)->bool {
			                                return gl._price > gr._price;
			};

	}
	void test3() {
		vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 },
							{ "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
		// 使用 Lambda 表达式解决比较问题
		std::sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
			return gl._price > gr._price;
			});	// 价格降序
		std::sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
			return gl._price < gr._price;
			});		// 价格升序
		std::sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
			return gl._evaluate > gr._evaluate;
			});	// 评价降序
		std::sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
			return gl._evaluate < gr._evaluate;
			});	// 评价升序
		
	}
}
int main() {
	//use_1::test1();
	use_1::test3();
	return 0;
}