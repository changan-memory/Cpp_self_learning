#include <vector>
#include <iostream>
using namespace std;

int main() {

	//resize 初始化，val可以有默认值(缺省参数)，但如何确定缺省参数的类型
	// 此时 T() 本质是一个T类型的匿名对象 ，会调用T类型的默认构造，
	// 一般而言，写一个类，一定要提供默认构造
	// 如果是 int 等内置类型 resize怎么跑？   理论上不能跑
	// 有了模板后，C++对内置类型进行了升级，也支持内置类型有默认构造函数
	int i = 1;
	int j = int();	//默认是 0  int 默认是0 double 默认是 0.0  指针默认是nullptr
	int k = int(20);
	cout << i << " " << j << " " << k << endl;
	return 0;
}