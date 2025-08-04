#include <iostream>
using namespace std;
namespace question4 {
	//这里常考一道笔试题：sizeof(Base)是多少？
	class Base {
	public:
		virtual void Func1() {
			cout << "Func1()" << endl;
		}
	private:
		int _b = 1;
	};
	void test() {
		cout << sizeof(Base) << endl;	// 结果为8
	}
}
int main() {
	question4::test();
	return 0;
}