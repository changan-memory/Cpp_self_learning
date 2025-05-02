#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
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

		// ָ�� - ָ�룬���ص�������ָ���м��Ԫ�ظ���
		size_t capacity() const { return _end_of_storage - _start; }
		size_t size() const { return _finish - _start; }

		//[]����
		T& operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const {
			assert(pos < size());
			return _start[pos];
		}

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
				_start = _finish = _end_of_storage = nullptr;
			}
		}
		void reserve(size_t n) {
			// reserve ����ֻ��push_backʹ�ã����ҲҪ��鴫�����ݵĺϷ���
			// ����ʱ ������
			if (n > capacity()) {
				size_t old_sz = size();
				T* tmp = new T[n];		//���ռ�, �������  �ṹ��һ��vector
				// ԭ�ռ䲻Ϊ��ʱ��������
				if (_start) {
					memcpy(tmp, _start, sizeof(T) * old_sz);
					delete[] _start;
				}
				// startָ���¿ռ䣬ָ��finish��Ϊ start ���� 
				_start = tmp;
				// _finish = _start + size(); //���Ǵ���д�����ȼ��� _finsih = _start + _finish - _start
				// ��ʼʱ��_finsih Ϊ nullptr ��� �����finsihΪ��ָ��

				_finish = _start + old_sz;	// ��finsihָ���ԭ�ռ�һ����size��
				_end_of_storage = _start + n;
			}
		}
		
		//resize ��ʼ����val������Ĭ��ֵ(ȱʡ����)�������ȷ��ȱʡ����������
		// ��ʱ T() ������һ��T���͵��������� �������T���͵�Ĭ�Ϲ��죬дһ���࣬һ��Ҫ�ṩĬ�Ϲ���
		// ����� int ���������� resize��ô�ܣ�   �����ϲ�����
		// ����ģ���C++���������ͽ�����������Ҳ֧������������Ĭ�Ϲ��캯��
		void resize(size_t n, const T& val = T()) {
			//�ж�Ҫ������
			if (n < size())		//�ı��С
				_finish = _start + n;
			else {
				reserve(n);
				while (_finish != _start + n) {
					*_finish = val;
					++_finish;
				}
			}
		}

		//T�������������ͣ��Զ������ͻ��������ͣ�����ʹ������
		void push_back(const T& obj) {
			//�������������
			if (_finish == _end_of_storage) {
				//�����¿ռ���Ҫ�Ĵ�С  ���������߼�
				size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);	
				// ����������ݺ�ռ�Ĵ�С
				reserve(newCapacity);			//����ռ�Ĵ�С
			}
			// ���ÿռ�󣬲������ݣ�������_finish
			*_finish = obj;
			++_finish;
			
			//insert(_finish, obj);
			//insert(end(), obj);
		}
		void pop_back() {
			erase(--end());
		}

		////������ʧЧ������
		//void insert(iterator pos, const T& obj) {
		//	assert(pos >= 0 && pos <= _finish);
		//	//�����߼�
		//	if (_finish == _end_of_storage) {
		//		size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);
		//		reserve(newCapacity);			//����ռ�Ĵ�С
		//	}
		//	iterator end = _finish - 1;
		//	while (end > pos) {
		//		*(end + 1) = *end;
		//		--end;
		//	}
		//	*pos = obj;
		//	++_finish;
		//}

		//ʹ��ָ������ƣ�pos������Ϊ0 ������string������������
		//��ָ����� ����ʹ�õĵ�ַ��ר�����ڳ�ʼ��
		iterator insert(iterator pos, const T& obj) {
			assert(pos >= _start && pos <= _finish);	//���pos �� ==finsihʱ Ϊβ��
			//�������������
			//���ݺ����ڿռ����ؿ��ݺ��ͷţ�pos��¼�ĵ�ַ���ܲ����¿��ٿռ�ĵ�ַ����ʱ������ʧЧ
			// ԭ�е�ָ�붼��ʧЧ
			if (_finish == _end_of_storage) {
				//��¼�� pos ����� _start��ƫ�Ƶ�ַ�������ƫ��������posָ��
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
			*pos = obj;
			++_finish;
			return pos;		//���ز���λ�õ�ָ�룬����ⲿ������ʧЧ����
		}
		// ���� pos ����������ֹ������ʧЧ����
		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finish);		//���Խ��,�������ƣ���֤��һ��������
			//ɾ���߼�,�����ݲ���ɾ
			iterator begin = pos + 1;
			//while (begin != _finish) {
			while (begin < _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			//����״̬
			--_finish;
			return pos;
		}

	private:
		//���׼��STL�е�������񱣳�һ��
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}