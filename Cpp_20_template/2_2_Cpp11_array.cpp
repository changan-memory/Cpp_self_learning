// 2. 非类型模板参数的应用场景之一   std::array

#include <iostream>
#include <array>
#include <vector>
using namespace std;

void testArray() {
	// C++11更新了一个array   支持模板的静态数组
	//int a[8];
	array<int, 10> a;
	a[0] = 0;
	for (auto e : a)
		cout << e << " ";
	cout << endl;

	// array对越界的检查十分严格，越界读写都能检查
	// C风格的普通数组，不能越界检查读，少部分越界写可以检查出来
	//a[10];

	//既然array对越界的检查十分严格，越界读写都能检查。那我为什么不使用vector呢
	// 既能初始化，还能检查读写越界，实现静态数组的话，我不扩容就是了
	vector<int> v(10, 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	//v[10];
	// 总之 std::array确实鸡肋
}
//int main() {
//	testArray();
//	return 0;
//}