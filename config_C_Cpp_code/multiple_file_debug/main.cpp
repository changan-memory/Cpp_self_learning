#include <iostream>
#include <vector>
using namespace std;

extern int Add(int x, int y);

int main() {
    vector<int> v1(10, 2);
    for (auto& e : v1) {
        cout << e << " ";
    }
    cout << endl;
    cout << Add(10, 60) << endl;
    return 0;
}