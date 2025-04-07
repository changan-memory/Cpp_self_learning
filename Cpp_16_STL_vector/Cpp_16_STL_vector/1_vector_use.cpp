#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

void Test_v1() {
	//�û���ֱ��ʹ��vector�����ֱ���
	vector<int> v1;		//�չ���
	v1.push_back(2);	//β��
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	//ʹ��[]���size����
	for (int i = 0; i < v1.size(); ++i) {
		cout << v1[i] << " ";
	}
	cout << endl;
	//����������
	vector<int>::iterator it = v1.begin();
	while (it != v1.end()) {
		cout << *it <<" ";
		++it;
	}
	cout << endl;
	//��Χfor����
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
}

void Test_v2() {
	//vector<char> strV;	//vector<char>�ܷ���� string ?
	//���ǲ���
	// string Ҫ������� '\0' ,���Ը��õļ���C����
	//string�Ľӿڸ��ӷḻ���и���ר�õĽӿ� ��  += �ַ����Ƚϴ�С������

	// string ��


	//�������Ĺ��캯��  ֧����ʽ����ת��
	//vectorҲ���Դ�string
	vector<string> strV;
	//����һ��string�����ڴ洢
	string name1("����");
	strV.push_back(name1);
	//�������������
	strV.push_back(string("����"));
	//��ʽ����ת��
	strV.push_back("����");
}

void Test_v3() {
	//1. ��n����ͬ��value��ʼ������һ�������Ǹ������ڶ���������value
	vector<int> v1(10, 1);	
	vector<string> v2(5, "***");
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : v2) {
		cout << e << " ";
	}
	cout << endl;

	//2. ������(����)�����ĵ��������г�ʼ��
	vector<int> v3(v1.begin(), v1.end());
	for (auto& e : v3) {
		cout << e << " ";
	}
	cout << endl;

	//3. ���������͵ĵ�������ʼ��
	string str("hello world");
	vector<char> v4(str.begin(), str.end());
	for (auto& e : v4) {
		cout << e << " ";
	}
	cout << endl;
	
	//4. ��C���Է���������г�ʼ��
	int arr[] = { 66, 77, 12, 39, 6, 2};	
		//�����ĵ�������endָ��������һ��Ԫ�ص���һ��λ��
	vector<int> v5(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto& e : v5) {
		cout << e << " ";
	}
	cout << endl;

	//��������㷨��
	//���� less   sortĬ��������
	sort(v5.begin(), v5.end());
	for (auto& e : v5) {
		cout << e << " ";
	}
	cout << endl;

	//�Ž�������ַ���
	sort(v5.begin(), v5.end(), greater<int>());	//1. ʹ��sort�����ذ汾
	for (auto& e : v5) {
		cout << e << " ";
	}
	cout << endl;

	//sort(v5.end(), v5.begin());	//�������ᵼ������Խ��
	sort(v5.rbegin(), v5.rend());					//2. ���򴫵�����
	for (auto& e : v5) {
		cout << e << " ";
	}
	cout << endl;

	sort(v4.begin(), v4.end());		//sort���Դ�  ����ʵ���˵����� ������				
	for (auto& e : v4) {
		cout << e << " ";
	}
	cout << endl;
}
void Test_v4() {
	//resize �� reserve
	vector<int> v1;
	v1.reserve(10);		//reserve�ı����capacity,��Ϊ��,������size
	for (size_t i = 0; i < 10; ++i) {	//����ֱ�ӵ� i<10
		//v1[i] = i;	//��[]+�±���ʻ��������Խ����,capacity�Ĵ�С������size�Ĵ�С
		//һ��size��capacityҪС��[]����ʱ�����ܷ���size֮�������
		v1.push_back(i);	//�����β��
	}
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
}

void Test_v5() {
	//��C���Է���������г�ʼ��
	int arr[] = { 66, 77, 12, 3, 3, 3, 3, 39, 6, 2 };
	//�����ĵ�������endָ��������һ��Ԫ�ص���һ��λ��
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;

	//β���βɾ
	v1.push_back(12);
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
	v1.pop_back();
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;

	//���� insert �� erase ʵ��ͷ���ͷɾ  insert  �ڴ����λ��֮ǰ����
	v1.insert(v1.begin()+1, 100);	//������ϼӼ���ʵ������λ�õĲ���
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
	//ɾ����һ��Ԫ��
	v1.erase(v1.begin());
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;
}
void Test_v7() {
	//��C���Է���������г�ʼ��
	int arr[] = { 66, 77, 12, 3, 39, 6, 3, 2, 3, 3};
	//�����ĵ�������endָ��������һ��Ԫ�ص���һ��λ��
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;

	//����㷨���е�find��ɾ�������е�ָ��Ԫ�� 
	// find ���ض�Ӧ�±�ĵ�����������Ҳ��������� ������end
	//����дɾ������ �����е� ��һ��ƥ���Ԫ��
	vector<int> ::iterator pos = find(v1.begin(), v1.end(), 3);
	if (pos != v1.end()) {
		v1.erase(pos);
	}
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;

	//ɾ�����������е� 3 ����
	//������漰������ʧЧ������  --  �ײ�ʵ��ʱҪ���
	vector<int> ::iterator pos_1 = std::find(v2.begin(), v2.end(), 3);
	while (pos_1 != v2.end()) {
		vector<int>::iterator pos_tmp;
		v1.erase(pos_1);
		//pos_1 = std::find(pos_1+1, v2.end(), 3);  //����д�漰������ʧЧ
		pos_tmp = std::find(v2.begin(), v2.end(), 3);	//�����ٴ�ͷ��ʼ�ң���Ч�ʱȽϵ�
	}
	for (auto& e : v2) {
		cout << e << " ";
	}
	cout << endl;

}

//int main() {
//	//Test_v1();
//	//Test_v2();
//	//Test_v3();
//	//Test_v4();
//	Test_v5();
//	//Test_v7();
//	return 0;
//}

namespace test {
	class A {
		int _a;
	public:
		A(int a)
			:_a(a)
		{ }
	};
	int main() {
		A a1(1);	//�������Ĺ��캯��֧����ʽ����ת��
		A a2 = 1;
		return 0;
	}
}