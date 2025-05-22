#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

// 1. 最小栈
class MinStack {
public:
    // 默认构造，成员变量走初始化列表，内置类型不做处理，自定义类型 调用默认构造
    MinStack()
    { }
    ~MinStack() //析构函数，内置类型不用管，对象销毁时自动释放，析构函数，自定义类型自动调用析构函数
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
// 栈的压入、弹出序列
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
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
            // top == popV[outIndex] 了
            --outIndex;
            st.pop();
        }

    }
};