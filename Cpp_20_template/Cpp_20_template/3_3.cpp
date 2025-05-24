// 3. 模板的特化


#include <iostream>
#include <vector>
#include <list>
using namespace std;


// 3.1 函数模板的特化
// 函数模板 -- 参数匹配
template<class T>		// 1
bool Less(T left, T right) {
	return left < right;
}
//// 标准的函数模板的特化   的写法
//template<>				// 2
//bool Less<int*>(int* left, int* right) {
//	return *left < *right;
//}

// 但其实没必要进行这样的特化，
// 因为要进行特化了，倒不如直接写一个新的函数，和上述函数构成重载，template<>没必要写了
bool Less(int* left, int* right) {		// 2
	return *left < *right;
}
// 至此依旧没有解决问题，因为此时只能结构int* ,double*呢
// 最终实现
template<class T>		// 3
bool Less(T* left, T* right) {
	return *left < *right;
}
void test3() {
	cout << Less(1, 2) << endl;   // 匹配 1
	int a = 1, b = 2;
	cout << Less(&a, &b) << endl;	// 匹配 2 // 有可能 我想传地址，但不按照地址的大小比，按值去比
	double a1 = 1.1, b1 = 2.2;
	cout << Less(&a, &b) << endl;	 // 匹配 3  // 有可能 我想传地址，但不按照地址的大小比，按值去比

}

// 3.2 类模板的特化

//int main() {
//	
//	test3();
//	return 0;
//}