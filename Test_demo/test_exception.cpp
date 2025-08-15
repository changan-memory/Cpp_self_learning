#include <iostream>
using namespace std;
//
//class A {
//public:
//	void f() { cout << "A::f()" << endl; }
//	int a;
//};
//
//class B : public A {
//public:
//	void f(int a) { cout << "B::f()" << endl; }
//	int a;
//};
//int main(){
//	B b;
//	b.f();
//	return 0;
//}

//class A {
//public:
//	A() { cout << "A::A()" << endl; }
//	~A() { cout << "A::~A()" << endl; }
//	int a;
//};
//
//class B : public A {
//public:
//	B() { cout << "B::B()" << endl; }
//	~B() { cout << "B::~B()" << endl; }
//	int b;
//};
//void f() {
//	B b;
//}
//
//int main() {
//	f();
//}

//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//
//class Derive : public Base1, public Base2 {
//public: 
//	int _d;
//};
//
//int main() {
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}

class B {
public:
	int _b;
};

class C1 : public B { public: int c1; };

class C2 : public B { public: int c2; };

class D : public C1, public C2 {
public:
	int d;
};

int main() {
	cout << sizeof(D) << endl;
}