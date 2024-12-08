#include <iostream>
using namespace std;
#include <string>

class Student {
public:
	//属性
	string _name;
	int _Id;
public:
	//行为
	void Set_Name(string name) {
		_name = name;
	}
	void Set_Id(int id) {
		_Id = id;
	}
	void Show_Stu() {
		cout << "学号 "  << _Id << "  姓名 " << _name << endl;
	}
};

//int main() {
//	
//
//	Student s1;
//	s1.Set_Id(123);
//	s1.Set_Name("wang_tao");
//	s1.Show_Stu();
//	system("pause");
//	return 0;
//}