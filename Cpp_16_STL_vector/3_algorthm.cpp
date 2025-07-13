#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
    //�������ֺ���ĸ��ӳ���ϵ
    const char* arr[10] = { "", "", "abc", "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    void Conbine(string digits, int level, string conbineStr, vector<string>& retVect) {
        //�ݹ��������
        if (level == digits.size()) {
            retVect.push_back(conbineStr);
            return;
        }

        //ȡ��һ���ַ���, ����str
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