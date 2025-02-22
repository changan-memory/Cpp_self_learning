#include <iostream>
#include <string>
using namespace std;

class A {
public:
	A(int a = 0)
		:_a(a)
	{ 
		cout << "A(int a)" << endl;
	}
	~A() {
		cout << "~A()" << endl;
	}
private:
	int _a;
};
class Solution {
public:
	Solution(int x, int y) {
		cout << " Solution(int x, int y)" << endl;
	}
	Solution() {
		cout << " Solution()" << endl;
	}
public:
	int Sum_solution(int n) {
		cout << "Sum_solution()" << endl;
		return n;
	}
};
void push_back(const string& str) {
	cout << "str: " << str << endl;
}
void Test_push_back() {
	string str("1111111");	//����������push
	push_back(str);

	push_back(string("1111111"));	//pushһ����������, ����������г��ԣ�����Ҫ��const����

	push_back("1111111");	//��ʽ����ת������push   ��ʱ����Ҳ���г��ԣ�����Ҫ��const����
}
int main() {
	A aa1(1);	//�������� -- ���������ڵ�ǰ����������
	A(2);		//�������� -- ���������ڵ�ǰ�У����ü�����

	Solution s1;
	s1.Sum_solution(10);	//�����������󣬲����ú���

	Solution(10, 20).Sum_solution(20);	//���Լ�ʵ�ֵĹ��캯��������������
	Solution().Sum_solution(20);	//��Ĭ�Ϲ��캯��������������

	//A& ra = A(1);		//����������г���
	const A& ra = A(1);		//const���ã��ӳ�����������������ڣ����������ڵ�ǰ����������

	return 0;
}