#include <vector>
#include <iostream>
using namespace std;

int main() {

	//resize ��ʼ����val������Ĭ��ֵ(ȱʡ����)�������ȷ��ȱʡ����������
	// ��ʱ T() ������һ��T���͵��������� �������T���͵�Ĭ�Ϲ��죬
	// һ����ԣ�дһ���࣬һ��Ҫ�ṩĬ�Ϲ���
	// ����� int ���������� resize��ô�ܣ�   �����ϲ�����
	// ����ģ���C++���������ͽ�����������Ҳ֧������������Ĭ�Ϲ��캯��
	int i = 1;
	int j = int();	//Ĭ���� 0  int Ĭ����0 double Ĭ���� 0.0  ָ��Ĭ����nullptr
	int k = int(20);
	cout << i << " " << j << " " << k << endl;
	return 0;
}