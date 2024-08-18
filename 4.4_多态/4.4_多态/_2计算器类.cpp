//#include <iostream>
//using namespace std;
//
//class Calculator {
//public:
//	int get_result(string opera) {
//		if (opera == "+")
//			return _Num1 + _Num2;
//		if (opera == "-")
//			return _Num1 - _Num2;
//		if (opera == "*")
//			return _Num1 * _Num2;
//	}
//	int _Num1;
//	int _Num2;
//};
//
//void test1() {
//	Calculator c;
//	c._Num1 = 10;
//	c._Num2 = 20;
//	cout << c._Num1 << " + " << c._Num2 << " = " << c.get_result("+") << endl;
//	cout << c._Num1 << " - " << c._Num2 << " = " << c.get_result("-") << endl;
//	cout << c._Num1 << " * " << c._Num2 << " = " << c.get_result("*") << endl;
//}
//
//class AbstructCalculator {
//public:
//	virtual int get_result() {
//		return 0;
//	}
//	int _Num1;
//	int _Num2;
//};
//
//class AddCal :public AbstructCalculator {
//public:
//	virtual int get_result() {
//		return _Num1 + _Num2;
//	}
//};
//
//class SubCal :public AbstructCalculator {
//public:
//	virtual int get_result() {
//		return _Num1 - _Num2;
//	}
//};
//
//class MulCal :public AbstructCalculator {
//public:
//	virtual int get_result() {
//		return _Num1 * _Num2;
//	}
//};
//
//class DivCal :public AbstructCalculator {
//public:
//	virtual int get_result() {
//		return _Num1 / _Num2;
//	}
//};
//
//void test2() {
//	AbstructCalculator* cal = new AddCal;
//	cal->_Num1 = 10;
//	cal->_Num2 = 30;
//	cout << cal->_Num1 << " + " << cal->_Num2 << " = " << cal->get_result() << endl;
//	delete cal;
//	cal = nullptr;
//
//	cal = new SubCal;
//	cal->_Num1 = 10;
//	cal->_Num2 = 30;
//	cout << cal->_Num1 << " - " << cal->_Num2 << " = " << cal->get_result() << endl;
//	delete cal;
//	cal = nullptr;
//
//	cal = new MulCal;
//	cal->_Num1 = 10;
//	cal->_Num2 = 30;
//	cout << cal->_Num1 << " * " << cal->_Num2 << " = " << cal->get_result() << endl;
//	delete cal;
//	cal = nullptr;
//
//	cal = new DivCal;
//	cal->_Num1 = 10;
//	cal->_Num2 = 30;
//	cout << cal->_Num1 << " / " << cal->_Num2 << " = " << cal->get_result() << endl;
//	delete cal;
//	cal = nullptr;
//	
//}
//int main() {
//
//
//	//test1();
//	test2();
//	return 0;
//}