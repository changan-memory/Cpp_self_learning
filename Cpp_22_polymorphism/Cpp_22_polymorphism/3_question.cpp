#include <iostream>
using namespace std;

// ���һ�����ܱ��̳е���
// 1. ���캯��˽��/��������˽�� (C++98)
// 2. ��final���θ��࣬��ʾ�����������࣬���ܱ��̳� (C++11)
namespace question1 {
	// ��һ����Ĺ��캯��˽�к󣬸���Ͳ��ܱ��̳���
	class A {
	public:
		// AҲ��Ҫ����������˿����ṩһ�����������ڴ���A�Ķ���
		// ���ǵ���ʱ���Ǿ�̬��Ա��������Ҫ����������ܣ����ܵ���
		// ��� ��Ƴɾ�̬��Ա���� ���Խ��������
		static A creatObj() {
			return A();
		}
	private:
		A(){}
	};
	class B : public A {

	};
	void test() {
		A a = A::creatObj();
	}
}

namespace question2 {
	// ��һ�������������˽��
	class A {
	public:
	private:
		~A() {}
	};
	class B : public A {

	};
	void test() {
		//B b;	// �޷�����������ΪB�޷�������������
	}
}
namespace question3 {
	// C++11 final final���ε��಻�ܱ��̳�
	class A final {
	public:
	private:
		~A() {}
	};
	//class B : public A	// A���ܱ��̳�
	//{ };
}
