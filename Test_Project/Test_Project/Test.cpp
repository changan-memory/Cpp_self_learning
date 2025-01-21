#include <iostream>
int main(){
	int a;
	double b;
	char c;

	// 可以自动识别变量的类型
	std::cin >> a;
	std::cin >> b >> c;
	std::cout <<std::endl<< a << std::endl;
	std::cout << b << " " << c << std::endl;
	return 0;
}
