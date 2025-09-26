// �ɱ�ģ�����
#include <iostream>
#include <functional>
using namespace std;

//// ����ɱ�ģ����� ���﷨
//template<typename T, typename ...Args>
//void showList(T value, Args... args) {
//	cout << sizeof...(args) << endl;
//}
//
//int main() {
//	showList(1);
//	showList(1, 2);
//	showList(1, 2, 3);
//	return 0;
//}





//// �ݹ鷽ʽ��ȡģ��������е�����
//template<class T>
//void showList(T val) {
//	cout << val << " ";
//	cout << endl;
//}
//template<class T, class ...Args>
//void showList(T value, Args...args) {
//	cout << value << " ";
//	showList(args...);
//}
//
//int main() {
//	showList(1);
//	showList(1, 2.2);
//	showList(1, 2, 3.3);
//	return 0;
//}





//// �ݹ鷽ʽ��ȡģ��������е�����
//template<class T>
//void _showList(T val) {
//	cout << val << " ";
//	cout << endl;
//}
//template<class T, class ...Args>
//void _showList(T value, Args...args) {
//	cout << value << " ";
//	_showList(args...);
//}
//
//template<class ...Args>
//void showList(Args...args) {
//	_showList(args...);
//}
//
//int main() {
//	showList(1);
//	showList(1, 2.2);
//	showList(1, 2, 3.3);
//	return 0;
//}





//// �ݹ鷽ʽ��ȡģ��������е�����
//void _showList();
//
//template<class T>
//void _showList(T val) {
//	cout << val << " ";
//	cout << endl;
//}
//template<class T, class ...Args>
//void _showList(T value, Args...args) {
//	cout << value << " ";
//	_showList(args...);
//}
//template<class ...Args>
//void showList(Args...args) {
//	_showList(args...);
//}
//void _showList() {
//	cout << endl;
//}
//int main() {
//	showList();
//	showList(1);
//	showList(1, 2.2);
//	showList(1, 2, 3.3);
//	return 0;
//}


//// ʹ�ö��ű��ʽ��ȡ�������е�����
//template <class T>
//void PrintArg(T t) {
//	cout << t << " ";
//}
//
////չ������
//template <class ...Args>
//void ShowList(Args... args) {
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}
//int main() {
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}

// ʹ�ö��ű��ʽ�ļ�д��
template <class T>
int PrintArg(T t) {
	cout << t << " ";
	return 0;
}

//չ������
template <class ...Args>
void ShowList(Args... args) {
	int arr[] = { PrintArg(args)... };
	cout << endl;
}
//int main() {
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}
