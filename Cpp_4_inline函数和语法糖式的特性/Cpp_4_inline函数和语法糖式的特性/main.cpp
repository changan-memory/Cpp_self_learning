#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>



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


//�����и�������Ҫ��ѭ����ִ��10000�Σ� ��ôÿ�ε��ú������Ὠ��ջ֡���н���ջ֡�Ŀ���
// C������ͨ���꺯������������չ�����������������
//#define TESTADD(x, y) (10*(x+y))	//��ִ�е����ı��滻�� ���ܼӷֺţ� ���ܼ�return  ���ü��β�����
#define ADD(x, y) (10*((x)+(y)))  //ÿ�������������Ǳ��ʽ����ˣ���Ҫ�Ӷ�������

//#define �м� \ ������к꣬ ���߱�������Щ������ͬһ��
#define safe_add(a, b) ({ \
    typeof(a) _a = (a); \
    typeof(b) _b = (b); \
    _a + _b; \
})
//�꺯��-----
//�ŵ�      ����Ҫ����ջ֡�� ���Ч��
//ȱ��		���ӣ����׳��� ����Ŀɶ��Բ ���ܵ��ԣ� û�����Ͱ�ȫ�ļ��

//C++�������������������������������
//����ͨ��������ǰ�����  inline �ؼ��֣��ú����ͳ�����������
//������ ��С�ģ���Ƶ�����õĺ������������Ͳ�Ҫʹ�� inline ����չ����
//��� inline ����չ���󣬻�ʹ��ִ�г����������
//inline ���ڱ�������˵��ֻ��һ�����飬 �Ƿ��Ϊ����������ȡ���ڱ�����
//1. �Ƚϳ��ĺ���
//2. �ݹ麯��    ���ᱻ����������Ϊ��������
//Ĭ��debugģʽ�£� ����������Ч�����򲻷��������
inline int Add(int left, int right) {
	return left + right;
}
void Test_inline() {
	for (int i = 0; i < 10000; ++i) {
		cout << Add(i, i + 1) << endl;
	}
}
#include "Func.h"
void Test_Inline() {
	F(2, 3);	//F���������������ж���,Ϊʲô����ʱ����  
	//�������������Ͷ��岻�ܷ��룬 ������������Ҫ��call(û�к�����ַ), ���������ű�����ʱ���Ҳ���
	//�˴�����ʱ��ֻ����������˱�������Ҫȥ�Һ����Ķ��壬�����������Ķ��屻չ���ˣ��Ҳ���
}

//C++�еĿ�ָ��
void f(int) {
	cout << "f(int)" << endl;
}
void f(int*) {
	cout << "f(int*)" << endl;
}
void Test_nullptr() {
	f(0);
	f(NULL);
	f(nullptr);	//��ָ��ؼ���
	cout << sizeof(nullptr) << endl; //8�ֽ�
}
int main() {

	//Test_NewFunction();
	//TestFor();
	//Test_Inline();
	Test_nullptr();
	return 0;
}