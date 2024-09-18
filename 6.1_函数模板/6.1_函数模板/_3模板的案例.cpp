//#include <iostream>
//using namespace std;
//
//template<typename T>
//void Swap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
////对一个数组进行排序， char 数组， int 数组 ， double 数组
//template<typename T>	//告诉编译器  要声明一个模板
//void sort_T(T arr[], int size) {
//	int i = 0,j = 0;
//	for (int i = 0; i < size; i++) {
//		int max_index = i;
//		for (j = i + 1; j < size; j++) {
//			if (arr[j] >= arr[max_index]){
//				max_index = j;
//			}
//		}
//		if (max_index != i){
//			Swap(arr[i], arr[max_index]);
//			/*T temp = arr[i];
//			arr[i] = arr[max_index];
//			arr[max_index] = temp;*/
//		}
//	}
//}
//
//template<typename T>
//void print(T arr[], int size) {		//
//	for (int i = 0; i < size; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void test_int() {
//	//数组名作为函数参数的话  是一个指针
//	int arr1[] = { 6, 7, 8, 1, 2, 3 };
//	print(arr1, sizeof(arr1) / sizeof(arr1[0]));
//	sort_T(arr1, sizeof(arr1) / sizeof(arr1[0]));
//	print(arr1, sizeof(arr1) / sizeof(arr1[0]));
//	cout << endl;
//
//}
//void test_char() {
//	char arr2[] = "xyzabc";
//	print(arr2, sizeof(arr2) / sizeof(arr2[0]));
//	sort_T(arr2, sizeof(arr2) / sizeof(arr2[0]));
//	print(arr2, sizeof(arr2) / sizeof(arr2[0]));
//	cout << endl;
//}
//
//void test_double() {
//	double arr3[] = { 2.22, 1.11, 3.33 };
//	print<double>(arr3, sizeof(arr3) / sizeof(arr3[0]));
//	sort_T(arr3, sizeof(arr3) / sizeof(arr3[0]));
//	print<double>(arr3, sizeof(arr3) / sizeof(arr3[0]));
//	cout << endl;
//
//}
//int main() {
//	
//	test_int();
//
//	test_char();
//
//	test_double();
//
//	system("pause");
//	return 0;
//}
//
