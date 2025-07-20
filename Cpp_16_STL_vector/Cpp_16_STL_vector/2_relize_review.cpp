#include "vector_review.h"

void print(const mm_vector::vector<int>& v) {
	//范围for 普通对象转换调用普通迭代器  const对象转换调用const迭代器
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}
void testVector1() {
	mm_vector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(22);
	v1.push_back(33);
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;

	for (auto& e : v1)
		++e;
	print(v1);

	for (int i = 0; i < v1.size(); ++i)
		++v1[i];
	print(v1);
}
void testVector2() {
	mm_vector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);	//已有8个元素，再插入时会触发扩容逻辑
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;

	// 在第三个位置插入
	// 在 insert内部修改 pos 的值，解决的是内部的迭代器失效问题
	// 外部的迭代器传给 insert 的形参 pos 后，值传递传拷贝，pos的修改不会改变p的值，因此无法解决p失效的问题
	// 也不能将 insert 的参数 pos 设为 引用或const 引用，否则insert逻辑无法实现
	// insert 之后，迭代器可能会失效。扩容就会引起迭代器失效。
	// 但不同平台的扩容机制不一样，所以无法预防迭代器失效何时发生
	// 因此记住，insert之后不要使用 传入的实参迭代器了   最终我们认为 insert之后 迭代器都会失效
	mm_vector::vector<int>::iterator p = v1.begin() + 3;
	v1.insert(p, 300);
	print(v1);

	// 300 插入后，迭代器p已经失效了，对p位置做修改，修改失败
	*p += 10;	//扩容后    
	print(v1);
	//m_vector::vector<int>::iterator pres = v1.insert(p, 200);

	//*p + 200;
	cout << *p << endl;
	//p记录的是原空间地址，如果原空间发生了扩容，原空间的地址会发生改变
	// 那么p就成了野指针, 这里是野指针造成的迭代器失效

	////insert之后，迭代器 有可能会失效(主要会在发生 扩容时 迭代器失效)，但不同平台的扩容策略不同，难以避免
	//// insert 之后就不要使用这个形参迭代器了，因为insert后，迭代器可能失效
	////正确的做法是，使用insert返回的结果当来获取pos的值
	////这样的接口是不安全的，因此  直接认为 insert后，迭代器失效了
	////cout << *pres << endl;
	//print(v1);
}


//测试删除，头删没问题
void testVector3() {
	mm_vector::vector<int> v1;
	//std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;
	/*v1.erase(v1.begin());
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;*/

	// 修改后无问题
	auto it = v1.begin();
	while (it != v1.end()) {
		if (*it % 2 == 0)
			it = v1.erase(it);
		//v1.erase(it);
		else
			++it;
	}
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;

	// 也认为 erase 会迭代器失效, 不能访问
	// vs下会进行强制检查，访问会报错
	//auto it = v1.begin() + 3;
	//v1.erase(it);
	//cout << *it << endl;
	//++it;
	//cout << *it << endl;
	//print(v1);
	//// g++中实现的erase，删除时也是不抹除数据的
	// 考虑到平台的可移植性，认为erase也会迭代器失效

	// 还有一些平台，不断地删除数据，删到只剩原有数据的一般时，有的平台会进行缩容
	// 缩容一般都是异地缩容，那么erase后也会出现迭代器失效
}

void testVector4() {
	mm_vector::vector<int> v(3, 6);
	v.resize(10, 2);

	//resize 初始化，val可以有默认值(缺省参数)，但如何确定缺省参数的类型
	// 此时 T() 本质是一个T类型的匿名对象 ，会调用T类型的默认构造，
	// 一般而言，写一个类，一定要提供默认构造
	// 如果是 int 等内置类型 resize怎么跑？   理论上不能跑
	// 有了模板后，C++对内置类型进行了升级，也支持内置类型有默认构造函数
	int i = 0;
	int j = int();	//默认是 0  int 默认是0 double 默认是 0.0  指针默认是nullptr
	int k = int(20);
	cout << i << " " << j << " " << k << endl;

	for (auto& e : v)
		cout << e << " ";
	cout << endl;
}

//void testVector5() {
//	m_vector::vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	m_vector::vector<int> v1(v);	//浅拷贝，同一块空间会析构两次，因此要实现深拷贝
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//
//	m_vector::vector<int> v2;
//	v2.resize(10, 3);
//	v1 = v2;
//	v2 = v2;
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//}
//
//void testVector6() {
//	m_vector::vector<string> v;
//	//单参数的构造函数支持隐式类型转换
//	v.push_back("111111111111111111");		// const char* 可以隐式类型转换为string
//	v.push_back("222222222222222222");
//	v.push_back("333333333333333333");
//	v.push_back("444444444444444444");
//	v.push_back("555555555555555555");
//	for (auto& e : v)	//范围for的底层是取迭代器，*it 赋值给 e ,因此自定义类型最好要加引用
//		cout << e << " ";
//	cout << endl;
//	m_vector::vector<string> v1(v);		//如果拷贝构造用的也是memcpy，那么存string时也会出错
//	for (auto& e : v1)
//		cout << e << " ";
//}
//
//void testVector7() {
//	m_vector::vector<int> v1(10, 1);
//	m_vector::vector<int> v2(10, 1);
//	m_vector::vector<string> v3(10, "hello");
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//	for (auto& e : v3)
//		cout << e << " ";
//	cout << endl;
//}

int main() {
	//testVector1();
	//testVector2();
	//testVector3();
	testVector4();
	//testVector5();
	//testVector6();
	//testVector7();

	return 0;
}

//int main() {
//
//	int i = 0;
//	int j = int();	// 内置 int 的默认构造是 0
//	int k = int(20);	// 用 20 进行构造
//	cout << i << " " << j << " " << k << endl;
//	return 0;
//}