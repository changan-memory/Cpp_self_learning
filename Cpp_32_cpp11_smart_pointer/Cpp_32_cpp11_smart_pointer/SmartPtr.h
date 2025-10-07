#pragma once

namespace m_SmartPtr {
	// auto_ptr ģ��ʵ��
	template<class T>
	class auto_ptr {
	private:
		T* _ptr; // ָ�����Ķ�̬��Դ����: new����Ķ���

	public:
		// 1. ���캯���������ⲿnew����Դָ�룬�ӹ�����Ȩ
		auto_ptr(T* ptr)
			: _ptr(ptr)
		{ }

		// 2. ������������auto_ptr�����������ڽ���ʱ���Զ��ͷŹ������Դ
		~auto_ptr()
		{
			if (_ptr)  // ȷ��ָ��ǿգ������ظ��ͷ�
			{
				//1.��ʾ�ͷŵĵ�ַ
				cout << "delete:" << _ptr << endl;

				//2.�ͷŶ�̬��Դ
				delete _ptr;

				//3.ָ���ÿձ���Ұָ��
				_ptr = nullptr;
			}
		}

		// 3. �������캯�� ---> ����"����Ȩת��"���� ---> ԭ�����ʧȥ��Դ����Ȩ����Ϊ����ָ��
		auto_ptr(auto_ptr<T>& sp)
			: _ptr(sp._ptr)     //1.�¶���ӹ�ԭ�������Դ
		{
			sp._ptr = nullptr;  //2.ԭ����ָ���ÿգ�ʧȥ����Ȩ
		}

		// 4. ������ֵ����� ---> ����"����Ȩת��"����
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			//1.����Ը�ֵ�Ա����Լ���ֵ���Լ����µĴ���
			if (this != &ap)
			{
				//��һ�������ͷŵ�ǰ��Դ
				if (_ptr)
				{
					delete _ptr;
					_ptr = nullptr;
				}

				//�ڶ������ٽӹ�����Դ
				_ptr = ap._ptr;  //�ӹ�ap����Դ

				//�����������ԭ����ָ���ÿ�
				ap._ptr = nullptr;  // apʧȥ����Ȩ
			}

			//2.���ص�ǰ������֧����ʽ��ֵ
			return *this;
		}

		// 5. ���ؽ������������
		T& operator*()
		{
			return *_ptr;  // ������Դ������
		}
		//ע�⣺ģ��ԭʼָ���*����������ͨ��auto_ptr���ʡ���Դ����


		// 6. ���س�Ա���������
		T* operator->()
		{
			return _ptr;  // ������Դָ��
		}
		//ע�⣺ģ��ԭʼָ���->����������ͨ��auto_ptr���ʡ���Դ�ĳ�Ա��
	};

	// unique_ptr ģ��ʵ��
	template<class T>
	class unique_ptr {
	private:
		T* _ptr;  // ָ�����Ķ�̬��Դ

	public:
		// 1. ���캯��
		explicit unique_ptr(T* ptr) // explicit����ֹ��ʽת��������int*������ת��Ϊunique_ptr��
			: _ptr(ptr)
		{
		}
		/* �Աȷ�����unique_ptr��auto_ptr�ġ����캯����������
		*      1. unique_ptr�Ĺ��캯��ʹ����explicit �ؼ��ֽ����˽�ֹ��ʽת��
		*/

		// 2. ��������
		~unique_ptr() {
			if (_ptr)
			{
				//1.
				cout << "delete:" << _ptr << endl;

				//2.
				delete _ptr;

				//3.
				_ptr = nullptr;
			}
		}
		//�Աȷ����������unique_ptr��auto_ptr�ġ�����������ʵ��һ��


		// 3. ��ֹ������ɾ������������Ϳ�����ֵ��---> ȷ����Դ����ȨΨһ�������ظ��ͷ�
		//3.1����ֹ��������
		unique_ptr(const unique_ptr<T>& sp) = delete;
		//3.2����ֹ������ֵ
		unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;


		// 4. ���ؽ����������
		T& operator*() {
			return *_ptr;
		}
		//�Աȷ����������unique_ptr��auto_ptr�ġ����ؽ������������ʵ��һ��


		// 5. ���س�Ա���������
		T* operator->() {
			return _ptr;
		}
		//�Աȷ����������unique_ptr��auto_ptr�ġ����س�Ա�����������ʵ��һ��


		// 6. �ƶ����캯�� ---> ͨ����ֵ����ת������Ȩ
		unique_ptr(unique_ptr<T>&& sp)
			: _ptr(sp._ptr)     //1.�¶���ӹ�ԭ�������Դ
		{
			sp._ptr = nullptr;  //2.ԭ����ָ���ÿգ�ʧȥ����Ȩ
		}
		/* �Աȷ�����auto_ptr�ġ��������캯������ unique_ptr�ġ��ƶ����캯������Ψһ���𣺺��������Ĳ�ͬ
		*      1. auto_ptr(auto_ptr<T>& sp)
		*      2. unique_ptr��unique_ptr(unique_ptr<T>&& sp)
		*/


		// 7. �ƶ���ֵ����� ---> ͨ����ֵ����ת������Ȩ
		unique_ptr<T>& operator=(unique_ptr<T>&& sp)
		{
			//1.����Ը�ֵ�Ա����Լ���ֵ���Լ����µĴ���
			if (this != &sp)
			{
				//��һ�������ͷŵ�ǰ��Դ
				if (_ptr)
				{
					delete _ptr;
				}

				//�ڶ������ٽӹ�����Դ
				_ptr = sp._ptr;  //�ӹ�sp����Դ

				//�����������ԭ����ָ���ÿ�
				sp._ptr = nullptr;  // sp�ÿ�ʧȥ����Ȩ

			}
			//2.���ص�ǰ������֧����ʽ��ֵ
			return *this;
		}
		/* �Աȷ�����auto_ptr�ġ�������ֵ��������� unique_ptr�ġ��ƶ���ֵ���������Ψһ���𣺺��������Ĳ�ͬ
		*      1. auto_ptr��auto_ptr<T>& operator=(auto_ptr<T>& ap)
		*      2. unique_ptr��unique_ptr<T>& operator=(unique_ptr<T>&& sp)
		*/
	};


}