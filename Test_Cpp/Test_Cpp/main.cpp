#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isLetter(const char ch) {
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
			return true;
		}
		else {
			return false;
		}
	}
	string reverseOnlyLetters(string s) {
		if (s.empty())
			return s;
		int left = 0, right = s.size() - 1;

		while (left < right) {
			while (!isLetter(s[left])) {
				if (left >= right) {
					break;
				}
				++left;
				
			}
			while (!isLetter(s[right])) {
				if (left >= right) {
					break;
				}
				--right;
				
			}
			swap(s[left], s[right]);
			++left;
			--right;
		}
		return s;
	}
};

int main() {

	string s1("7_28]");
	Solution s;
	string s_res = s.reverseOnlyLetters(s1);
	cout << s_res << endl;
	return 0;
}