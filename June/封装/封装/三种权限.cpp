#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
class Person 
{
public:
	string my_name;
	string my_gender;
//私有成员和保护成员均不能再类外访问
private:
	int my_money;
	string car;
	
protected:
	string my_wife;
	int password;
};
//int main() {
//	Person p1;
//	system("pause");
//	return 0;
//}
//struct 和 class 的区别在于   默认的访问权限不同
//class 的默认访问权限是 私有  private
//struct 的默认权限是  共有 
//