#include <iostream>
//#include <set>  // key 的搜索模型
#include <map>  // key/value 的搜索模型
#include <string>
using namespace std;

// map不允许修改键，但允许修改value
// map的key也不允许冗余
namespace test_map {
	// pair 的基本实现
	/*template <class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;
		pair() : first(T1()), second(T2())
		{
		}
		pair(const T1& a, const T2& b) : first(a), second(b)
		{
		}
	};*/

	void test1_map() {
		map<string, string> dict;
		//	typedef pair<const key_type, mapped_type> value_type
		pair<string, string> kv1("insert", "插入");	// const char* 会有隐式类型转换
		dict.insert(kv1);
		dict.insert(pair<string, string>("sort", "排序"));	// 构造匿名对象 2
		// pair 类中提供了make_pair函数，返回一个pair对象
		dict.insert(make_pair("string", "字符串"));		// 重点掌握

		// C++11支持多参数的构造函数隐式类型转换
		dict.insert({ "int", "整型数字" });	// 重点掌握 这里会调用pair的构造函数 等价于 2 的写法
		// 隐式类型转换 构造 + 优化
		string str = "hello";
		pair<string, string> kv2 = { "string", "字符串" };
	}
	// 遍历
	void test2_map() {
		map<string, string> dict;
		pair<string, string> kv1("insert", "插入");	// const char* 会有隐式类型转换
		dict.insert(kv1);
		dict.insert(pair<string, string>("sort", "排序"));	// 构造匿名对象 2
		dict.insert(make_pair("string", "字符串"));		// 重点掌握

		// key 相同 但value不同时，不插入，不覆盖
		// 反映出 STL设计的，插入过程中，只比较key, value相不相同无所谓
		// key 已经存在时，就不插入了
		dict.insert(make_pair("string", "string"));	

		map<string, string>::iterator it = dict.begin();
		// pair 的实现，没有重载<<运算符
		while (it != dict.end()) {
			//it->first = "xxx";  // key不能修改
			//it->second = "xxx";		// value 可以修改
			//cout << (*it).first << " " << (*it).second << endl;
			cout << it->first << " " << it->second << endl;
			//cout << it->->first << " " << it->->second << endl;
			// operator->返回的是一个指针,按理说应该it->->访问数据，但此处编译器做了优化
			++it;
		}
		for (const auto& kv : dict) {
			cout << kv.first << " : " << kv.second << endl;
		}
	}
}

namespace test_multimap {

}
int main() {
	//test_map::test1_map();
	test_map::test2_map();
	return 0;
}