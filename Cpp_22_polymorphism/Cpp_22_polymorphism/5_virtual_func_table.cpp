#include <iostream>
using namespace std;
namespace question4 {
	//���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
	class Base {
	public:
		virtual void Func1() {
			cout << "Func1()" << endl;
		}
	private:
		int _b = 1;
	};
	void test() {
		cout << sizeof(Base) << endl;	// ���Ϊ8
	}
}
int main() {
	question4::test();
	return 0;
}