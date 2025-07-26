#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

// 1. ��Сջ
class MinStack {
public:
    // Ĭ�Ϲ��죬��Ա�����߳�ʼ���б��������Ͳ��������Զ������� ����Ĭ�Ϲ���
    MinStack()
    { }
    ~MinStack() //�����������������Ͳ��ùܣ���������ʱ�Զ��ͷţ������������Զ��������Զ�������������
    {}

    void push(int val) {
        _st.push(val);
        if (_minst.empty() || val <= _minst.top())
            _minst.push(val);
    }

    void pop() {
        if (_st.top() == _minst.top())
            _minst.pop();
        _st.pop();
    }

    int top() {
        return _st.top();
    }

    int getMin() {
        return _minst.top();
    }

private:
    std::stack<int> _st;
    std::stack<int> _minst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// 2. 
// ջ��ѹ�롢��������
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pushV int����vector
     * @param popV int����vector
     * @return bool������
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        stack<int> st;
        int pushIndex = 0, outIndex = 0;
        while (!st.empty() && outIndex < popV.size()) {
            st.push(pushV[pushIndex++]);
            while(st.top() != popV[outIndex]) {
                st.push(pushV[pushIndex]);
            }
            // top == popV[outIndex] ��
            --outIndex;
            st.pop();
        }

    }
};