#include <iostream>
using namespace std;
#include <assert.h>

void Test_new(){
	// ���ַ�ʽ���ǿ��ռ䣬������ʼ��
	// malloc free�Ǻ�����new delete �ǲ�����
	//C
	int* p1 = (int*)malloc(sizeof(int));
	free(p1);
	//Cpp	// new + ����
	int* p2 = new int;
	delete p2;

	//�� 10��int�� ����
	//C
	int* p3 = (int*)malloc(sizeof(int) * 10);

	//Cpp	������10��int��һ��ռ�
	int* p4 = new int[10];	//���鲻�ܳ�ʼ��
	delete[] p4;
	//����һ�� int ,��ʼ��Ϊ 10
	int* p5 = new int(10);	//Բ���� �ǳ�ʼ��
	delete p5;
	// new ����ʱ��ʼ��
	//int* p6 = new int[10](0);		//���鲻����()����ʼ��
	int* p6 = new int[10] {1, 2, 3};
	delete[] p6;
}
struct ListNode {
	int _data;
	struct ListNode* _next;
	ListNode(int data = 0)
		:_data(data)
		,_next(nullptr)
	{ }
};
struct ListNode* BuyNode(int data) {
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	//���
	assert(newNode);
	newNode->_data = data;
	newNode->_next = NULL;
	return newNode;
}
void TestList() {
	//C���Ե�д��
	struct ListNode* n1 = BuyNode(1);
	struct ListNode* n2 = BuyNode(2);
	struct ListNode* n3 = BuyNode(3);

	//C++��д����ʹ��newʱ���Ե��ù��캯��
	struct ListNode* nn1 = new ListNode(1);
	struct ListNode* nn2 = new ListNode(2);
	struct ListNode* nn3 = new ListNode(3);
	return;
}
void Test_new_1() {
	//��һ��int
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;

	//������10��int��һ��ռ�
	int* p3 = (int*)malloc(sizeof(int) * 10);
	int* p4 = new int[10];	//int* p4 = new int[10](0);		//���鲻����()����ʼ��
	//����һ�� int ,��ʼ��Ϊ 10
	int* p5 = new int(10);	//Բ���� 

	// new ����ʱ��ʼ��
	int* p6 = new int[10] {1, 2, 3};

	free(p1);
	delete p2;
	free(p3);
	delete[] p4;
	delete p5;
	delete[] p6;
}
//int main() {
//	Test_new_1();
//	return 0;
//}






//class MyClass {
//public:
//	MyClass(int init_value)
//		: _value1(init_value)   // ���е�����˳�������ʼ��˳��
//		, _value2(_value1)  // _value2�������������� _value1 ��ʼ�� _value2
//		// ��ʱ _value1 ��δ��ɳ�ʼ���������ֵ
//	{
//	}
//	void Print() const {
//		cout << "_value1: " << _value1
//			<< "  _value2: " << _value2 << endl;
//	}
//private:
//	int _value2;
//	int _value1;
//};
//int main() {
//	MyClass obj(5);
//	obj.Print();  // �����_value1: 5  _value2: ���ֵ
//	return 0;
//}