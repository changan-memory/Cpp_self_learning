#include <iostream>
#include <list>
using namespace std;

void testAccess() {
	std::list<int> lt;
	lt.push_back(11);
	lt.push_back(12);
	lt.push_back(22);
	lt.push_back(32);
	for (auto e : lt)
		cout << e << " ";
	cout << endl;
}

int main() {
	
	testAccess();
	return 0;
}