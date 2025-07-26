#include "m_list.h"

void print(const m_list::list<int>& lt) {
	m_list::list<int>::const_iterator it = lt.begin();	// 自定义迭代器类型 
	// 这里的赋值是调用拷贝构造，用已存在的对象初始化另一个对象，这里的需要是完成浅拷贝即可
	while (it != lt.end()) {
		// 调用的本质 it.operator(it = lt.end())	调用时,end()返回对象的拷贝,形成临时对象
									// 临时对象具有常性，因此operator!=()的实现处参数要加const
		std::cout << (*it) << " ";
		//++it;
		it++;
	}
	std::cout << std::endl;
}

void test_list1() {
	m_list::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	m_list::list<int>::iterator it = lt.begin();	// 自定义迭代器类型 
	// 这里的赋值是调用拷贝构造，用已存在的对象初始化另一个对象，这里的需要是完成浅拷贝即可
	while (it != lt.end()) {	
		// 调用的本质 it.operator(it = lt.end())	调用时,end()返回对象的拷贝,形成临时对象
									// 临时对象具有常性，因此operator!=()的实现处参数要加const
		std::cout << (*it) << " ";
		//++it;
		it++;
	}
	std::cout << std::endl;
	for (auto& e : lt)
		std::cout << e << " "; std::cout << std::endl;
}
void test_list2_insert_erase() {
	m_list::list<int> lt;
	lt.push_back(1);
	lt.push_back(3);
	lt.push_back(5);
	lt.insert(lt.begin(), 2);
	lt.insert(++lt.begin(), 4);
	lt.insert(++lt.begin(), 5);
	for (auto& e : lt)
		std::cout << e << " "; std::cout << std::endl;
	lt.pop_back();
	lt.pop_back();
	lt.erase(lt.begin());
	lt.erase(lt.begin()++);
	for (auto& e : lt)
		std::cout << e << " "; std::cout << std::endl;
	lt.pop_back();
	lt.pop_back();
	/*for (auto& e : lt)
		std::cout << e << " "; std::cout << std::endl;*/
	print(lt);
}

struct A {
	A(int a1 = 0, int a2 = 0)
		:_a1(a1)
		,_a2(a2)
	{ }
	int _a1;
	int _a2;
};
// opeartor->
void test_operator() {
	m_list::list<A> lt;
	lt.push_back(A(1, 1));
	lt.push_back(A(2, 2));
	lt.push_back(A(3, 3));
	lt.push_back(A(4, 4));
	m_list::list<A>::iterator it = lt.begin();
	// 此时it 模拟的是 自定义类型的指针 我们可以写 it->_al
	while (it != lt.end()) {
		//std::cout << (*it)._a1 << " " << (*it)._a2 << std::endl;
		std::cout << it->_a1 << " " << it->_a2 << std::endl;
		++it;
	}
	std::cout<< std::endl;
}

void test_list3() {
	m_list::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_front(5);
	lt.push_front(6);
	lt.push_front(7);
	lt.push_front(8);
	print(lt);
	lt.pop_front();
	lt.pop_back();
	print(lt);

	lt.clear();
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	print(lt);
	std::cout << lt.size() << std::endl;
}
void test_list4() {
	m_list::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	for (auto& e : lt)
		std::cout << e << " "; std::cout << std::endl;
	m_list::list<int> lt1(lt);
	for (auto& e : lt)
		std::cout << e << " "; std::cout << std::endl;
}
void test_list5() {
	m_list::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	for (auto& e : lt)
		std::cout << e << " "; std::cout << std::endl;
	m_list::list<int> lt2;
	lt2.push_back(3);
	lt2.push_back(4);
	lt2.push_back(5);
	lt2.push_back(6);
	for (auto& e : lt2)
		std::cout << e << " "; std::cout << std::endl;
	lt = lt2;
	for (auto& e : lt)
		std::cout << e << " "; std::cout << std::endl;
	for (auto& e : lt2)
		std::cout << e << " "; std::cout << std::endl;
}
int main() {
	//test_list1();
	//test_list2_insert_erase();
	//test_operator();
	//test_list3();
	//test_list4();
	test_list5();


	return 0;
}