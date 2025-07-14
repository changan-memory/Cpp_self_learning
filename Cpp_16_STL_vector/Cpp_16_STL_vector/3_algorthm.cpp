#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
    //构建数字和字母的映射关系
    const char* arr[10] = { "", "", "abc", "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    void Conbine(string digits, int level, string conbineStr, vector<string>& retVect) {
        //递归结束条件
        if (level == digits.size()) {
            retVect.push_back(conbineStr);
            return;
        }

        //取第一个字符串, 存入str
        int num = digits[level] - '0';
        string str = arr[num];

        for (size_t i = 0; i < str.size(); ++i)
            Conbine(digits, level + 1, conbineStr + str[i], retVect);

    }
    vector<string> letterCombinations(string digits) {
        vector<string> retVect;
        if (digits.empty())
            return retVect;

        Conbine(digits, 0, "", retVect);
        return retVect;
    }
};