#include <iostream>
//#include <set>  // key ������ģ��
#include <map>  // key/value ������ģ��
#include <string>
using namespace std;

// map�������޸ļ����������޸�value
// map��keyҲ����������
namespace test_map {
	// pair �Ļ���ʵ��
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
		pair<string, string> kv1("insert", "����");	// const char* ������ʽ����ת��
		dict.insert(kv1);
		dict.insert(pair<string, string>("sort", "����"));	// ������������ 2
		// pair �����ṩ��make_pair����������һ��pair����
		dict.insert(make_pair("string", "�ַ���"));		// �ص�����

		// C++11֧�ֶ�����Ĺ��캯����ʽ����ת��
		dict.insert({ "int", "��������" });	// �ص����� ��������pair�Ĺ��캯�� �ȼ��� 2 ��д��
		// ��ʽ����ת�� ���� + �Ż�
		string str = "hello";
		pair<string, string> kv2 = { "string", "�ַ���" };
	}
	// ����
	void test2_map() {
		map<string, string> dict;
		pair<string, string> kv1("insert", "����");	// const char* ������ʽ����ת��
		dict.insert(kv1);
		dict.insert(pair<string, string>("sort", "����"));	// ������������ 2
		dict.insert(make_pair("string", "�ַ���"));		// �ص�����

		// key ��ͬ ��value��ͬʱ�������룬������
		// ��ӳ�� STL��Ƶģ���������У�ֻ�Ƚ�key, value�಻��ͬ����ν
		// key �Ѿ�����ʱ���Ͳ�������
		dict.insert(make_pair("string", "string"));	

		map<string, string>::iterator it = dict.begin();
		// pair ��ʵ�֣�û������<<�����
		while (it != dict.end()) {
			//it->first = "xxx";  // key�����޸�
			//it->second = "xxx";		// value �����޸�
			//cout << (*it).first << " " << (*it).second << endl;
			cout << it->first << " " << it->second << endl;
			//cout << it->->first << " " << it->->second << endl;
			// operator->���ص���һ��ָ��,����˵Ӧ��it->->�������ݣ����˴������������Ż�
			++it;
		}
		for (const auto& kv : dict) {
			cout << kv.first << " : " << kv.second << endl;
		}
	}
	// ʹ�� map ͳ�ƴ���
	void test3_map() {
		// ʹ�� map ͳ��ˮ�����ֵĴ���t
		string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
		"ƻ��", "�㽶", "ƻ��", "�㽶" };
		// ģ�壬�������Ͷ����ԣ����ǵײ㣬������Ӧ��֧�ֱȽϴ�С
		// ���һ���಻֧�ֱȽϴ�С�����ǻ������Լ�д�º�������
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
		// map �� operator[] �� ԭ��Ҫ�ص�����
		map<string, string> dict;
		dict.insert(make_pair("string", "�ַ���"));
		dict.insert(make_pair("sort", "����"));
		dict.insert(make_pair("insert", "����"));

		cout << dict["sort"] << endl;	// ���� �� ��
		// map �� []  ���������� key �޸� value
		dict["map"];					// ����
		cout << dict["map"] << endl;	// ���� �� ��

		dict["map"] = "ӳ�䣬��ͼ";		// �޸�
		cout << dict["map"] << endl;	// ���� �� ��

		dict["insert"] = "xxx";			// �޸�
		cout << dict["insert"] << endl;	// ���� �� ��

		dict["set"] = "����";			// ���� + �޸�
		cout << dict["set"] << endl;	// ���� �� ��

	}
}

// multimap �����ж�� ��ͬ��key
// ��� map , multimap ���� operator[] ��insert�Ĺ���Ҳ��һ����
// ����ʹ�û���һ��
// ���� unordered_map �� unopdered_set ��ʹ�ú� map set ��ʹ��һ��
// �������� unopdered �������ײ����ù�ϣʵ�ֵģ�Ч�ʸ���
// ���ǹ�ϣ�����������������������������ϣ�������
namespace test_multimap {

}
int main() {
	//test_map::test1_map();
	//test_map::test2_map();
	//test_map::test3_map();
	test_map::test_operator();
	return 0;
}