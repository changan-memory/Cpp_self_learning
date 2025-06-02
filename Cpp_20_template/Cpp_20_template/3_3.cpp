 //3. ģ����ػ�   ��ʱ������Ҫ���ĳЩ���ͽ������⻯����
 //ģ����ػ� ���� 
 //�ڸ�ģ���У�ĳЩ������Ҫ���⴦����ҪƵ�����ã�ר��Ϊ�����ͱ�дһ���ض���ģ�庯����ģ����

#include <iostream>
#include <vector>
#include <list>
using namespace std;


// 3.1 ����ģ����ػ�

// ����ģ�� -- ����ƥ��
template<class T>		// 1
bool Less(T left, T right) {
	return left < right;
}

//// ��׼�ĺ���ģ����ػ�   ��д��
//template<>				// 2
//bool Less<int*>(int* left, int* right) {
//	return *left < *right;
//}

// ����ʵû��Ҫ�����������ػ���
// ��ΪҪ�����ػ��ˣ�������ֱ��дһ���µĺ����������������������أ�template<>û��Ҫд��
bool Less(int* left, int* right) {		// 2
	return *left < *right;
}
// ��������û�н�����⣬��Ϊ��ʱֻ�ܽṹint* ,double*��
// ����ʵ��
template<class T>		// 3
bool Less(T* left, T* right) {
	return *left < *right;
}
void test3() {
	// �п��� ���봫��ַ���������յ�ַ�Ĵ�С�ȣ���ֵȥ��
	cout << Less(1, 2) << endl;   // ƥ�� 1
	int a = 1, b = 2;
	cout << Less(&a, &b) << endl;	// ƥ�� 2 
	double c = 1.1, d = 2.2;
	cout << Less(&c, &d) << endl;	 // ƥ�� 3  

}
// ����ģ����Խ����ػ� ��һ��û��Ҫ�ػ�������ͨ������������ʵ��

// 3.2 ��ģ����ػ�
template<class T1, class T2>
class Data {
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
// ��Data����������<int, double>������  ��ģ����ػ�
// ȫ�ػ�
template<>
class Data<int, double> {
public:
	Data() { cout << "Data<int, double>" << endl; }
private:
};

// ƫ�ػ�  ƫ�ػ�  ����  ģ�����
template<class T>
class Data<T, double> {
public:
	Data() { cout << "Data<T, double>" << endl; }
private:
};
// ƫ�ػ�  �����ͽ�һ��������
template<class T1, class T2>
class Data<T1*, T2*> {
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1&, T2&> {
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1&, T2*> {
public:
	Data() { cout << "Data<T1&, T2*>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1*, T2&> {
public:
	Data() { cout << "Data<T1*, T2&>" << endl; }
private:
};
// �������е�һ��ģ���� �� �ػ�������ģ���ֻ࣬��ͨ��ģ�����һ�����⻯�汾
// ���ػ��������࣬��һ���µ����ͣ����ڵĳ�Ա�����ͳ�Ա���������غ�Դ�ౣ��һ��
// �ɸ��� �ػ������ľ������͵����� �����尲��
void test4() {
	// ƫ�ػ�  ƫ�ػ�  ����  ģ�����
	cout << "ƫ�ػ�  ƫ�ػ�����ģ�����" << endl;
	Data<int, int> d1;   // δ�ػ� Data<T1, T2>
	Data<int, double> d2;	// �ػ� Data<int, double>
	Data<Data<int, int>, double> d3;	// �ػ�һ�� Data<T1, T2>  Data<T, double>
	Data<Data<vector<int>, int>, double> d4;	// �ػ����� Data<T1, T2>  Data<T, double>
	// ƫ�ػ�  �����͵Ľ�һ������
	cout << "ƫ�ػ�  �����ͽ�һ������" << endl;
	Data<int*, double*> d5;			// �ػ� Data<T1*, T2*>
	Data<void*, void*> d6;			// �ػ� Data<T1*, T2*>
	Data<int*, double&> d7;			// �ػ� Data<T1*, T2&>
	Data<char&, double&> d8;			// �ػ� Data<T1&, T2&>
	Data<char&, double*> d9;			// �ػ� Data<T1&, T2*>
}

// һ���ڿ����У��ػ����� �ػ�һЩ��С����

//int main() {
//	cout << "ƫ�ػ�  ƫ�ػ�����ģ�����" << endl;
//
//	Data<int, int> d1;   // δ�ػ� Data<T1, T2>
//	Data<int, double> d2;	// �ػ� Data<int, double>
//	Data<Data<int, int>, double> d3;	// �ػ�һ�� Data<T1, T2>  Data<T, double>
//	Data<Data<vector<int>, int>, double> d4;	// �ػ����� Data<T1, T2>  Data<T, double>
//	
//	cout << "ƫ�ػ�  �����ͽ�һ������" << endl;
//	Data<int*, double*> d5;			// �ػ� Data<T1*, T2*>
//	Data<void*, void*> d6;			// �ػ� Data<T1*, T2*>
//	Data<int*, double&> d7;			// �ػ� Data<T1*, T2&>
//	Data<char&, double&> d8;			// �ػ� Data<T1&, T2&>
//	Data<char&, double*> d9;			// �ػ� Data<T1&, T2*>
//	return 0;
//}