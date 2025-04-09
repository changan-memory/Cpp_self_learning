#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;


namespace m_vector {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		//��������const������
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }

		//Ĭ�Ϲ��캯��
		//����д���߼��� ����ʱ�ݲ����ռ�
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{ }

		~vector() {
			if (_start) {
				delete[] _start;
				_finish = _start = _end_of_storage = nullptr;
			}
		}
		void reserve(size_t n) {
			// reserve ����ֻ��push_backʹ�ã����ҲҪ���
			if (n > capacity()) {
				size_t old_sz = size();
				T* tmp = new T[n];		//���ռ�,�ṹ��һ��vector
				//ԭ�ռ䲻Ϊ��ʱ��������
				if (_start) {
					memcpy(tmp, _start, sizeof(T) * old_sz);
					delete[] _start;
				}
				// startָ���¿ռ䣬ָ��finish��Ϊ start ���� 
				_start = tmp;
				//_finish = _start + size();	//���Ǵ���д����size = finsih - start
				_finish = _start + old_sz;	//��finsihָ���ԭ�ռ�һ����size��
				_end_of_storage = _start + n;
			}
		}
		//T�������������ͣ��Զ������ͻ��������ͣ�����ʹ������
		void push_back(const T& obj) {
			////�������������
			//if (_finish == _end_of_storage) {
			//	//�����¿ռ���Ҫ�Ĵ�С  ���������߼�
			//	size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);	
			//	// ����������ݺ�ռ�Ĵ�С
			//	reserve(newCapacity);											//����ռ�Ĵ�С
			//}
			//// ���ÿռ�󣬲������ݣ�������_finish
			//*_finish = obj;
			//++_finish;
			
			//insert(_finish, obj);
			insert(end(), obj);
		}

		iterator insert(iterator pos, const T& ele) {
			//���pos
			assert(pos >= _start && pos <= _finish);
			//�������������

			//���ݺ����ڿռ���£�pos��¼�ĵ�ַ���ܲ����¿��ٿռ�ĵ�ַ����ʱ������ʧЧ
			if (_finish == _end_of_storage) {
				//��¼�� pos ����� _start��ƫ�Ƶ�ַ
				size_t len = pos - _start;

				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);

				//���������ʧЧ����, ��¼�±��˵�ַ��������Ǻ����ڲ�������ʧЧ������
				pos = _start + len;
			}
			//�����߼�
			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				--end;
			}
			//���³�Ա�����߼�
			*pos = ele;
			++_finish;
			return pos;		//���ز���λ�õ����ã�����ⲿ������ʧЧ����
		}

		void erase(iterator pos) {
			//���Խ��
			assert(pos >= _start && pos < _finish);
			//ɾ���߼�,�����ݲ���ɾ
			if (_start) {
				iterator begin = pos + 1;
				while (begin != _finish) {
					*(begin - 1) = *begin;
					++begin;
				}
				//����״̬
				--_finish;
			}
		}
		// ָ�� - ָ�룬���ص�������ָ���м��Ԫ�ظ���
		size_t capacity() const { return _end_of_storage - _start; }
		size_t size() const { return _finish - _start; }

		T& operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const{
			assert(pos < size());
			return _start[pos];
		}
	private:
		//���׼��STL�е�������񱣳�һ��
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

}