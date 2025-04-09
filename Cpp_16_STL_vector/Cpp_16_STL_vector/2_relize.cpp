#include "vector.h"
void print(const m_vector::vector<int>& v) {
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}
void testVector1() {
	m_vector::vector<int> v1;
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
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : v1) {
		e++;
	}
	print(v1);
}
void testVector2() {
	m_vector::vector<int> v1;
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
	
	m_vector::vector<int>::iterator p = v1.begin() + 3;
	m_vector::vector<int>::iterator pres = v1.insert(p, 200);
	*p + 200;
	cout << *p << endl;
	//p��¼����ԭ�ռ��ַ�����ԭ�ռ䷢�������ݣ���ôp�ͳ���Ұָ��,������Ұָ����ɵĵ�����ʧЧ
	
	//insert֮�󣬵��������ܻ�ʧЧ(����ʱ������ʧЧ)
	//�Ժ�insert������ʹ���βε���������Ϊinsert�󣬵���������ʧЧ
	//��ȷ�������ǣ�ʹ��insert���صĽ��������ȡpos��ֵ
	//�����Ľӿ��ǲ���ȫ�ģ�
	cout << *pres << endl;
	print(v1);
}
//����ɾ����ͷɾû����
void testVector3() {
	m_vector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);	//����8��Ԫ�أ��ٲ���ʱ�ᴥ�������߼�
	v1.erase(v1.begin());
	v1.erase(v1.begin());
	v1.erase(v1.begin());

	auto it = v1.begin();
	v1.erase(it);	
	cout << *it << endl;
	print(v1);
}
int main() {
	//testVector1();
	//testVector2();
	testVector3();

	return 0;
}