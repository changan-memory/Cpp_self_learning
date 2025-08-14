#include <iostream>
using namespace std;

double Division(int a, int b) {
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}
void Func() {
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}
int main() {
	Func();
	/*try {
		Func();
	}
	catch (const char* errmsg) {
		cout << "Òì³£ÒÑ²¶»ñ: " << errmsg << endl;
	}
	catch (...) {
		cout << "unkown exception" << endl;
	}*/
	return 0;
}