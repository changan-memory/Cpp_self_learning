#include <iostream>
using namespace std;
#include <string>

class Student {
public:
	//����
	string _name;
	int _Id;
public:
	//��Ϊ
	void Set_Name(string name) {
		_name = name;
	}
	void Set_Id(int id) {
		_Id = id;
	}
	void Show_Stu() {
		cout << "ѧ�� "  << _Id << "  ���� " << _name << endl;
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