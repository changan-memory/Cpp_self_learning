#include <iostream>

#include <set>  // key ������ģ��
//#include <map>  // key/value ������ģ��
using namespace std;

// set��������������� �ﵽ��Ч���� ȥ�� + ˳������
// multiset ��������ݣ������ֵ�ظ���
// set ��iterator ���� const_iterator  ��� set�� iterator ���� const_iterator
// set �ļ�ֵ�������޸�
namespace test_set {
	void test1_set() {
		// set �����ȥ��
		set<int> s1;
		s1.insert(3);
		s1.insert(2);
		s1.insert(4);
		s1.insert(5);
		s1.insert(1);
		s1.insert(3);	// ������ͬ��Ԫ��ʱ��������
		set<int>::iterator it = s1.begin();
		// ʹ�õ�����˳�����ʱ��Ĭ���ߵ��������������˽���������
		while (it != s1.end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;
		// ��Χfor����
		for (auto e : s1) {
			cout << e << " ";
		}
		cout << endl;

		// ɾ��ָ��λ��
		auto pos = s1.find(3);	 // ���ڵ� find ��ƽ��Ķ������������� O(logN)  
		if (pos != s1.end())
			s1.erase(pos);
		//auto pos = find(s1.begin(), s1.end(), 3);	// �㷨���е� find �������� O(N)
		// ɾ��ָ����ֵ
		s1.erase(1);
		for (auto e : s1) {
			cout << e << " ";
		}
		cout << endl;
		if (s1.count(5)) {
			cout << "�ҵ���" << endl;
		}
	}
	void test2_set() {
		// �ұ߽�
		std::set<int> myset;
		std::set<int>::iterator itlow, itup;

		for (int i = 1; i < 10; i++) myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
		std::cout << "myset contains:";
		for (auto e : myset) {
			cout << e << " ";
		}
		cout << endl;
		// �Ҵ���ֵ�ı߽�
		// �������� [30, 60] ����ɾ��
		itlow = myset.lower_bound(30);                //   �� >= 30 ���Ǹ�ֵ  itlow��30��λ��
		itup = myset.upper_bound(60);                 //   �� > 60 ���Ǹ�ֵ   itup��70��λ��
		// ��ô�����Ϊ�����erase ������ҿ�
		cout << *itlow << " " << *itup << endl;
		// ɾ������ [itlow, itup)
		myset.erase(itlow, itup);                     // 10 20 70 80 90

		std::cout << "myset contains:";
		for (auto e : myset) {
			cout << e << " ";
		}
		cout << endl;
	}
	void test3_set() {
		std::set<int> myset;

		for (int i = 1; i <= 5; i++) myset.insert(i * 10);   // myset: 10 20 30 40 50

		//std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
		auto ret = myset.equal_range(30);
		// ret �������� pair<iterator, itrator> 
		// equal_range(30) ���ص��� 30 ������ҿ������� [30, 40) 
		std::cout << "the lower bound points to: " << *ret.first << '\n';
		std::cout << "the upper bound points to: " << *ret.second << '\n';
	}
}
// set��������������� �ﵽ��Ч���� ȥ�� + ˳������
// multiset ��������ݣ������ֵ�ظ���
// count �� equal_range ����Ϊ multiset��Ƶ�
namespace test_multiset {
	void test1_multiset() {
		multiset<int> mset;		// multiset �����ֵ����
		mset.insert(3);
		mset.insert(5);
		mset.insert(8);
		mset.insert(7);
		mset.insert(7);
		mset.insert(9);
		mset.insert(7);
		for (auto e : mset) {
			cout << e << " ";
		}
		cout << endl;
		cout << "count of number 7 is:" << mset.count(7) << endl;
		// ɾ�����������е�7
		//std::pair<std::multiset<int>::const_iterator, std::multiset<int>::const_iterator> ret = mset.equal_range(7);
		auto ret = mset.equal_range(7);
		// ret ���Ƶ�Ϊ�� pair<std::set<int>::iterator,std::set<int>::iterator>
		// ��Ҫԭ������ std::multiset����ײ�ʵ����ͨ������ std::set�ĵ���������
		// ���������ر��� MSVC�����ڲ����Ͷ�����ʹ���˱���
		cout << *ret.first << endl;
		cout << *ret.second << endl;
		// equal_range(7)  �ķ���ֵ ret ����һ�����������䣬
		// �ֱ�ָ���һ��7��λ�ú� ���һ��7����һ��λ��(����ʱ���������еģ���˶��7�ǰ��ŵ�)
		mset.erase(ret.first, ret.second);
		for (auto e : mset) {
			cout << e << " ";
		}
		cout << endl;
	}
	void test2_multiset() {
		multiset<int> mset;		// multiset �����ֵ����
		mset.insert(3);
		mset.insert(5);
		mset.insert(8);
		mset.insert(7);
		mset.insert(7);
		mset.insert(9);
		mset.insert(7);
		for (auto e : mset) {
			cout << e << " ";
		}
		cout << endl;
		// �ж��7ʱ��find���ص��� �������ʱ �ĵ�һ��7 ��λ��
		// ���û�ҵ������ص���һ��������
		// ����7ÿ�ҵ�������
		auto pos = mset.find(7);
		while (pos != mset.end()) {
			cout << *pos << " ";
			pos++;
		}
		cout << endl;
		for (auto e : mset) {
			cout << e << " ";
		}
		cout << endl;
	}
}
//int main() {
//	//test_set::test2_set();
//	//test_set::test3_set();
//	//test_multiset::test1_multiset();
//	test_multiset::test2_multiset();
//	return 0;
//}