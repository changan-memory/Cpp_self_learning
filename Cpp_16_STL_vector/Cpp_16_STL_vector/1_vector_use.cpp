#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

void Test_v1() {
	//用基础直接使用vector的三种遍历
	vector<int> v1;		//空构造
	v1.push_back(2);	//尾插
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	//使用[]配合size遍历
	for (int i = 0; i < v1.size(); ++i) {
		cout << v1[i] << " ";
	}
	cout << endl;
	//迭代器遍历
	vector<int>::iterator it = v1.begin();
	while (it != v1.end()) {
		cout << *it <<" ";
		++it;
	}
	cout << endl;
	//范围for遍历
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
}

void Test_v2() {
	//vector<char> strV;	//vector<char>能否替代 string ?
	//答案是不能
	// string 要求最后有 '\0' ,可以更好的兼容C语言
	//string的接口更加丰富，有更多专用的接口 如  += 字符串比较大小，查找

	// string 是


	//单参数的构造函数  支持隐式类型转换
	//vector也可以存string
	vector<string> strV;
	//构造一个string对象在存储
	string name1("张三");
	strV.push_back(name1);
	//用匿名对象插入
	strV.push_back(string("张三"));
	//隐式类型转换
	strV.push_back("张三");
}

void Test_v3() {
	//1. 用n个相同的value初始化，第一个参数是个数，第二个参数是value
	vector<int> v1(10, 1);	
	vector<string> v2(5, "***");
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : v2) {
		cout << e << " ";
	}
	cout << endl;

	//2. 用其他(自身)容器的迭代器进行初始化
	vector<int> v3(v1.begin(), v1.end());
	for (auto& e : v3) {
		cout << e << " ";
	}
	cout << endl;

	//3. 用其他类型的迭代器初始化
	string str("hello world");
	vector<char> v4(str.begin(), str.end());
	for (auto& e : v4) {
		cout << e << " ";
	}
	cout << endl;
	
	//4. 用C语言风格的数组进行初始化
	int arr[] = { 66, 77, 12, 39, 6, 2};	
		//容器的迭代器的end指向的是最后一个元素的下一个位置
	vector<int> v5(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto& e : v5) {
		cout << e << " ";
	}
	cout << endl;

	//容器配合算法库
	//升序 less   sort默认排升序
	sort(v5.begin(), v5.end());
	for (auto& e : v5) {
		cout << e << " ";
	}
	cout << endl;

	//排降序的两种方法
	sort(v5.begin(), v5.end(), greater<int>());	//1. 使用sort的重载版本
	for (auto& e : v5) {
		cout << e << " ";
	}
	cout << endl;

	//sort(v5.end(), v5.begin());	//这样传会导致数组越界
	sort(v5.rbegin(), v5.rend());					//2. 反向传迭代器
	for (auto& e : v5) {
		cout << e << " ";
	}
	cout << endl;

	sort(v4.begin(), v4.end());		//sort可以传  任意实现了迭代器 的容器				
	for (auto& e : v4) {
		cout << e << " ";
	}
	cout << endl;
}
void Test_v4() {
	//resize 和 reserve
	vector<int> v1;
	v1.reserve(10);		//reserve改变的是capacity,是为了,而不是size
	for (size_t i = 0; i < 10; ++i) {	//不能直接到 i<10
		//v1[i] = i;	//用[]+下标访问会进行数组越界检查,capacity的大小不等于size的大小
		//一般size比capacity要小，[]访问时，不能访问size之外的数据
		v1.push_back(i);	//最好用尾插
	}
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
}
int main() {
	//Test_v1();
	//Test_v2();
	//Test_v3();
	Test_v4();
	return 0;
}

namespace test {
	class A {
		int _a;
	public:
		A(int a)
			:_a(a)
		{ }
	};
	int main() {
		A a1(1);	//单参数的构造函数支持隐式类型转换
		A a2 = 1;
		return 0;
	}
}