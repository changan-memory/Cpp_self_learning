#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
//using std::cout;
//using std::endl;
//using std::string;
//using std::vector;
//using std::list;
using namespace std;


//test operator[]
void Test_1() {
	string s0;
	string s1("hello world");	//底层是一个字符数组，结尾有一个\0
	cout << s1 << endl;

	//遍历string,使用[]
	//[] 有普通对象重载版本  和  const对象  重载版本
	cout << s1.size() << endl;	// \0不算大小，size是 11,\0是一个标识字符串结束的特殊字符，不算有效字符
	//size计算出的大小为 11,不包括 '\0',因此不会访问到'\0'
	for (size_t i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < s1.size(); ++i) {
		s1[i] += 1;
		cout << s1[i] << " ";
	}

	char s3[] = "hello world";
	//本质区别
	s3[0]++;	//底层: *(s3+0)
	s1[0]++;	//底层: s1.operator[](&s1, 0)
}

//迭代器，暂且理解成像指针一样的东西
void Test_2() {
	string s1("hello world");	//底层是一个字符数组，结尾有一个\0
	string::iterator str_it = s1.begin();
	while (str_it != s1.end()) {
		cout << *str_it;
		++str_it;
	}
	cout << endl;
	
	//迭代器的底层可能是指针，也可能是别的实现
	//范围for配合auto
	//范围for 底层会被替换为迭代器，只要支持迭代器的容器，就支持范围for
	//for (char& ch : s1) {
	for (auto& ch : s1) {
		cout << ch;
	}
	cout << endl;

	//连续的空间才能用[下标]来访问
	//迭代器才是容器主流的访问方式
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(6);
	vector<int>::iterator vit = vec.begin();
	while (vit != vec.end()) {
		cout << *vit << " ";
		vit++;
	}
	cout << endl;
	//任何容器都支持迭代器，并且访问方式类似
	list<int> ls;
	ls.push_back(20);
	ls.push_back(40);
	ls.push_back(60);
	list<int>::iterator lsit = ls.begin();
	while (lsit != ls.end()) {
		cout << *lsit << " ";
		lsit++;
	}
	cout << endl;
	//[]只能用于访问数组结构的容器，但迭代器可以访问任何容器,(树,哈希表等)
	//迭代器跟容器和算法进行配合
	std::reverse(vec.begin(), vec.end());
	std::reverse(ls.begin(), ls.end());
	for (auto& e : vec) {
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : ls) {
		cout << e << " ";
	}
	cout << endl;
	//std::sort(ls.begin(), ls.end());	//不能对链表进行排序
	std::sort(vec.begin(), vec.end());
	for (auto& e : vec) {
		cout << e << " ";
	}
	cout << endl;

}

// 反向迭代器
void Test_3() {
	string s1("hello world");

	//对于类的迭代器类型，auto更加智能
	//string::reverse_iterator rit = s1.rbegin();
	auto rit = s1.rbegin();
	//范围for不能倒着遍历容器，范围for只能使用正向迭代器
	while (rit != s1.rend()) {
		cout << (*rit) << " ";
		++rit;
	}
	cout << endl;
}

// const对象需要用const迭代器
void Test_4(const string& str) {
	//string::reverse_iterator rit = str.rbegin();
	//string::const_reverse_iterator rit = str.rbegin();		//反向迭代器
	// it不是常量，(*it)才是常量
	auto it = str.cbegin();		//const 对象迭代器
	while (it != str.cend()) {
		cout << (*it) << "";
		++it;
	}
	cout << endl;

	//四种迭代器
	// iterator		普通迭代器
	// reverse_itreator		反向迭代器

	// const_iterator	const对象 迭代器
	// const_reverse_itreator		const对象 反向迭代器
}
void test() {
	//Test_1();
	//Test_2();
	//Test_3();
	const string cstring("hello Linux");
	Test_4(cstring);
}

//int main() {
//	//各种迭代器的使用
//	std::string s1("hello Linux");
//	const std::string s2("hello world");
//
//	string::iterator it1 = s1.begin();	//普通对象迭代器
//	string::iterator it2 = s1.end();	//普通对象迭代器
//
//	string::reverse_iterator rit1 = s1.rbegin(); //普通对象反向迭代器
//	string::reverse_iterator rit2 = s1.rbegin(); //普通对象反向迭代器
//
//	string::const_iterator cit1 = s2.begin();	//const对象迭代器
//	string::const_iterator cit2 = s2.end(); 	//const对象迭代器
//
//	string::const_reverse_iterator crit1 = s2.crbegin();	//const对象反向迭代器
//	string::const_reverse_iterator crit2 = s2.crend();	//const对象反向迭代器
//	return 0;
//}