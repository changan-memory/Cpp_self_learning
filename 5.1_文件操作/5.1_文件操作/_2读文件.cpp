#include <fstream>
#include <iostream>
using namespace std;

void test() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "��ʧ��" << endl;
		return;
	}

}





int main() {

	test();
	return 0;
}