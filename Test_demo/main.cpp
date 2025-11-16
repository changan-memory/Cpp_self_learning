#include "SmartPointer.h"

class A
{	
public:
	int _a;

	A(int a = 0)
		:_a(a)
	{
		cout << "¹¹ÔìA" << endl;
	}
	~A()
	{
		cout << "Îö¹¹A" << endl;
	}
};

void teat_auto_Ptr()
{
	myPointer::auto_ptr<A> ap1(new A(1));
	myPointer::auto_ptr<A> ap3;
	myPointer::auto_ptr<A> ap2(ap1);

	/*cout << ap2->_a << endl;
	cout << ap1->_a << endl;*/

	
}
int main()
{
	teat_auto_Ptr();
	return 0;
}

