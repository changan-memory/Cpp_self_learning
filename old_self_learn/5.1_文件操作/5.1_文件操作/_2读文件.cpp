#include <fstream>		//文件流  是一个类
#include <iostream>
using namespace std;

void test() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}

}





int main() {

	test();
	return 0;
}