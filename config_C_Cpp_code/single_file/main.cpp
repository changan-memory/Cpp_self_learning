#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1(10, 2);
    for (auto& e : v1) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}