#include "vector_review.h"

void print(const mm_vector::vector<int>& v) {
	//��Χfor ��ͨ����ת��������ͨ������  const����ת������const������
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}
void testVector1() {
	mm_vector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(22);
	v1.push_back(33);
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;

	for (auto& e : v1)
		++e;
	print(v1);

	for (int i = 0; i < v1.size(); ++i)
		++v1[i];
	print(v1);
}
void testVector2() {
	mm_vector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);	//����8��Ԫ�أ��ٲ���ʱ�ᴥ�������߼�
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;

	// �ڵ�����λ�ò���
	// �� insert�ڲ��޸� pos ��ֵ����������ڲ��ĵ�����ʧЧ����
	// �ⲿ�ĵ��������� insert ���β� pos ��ֵ���ݴ�������pos���޸Ĳ���ı�p��ֵ������޷����pʧЧ������
	// Ҳ���ܽ� insert �Ĳ��� pos ��Ϊ ���û�const ���ã�����insert�߼��޷�ʵ��
	// insert ֮�󣬵��������ܻ�ʧЧ�����ݾͻ����������ʧЧ��
	// ����ͬƽ̨�����ݻ��Ʋ�һ���������޷�Ԥ��������ʧЧ��ʱ����
	// ��˼�ס��insert֮��Ҫʹ�� �����ʵ�ε�������   ����������Ϊ insert֮�� ����������ʧЧ
	mm_vector::vector<int>::iterator p = v1.begin() + 3;
	v1.insert(p, 300);
	print(v1);

	// 300 ����󣬵�����p�Ѿ�ʧЧ�ˣ���pλ�����޸ģ��޸�ʧ��
	*p += 10;	//���ݺ�    
	print(v1);
	//m_vector::vector<int>::iterator pres = v1.insert(p, 200);

	//*p + 200;
	cout << *p << endl;
	//p��¼����ԭ�ռ��ַ�����ԭ�ռ䷢�������ݣ�ԭ�ռ�ĵ�ַ�ᷢ���ı�
	// ��ôp�ͳ���Ұָ��, ������Ұָ����ɵĵ�����ʧЧ

	////insert֮�󣬵����� �п��ܻ�ʧЧ(��Ҫ���ڷ��� ����ʱ ������ʧЧ)������ͬƽ̨�����ݲ��Բ�ͬ�����Ա���
	//// insert ֮��Ͳ�Ҫʹ������βε������ˣ���Ϊinsert�󣬵���������ʧЧ
	////��ȷ�������ǣ�ʹ��insert���صĽ��������ȡpos��ֵ
	////�����Ľӿ��ǲ���ȫ�ģ����  ֱ����Ϊ insert�󣬵�����ʧЧ��
	////cout << *pres << endl;
	//print(v1);
}


//����ɾ����ͷɾû����
void testVector3() {
	mm_vector::vector<int> v1;
	//std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;
	/*v1.erase(v1.begin());
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;*/

	// �޸ĺ�������
	auto it = v1.begin();
	while (it != v1.end()) {
		if (*it % 2 == 0)
			it = v1.erase(it);
		//v1.erase(it);
		else
			++it;
	}
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;

	// Ҳ��Ϊ erase �������ʧЧ, ���ܷ���
	// vs�»����ǿ�Ƽ�飬���ʻᱨ��
	//auto it = v1.begin() + 3;
	//v1.erase(it);
	//cout << *it << endl;
	//++it;
	//cout << *it << endl;
	//print(v1);
	//// g++��ʵ�ֵ�erase��ɾ��ʱҲ�ǲ�Ĩ�����ݵ�
	// ���ǵ�ƽ̨�Ŀ���ֲ�ԣ���ΪeraseҲ�������ʧЧ

	// ����һЩƽ̨�����ϵ�ɾ�����ݣ�ɾ��ֻʣԭ�����ݵ�һ��ʱ���е�ƽ̨���������
	// ����һ�㶼��������ݣ���ôerase��Ҳ����ֵ�����ʧЧ
}

void testVector4() {
	mm_vector::vector<int> v(3, 6);
	v.resize(10, 2);

	//resize ��ʼ����val������Ĭ��ֵ(ȱʡ����)�������ȷ��ȱʡ����������
	// ��ʱ T() ������һ��T���͵��������� �������T���͵�Ĭ�Ϲ��죬
	// һ����ԣ�дһ���࣬һ��Ҫ�ṩĬ�Ϲ���
	// ����� int ���������� resize��ô�ܣ�   �����ϲ�����
	// ����ģ���C++���������ͽ�����������Ҳ֧������������Ĭ�Ϲ��캯��
	int i = 0;
	int j = int();	//Ĭ���� 0  int Ĭ����0 double Ĭ���� 0.0  ָ��Ĭ����nullptr
	int k = int(20);
	cout << i << " " << j << " " << k << endl;

	for (auto& e : v)
		cout << e << " ";
	cout << endl;
}

//void testVector5() {
//	m_vector::vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	m_vector::vector<int> v1(v);	//ǳ������ͬһ��ռ���������Σ����Ҫʵ�����
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//
//	m_vector::vector<int> v2;
//	v2.resize(10, 3);
//	v1 = v2;
//	v2 = v2;
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//}
//
//void testVector6() {
//	m_vector::vector<string> v;
//	//�������Ĺ��캯��֧����ʽ����ת��
//	v.push_back("111111111111111111");		// const char* ������ʽ����ת��Ϊstring
//	v.push_back("222222222222222222");
//	v.push_back("333333333333333333");
//	v.push_back("444444444444444444");
//	v.push_back("555555555555555555");
//	for (auto& e : v)	//��Χfor�ĵײ���ȡ��������*it ��ֵ�� e ,����Զ����������Ҫ������
//		cout << e << " ";
//	cout << endl;
//	m_vector::vector<string> v1(v);		//������������õ�Ҳ��memcpy����ô��stringʱҲ�����
//	for (auto& e : v1)
//		cout << e << " ";
//}
//
//void testVector7() {
//	m_vector::vector<int> v1(10, 1);
//	m_vector::vector<int> v2(10, 1);
//	m_vector::vector<string> v3(10, "hello");
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//	for (auto& e : v3)
//		cout << e << " ";
//	cout << endl;
//}

int main() {
	//testVector1();
	//testVector2();
	//testVector3();
	testVector4();
	//testVector5();
	//testVector6();
	//testVector7();

	return 0;
}

//int main() {
//
//	int i = 0;
//	int j = int();	// ���� int ��Ĭ�Ϲ����� 0
//	int k = int(20);	// �� 20 ���й���
//	cout << i << " " << j << " " << k << endl;
//	return 0;
//}