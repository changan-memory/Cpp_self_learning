#include <iostream>
using namespace std;

//���һ������ͳ�Ƶ�ǰ����ʹ�õ�ĳ�������ж��ٸ�
class A {
public:
	A() { 
		++_scount;
	}
	A(const A& t) { 
		++_scount;
	}
	~A() { 
		--_scount; 
	}
	//��̬��Ա���� -- û��thisָ�룬ָ������ͷ����޶����Ϳ��Է���
	static int GetACount() {
		//��̬��Ա���������ܷ������ڵķǾ�̬��Ա����
		return _scount;
	}
private:
	// ��Ա���� -- ����ÿһ������� �洢�ڶ�������
	int _a1 = 1;
	int _a2 = 2;

	// ��̬��Ա���� -- �����࣬���ÿ���������洢�ھ�̬��, �����ó�ʼ���б��ʼ��
//public:
	static int _scount;
};
//ȫ��λ�ã����ⶨ��
int A::_scount = 0;

int main() {

	//cout << __LINE__ <<" " << A::_scount << endl;	//���_scount��public�ģ���ô����ͨ�����������޶���������
	cout << __LINE__ <<" " << A::GetACount() << endl;	

	return 0;
}
