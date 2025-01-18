#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>

//#define TESTADD(x, y) (10*(x+y))	//��ִ�е����ı��滻�� ���ܼӷֺţ� ���ܼ�return  ���ü��β�����
#define ADD(x, y) (10*((x)+(y)))  //ÿ�������������Ǳ��ʽ����ˣ���Ҫ�Ӷ�������

//#define �м� \ ������к꣬ ���߱�������Щ������ͬһ��
#define safe_add(a, b) ({ \
    typeof(a) _a = (a); \
    typeof(b) _b = (b); \
    _a + _b; \
})

void Test_NewFunction() {
	//auto�Զ�����ʶ�� �����ұ߱��ʽ�������Զ��Ƶ�����������
	auto a = 10;
	auto b = 11.11;
	auto c = a;
	auto d = b;
	//�����÷�typeid().name���鿴����
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	//auto���ں���ĳ�����ʶ��ǳ�����
	std::vector<std::string>::iterator it; //������ô��������auto  ʡ������
}

//���ڷ�Χ��forѭ��
//ʹ�������� ��������ķ�Χ������ȷ����
void TestFor(){
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;

	//���������飬��Χfor, �﷨��
	//����ȥ���������ݸ�ֵ�� ele, �Զ������� �Զ��жϽ���
	for (auto ele : array)
		cout << ele << " ";
	cout << endl;
	//���޸�Ԫ�صĻ�������������
	for (auto& ele : array) {	//������ͨcontinue,Ҳ����continue;
		ele *= 2;
		cout << ele << " ";
	}
	//����ʹ��
	/*int* base = (int*)malloc(sizeof(int) * 10);
	for (auto ele : base) {

	}
	1. forѭ�������ķ�Χ������ȷ����
	����������ԣ����������е�һ��Ԫ�غ����һ��Ԫ�صķ�Χ����������ԣ�Ӧ���ṩ
	begin��end�ķ�����begin��end����forѭ�������ķ�Χ��
	ע�⣺���´���������⣬��Ϊfor�ķ�Χ��ȷ��
	void Test(int arrar[]){
		for(auto& ele : array)
			cout<<ele<<endl;
	}
	2. �����Ķ���Ҫʵ��++��==�Ĳ���*/
}
int main() {

	//Test_NewFunction();
	TestFor();
	return 0;
}