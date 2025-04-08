#include "vector.h"
void print(const m_vector::vector<int>& v) {
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}
void testVector1() {
	m_vector::vector<int> v1;
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
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : v1) {
		e++;
	}
	print(v1);
}
void testVector2() {
	m_vector::vector<int> v1;
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
	
	m_vector::vector<int>::iterator p = v1.begin() + 3;
	m_vector::vector<int>::iterator pres = v1.insert(p, 200);
	*p + 200;
	cout << *p << endl;
	//p记录的是原空间地址，如果原空间发生了扩容，那么p就成了野指针,这里是野指针造成的迭代器失效
	
	//insert之后，迭代器可能会失效(扩容时迭代器失效)
	//以后insert尽量不使用形参迭代器，因为insert后，迭代器可能失效
	//正确的做法是，使用insert返回的结果当来获取pos的值
	cout << *pres << endl;
	print(v1);
}
int main() {
	//testVector1();
	testVector2();

	return 0;
}