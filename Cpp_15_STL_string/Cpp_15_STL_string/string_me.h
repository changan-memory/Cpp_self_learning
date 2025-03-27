#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
using namespace std;

namespace m_string {
	class string {
	public:
		//STL�еĵ�������������ָ�룬Ҳ���ܲ���ָ��
		//string�ĵ�������������char*
		typedef char* iterator;
		typedef const char* const_iterator;
		
		//��ͨ����ĵ�����
		iterator begin() {		
			//return &_str[0];
			return _str;	//�������ǵ�һ��Ԫ�صĵ�ַ
		}
		iterator end() {
			//return &_str[_size];
			return _str+_size;
		}
		//const���������
		const_iterator begin() const {
			return _str;	
		}
		const_iterator end() const {
			return _str + _size;
		}
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
		//string(const char* str = "\0")	//���д�����ý�β������"\0"
		//�ַ����Ľ���λ�ñ�����\0
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
		//����c_str			const ����thisָ��ָ��Ķ��󣬿�������ͨ�����const���󶼿��Ե�
		//�����ڲ��޸Ķ��󣬽������const
		const char* c_str() const {
			return _str;
		}
		//����_size
		size_t size() const {
			return _size;
		}

		char& operator[](size_t pos) {	//�������ã���д�汾
			assert(pos < _size);
			return _str[pos];
		}	//const�����const�汾[]    ��ͨ�������ͨ�汾[]

		const char& operator[](size_t pos) const {	//ֻ���汾
			assert(pos < _size);
			return _str[pos];
		}

		//������reserve��ʵ������
		void reserve(size_t spaceSize) {	//spaceSizeָ�����ַ��ĸ���
			if (spaceSize > _capacity) {
				char* newSpace = new char[spaceSize + 1];	//�࿪һ���ռ���\0
				strcpy(newSpace, _str);
				delete[] _str;
				_str = newSpace;
				_capacity = spaceSize;
			}
		}
		//+=�ı�����push_back�����ʵ��push_back
		void push_back(char ch) {
			//�ȿ�������
			if (_size == _capacity) {
				//��������
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size++] = ch;	//���ַ�
			_str[_size] = '\0';	//����\0
		}
		void append(const char* str) {
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				//�������ݵ�_size + len
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
	};
}