#include <iostream>
using namespace std;

class Base {
public:
	virtual void Func1() {
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2() {
		cout << "Base::Func2()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base {
public:
	virtual void Func3() {
		cout << "Derive::Func3()" << endl;
	}
private:
	int _d = 2;
};
// FUNC_PTR�Ǻ���ָ��
typedef void (*FUNC_PTR)();
// ��ӡ���ĺ���
//void printVTB(FUNC_PTR table[]) {		// C������û�к������δ������д���������飬���˻�Ϊָ��
void printVTB(FUNC_PTR* table) {
	for (size_t i = 0; table[i] != nullptr; ++i) {
		printf("[%d]: %p->", i, table[i]);
		FUNC_PTR fptr = table[i];
		fptr();
	}
	printf("\n");
}

//int main() {
//	Base b;
//	Derive d;
//
//	int ptb1 = *((int*)&b);
//	printVTB((FUNC_PTR*)ptb1);
//	int ptb2 = *((int*)&d);
//	printVTB((FUNC_PTR*)ptb2);
//	return 0;
//}

// ��̬
// ��̬(����ʱ)��̬: ��������
// ��̬(����ʱ)��̬: �̳С��麯����д �Ķ�̬
