 //3. 模板的特化   有时可能需要针对某些类型进行特殊化处理
 //模板的特化 就是 
 //在该模板中，某些类型需要特殊处理且要频繁调用，专门为该类型编写一个特定的模板函数或模板类

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
	// 有可能 我想传地址，但不按照地址的大小比，按值去比
	cout << Less(1, 2) << endl;   // 匹配 1
	int a = 1, b = 2;
	cout << Less(&a, &b) << endl;	// 匹配 2 
	double c = 1.1, d = 2.2;
	cout << Less(&c, &d) << endl;	 // 匹配 3  

}
// 函数模板可以进行特化 但一般没必要特化，可以通过函数重载来实现

// 3.2 类模板的特化
template<class T1, class T2>
class Data {
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
// 对Data的特殊类型<int, double>做处理  类模板的特化
// 全特化
template<>
class Data<int, double> {
public:
	Data() { cout << "Data<int, double>" << endl; }
private:
};

// 偏特化  偏特化  部分  模板参数
template<class T>
class Data<T, double> {
public:
	Data() { cout << "Data<T, double>" << endl; }
private:
};
// 偏特化  对类型进一步做限制
template<class T1, class T2>
class Data<T1*, T2*> {
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1&, T2&> {
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1&, T2*> {
public:
	Data() { cout << "Data<T1&, T2*>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1*, T2&> {
public:
	Data() { cout << "Data<T1*, T2&>" << endl; }
private:
};
// 根据已有的一个模板类 而 特化出来的模板类，只是通用模板类的一个特殊化版本
// 新特化出来的类，是一个新的类型，类内的成员变量和成员函数，不必和源类保持一致
// 可根据 特化出来的具体类型的需求 做具体安排
void test4() {
	// 偏特化  偏特化  部分  模板参数
	cout << "偏特化  偏特化部分模板参数" << endl;
	Data<int, int> d1;   // 未特化 Data<T1, T2>
	Data<int, double> d2;	// 特化 Data<int, double>
	Data<Data<int, int>, double> d3;	// 特化一次 Data<T1, T2>  Data<T, double>
	Data<Data<vector<int>, int>, double> d4;	// 特化两次 Data<T1, T2>  Data<T, double>
	// 偏特化  对类型的进一步限制
	cout << "偏特化  对类型进一步限制" << endl;
	Data<int*, double*> d5;			// 特化 Data<T1*, T2*>
	Data<void*, void*> d6;			// 特化 Data<T1*, T2*>
	Data<int*, double&> d7;			// 特化 Data<T1*, T2&>
	Data<char&, double&> d8;			// 特化 Data<T1&, T2&>
	Data<char&, double*> d9;			// 特化 Data<T1&, T2*>
}

// 一般在开发中，特化都是 特化一些极小的类

//int main() {
//	cout << "偏特化  偏特化部分模板参数" << endl;
//
//	Data<int, int> d1;   // 未特化 Data<T1, T2>
//	Data<int, double> d2;	// 特化 Data<int, double>
//	Data<Data<int, int>, double> d3;	// 特化一次 Data<T1, T2>  Data<T, double>
//	Data<Data<vector<int>, int>, double> d4;	// 特化两次 Data<T1, T2>  Data<T, double>
//	
//	cout << "偏特化  对类型进一步限制" << endl;
//	Data<int*, double*> d5;			// 特化 Data<T1*, T2*>
//	Data<void*, void*> d6;			// 特化 Data<T1*, T2*>
//	Data<int*, double&> d7;			// 特化 Data<T1*, T2&>
//	Data<char&, double&> d8;			// 特化 Data<T1&, T2&>
//	Data<char&, double*> d9;			// 特化 Data<T1&, T2*>
//	return 0;
//}