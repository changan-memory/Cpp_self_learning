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
		auto ComparePriceGreater = [](const Goods gl, const Goods gr)->bool
			{
				return gl._price > gr._price;
			};
		// 返回值可以省略
		auto ComparePriceGreater2 = [](const Goods gl, const Goods gr)
			{
				return gl._price > gr._price;
			};

	}
	void test3() {
		vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 },
							{ "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
		// 使用 Lambda 表达式解决比较问题
		// Lambda 不适合写长函数，适合写一些短小的函数
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

	void test4() {
		int a = 1, b = 3;
		auto add1 = [](int x, int y)->int { return x + y; };
		auto add2 = [](int x, int y) { return x + y; };
		cout << add1(1, 3) << endl;
		cout << add2(1, 3) << endl;
		// 交换
		auto swap1 = [](int& left, int& right)->void {
			int tmp = left;
			left = right;
			right = tmp;
			};
		swap1(a, b);
		// lambda 表达式中不能调用局部函数，但可以调用全局函数
		auto swap2 = [](int& left, int& right)->void {
			int tmp = left;
			left = right;
			right = tmp;
			test3();	// Lambda 中全局函数可以调用
			//cout << add1(left, right) << endl;	// Lambda 中局部函数不能直接调用
			};
		swap2(a, b);
	}
	// Lambda 中捕获列表的用法
	void test5() {
		// 传值捕获
		int a = 1, b = 3;
		double rate = 2.5555;
		auto add1 = [rate](int x, int y) { return (x + y) * rate; };
		cout << add1(a, b) << endl;

		// mutable的用法
		// 默认情况下，按值捕获的 lambda 函数总是一个const函数，mutable可以取消其常量性
		// 使用该修饰符时，参数列表不可省略(即使参数为空)
		// mutable 让捕获到的c 和 d 可以被修改，但是 值传递捕获，依然是外部变量的拷贝
		// 因此这里的  值捕获  不能 完成对 c 和 d 的交换
		int c = 8, d = 9;
		auto swap1 = [c, d]() mutable ->void {
			int tmp = c;
			c = d;
			d = tmp;
			};

		// 引用捕获
		auto swap2 = [&c, &d]()->void {
			auto tmp = c;
			c = d;
			d = tmp;
			};
		swap2();
	}

	// 捕获列表中一个个写太麻烦了，捕获父作用域中所有的变量
	void test6() {
		// 仅引用捕获
		int a = 1, b = 2, c = 3, d = 4;
		
		auto func1 = [&]() {
			++a;
			++b;
			++c;
			++d;
			};
		func1();

		// 仅值捕获
		auto func2 = [=]()mutable {
			++a;
			++b;
			++c;
			++d;
			};
		func2();
	}

	// 值捕获  和 引用捕获  混合
	void test7() {
		// 仅引用捕获
		int a = 1, b = 2, c = 3, d = 4;
		const int e = 6;

		// 引用捕获副 父作用域所有变量，值捕获 c 变量
		cout << &e << endl;
		auto func1 = [&, c]() {
			++a;
			++b;
			//++c;	// 默认 c 不可修改
			++d;
			cout << &e << endl;
			cout << typeid(e).name() << endl;
			};
		func1();
	}

	// Lambda 之间不能赋值
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
		// 函数对象
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