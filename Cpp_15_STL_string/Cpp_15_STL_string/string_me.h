#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

namespace string_me {

	class string {
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		//��ʼ���б��ǰ��ձ���������  ������˳�� ��ʼ����
		string(const char* str)
			//:_str(str)	//����д��Ȩ�޵ķŴ�
			:_str(new char[strlen(str)+1])
			,_size(strlen(str))
			,_capacity(strlen(str))
		{
			strcpy(_str, str);
		}
	};
}