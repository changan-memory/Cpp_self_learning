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
	// 使用 map 统计次数
	void test3_map() {
		// 使用 map 统计水果出现的次数t
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
		"苹果", "香蕉", "苹果", "香蕉" };
		// 模板，任意类型都可以，但是底层，该类型应该支持比较大小
		// 如果一个类不支持比较大小，我们还可以自己写仿函数控制
		map<string, int> countMap;
		for (const auto& e : arr) {
			auto it = countMap.find(e);
			if (it == countMap.end()) {
				countMap.insert(make_pair(e, 1));
			}
			else {
				it->second++;
			}
		}
		for (const auto& e : countMap) {
			cout << e.first << ": " << e.second << endl;
		}
	}
	void test_operator() {
		// map 的 operator[] 的 原理要重点掌握
		map<string, string> dict;
		dict.insert(make_pair("string", "字符串"));
		dict.insert(make_pair("sort", "排序"));
		dict.insert(make_pair("insert", "插入"));

		cout << dict["sort"] << endl;	// 查找 和 读
		// map 的 []  可以做到用 key 修改 value
		dict["map"];					// 插入
		cout << dict["map"] << endl;	// 查找 和 读

		dict["map"] = "映射，地图";		// 修改
		cout << dict["map"] << endl;	// 查找 和 读

		dict["insert"] = "xxx";			// 修改
		cout << dict["insert"] << endl;	// 查找 和 读

		dict["set"] = "集合";			// 插入 + 修改
		cout << dict["set"] << endl;	// 查找 和 读

	}
}

// multimap 可以有多个 相同的key
// 相比 map , multimap 少了 operator[] ，insert的功能也不一样了
// 其他使用基本一样
// 另外 unordered_map 和 unopdered_set 的使用和 map set 的使用一致
// 区别在于 unopdered 容器，底层是用哈希实现的，效率更快
// 但是哈希做不到二叉搜索树的有序遍历，哈希是无序的
namespace test_multimap {

}
int main() {
	//test_map::test1_map();
	//test_map::test2_map();
	//test_map::test3_map();
	test_map::test_operator();
	return 0;
}