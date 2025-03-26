#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

namespace m_string {
	class string {
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	public:
		//���캯��
		//string(const char* str)	//��ʼ���б��ǰ��ճ�Ա���������������Ĵ�����г�ʼ����
		//	:_size(strlen(str))
		//	,_capacity(_size)
		//	,_str(new char[_capacity+1])
		//{
		//	strcpy(_str, str);	//���˵����˳�ʼ���б��˳������׳���
		//}
		
		//��c_str����
		//������ʹ�ó�ʼ���б��ʼ��������Щ���ܳ�ʼ���б���ɲ��ˡ�
		// ���������� ��ʼ���б�/�������� ��ʼ������ν���Զ������;����ڳ�ʼ���б�
		//string(const char* str = '\0')
		//string(const char* str = nullptr)
		//string(const char* str = "\0")
		string(const char* str = "") {
			_size = strlen(str);
			_capacity = _size;	//capacity��ʾ���Դ�ŵ��µ��ַ�����
			_str = new char[_capacity + 1];		//���ռ�
			strcpy(_str, str);	//��������
		}
		//���޲ι���ͨ��ȱʡ�����ϲ�
		//string() {	//����Ĭ�Ϲ���  �޲ε� ȫȱʡ��  ���ǲ�д�������Լ����ɵ�
		//	_str = new char[1];
		//	_size = 0;
		//	_capacity = 0;
		//	_str[0] = '\0';
		//}

		//��������
		~string() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//����c_str
		const char* c_str() {
			return _str;
		}
		
	};
}