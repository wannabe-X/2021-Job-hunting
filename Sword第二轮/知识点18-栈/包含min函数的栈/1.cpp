/*
 * @Description: 包含min函数的栈
 * @Author: Mr. Lee
 * @Date: 2021-07-04 15:48:54
 * @LastEditTime: 2021-07-04 16:43:12
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 使用单调栈
class Solution
{
public:
    void push(int value)
    {
        stk1.push(value);
        minstack(value);
    }
    void pop()
    {
        int tmp = stk1.top();
        stk1.pop();
        if (tmp == stk2.top())
            stk2.pop();
    }
    int top()
    {
        return stk1.top();
    }
    int min()
    {
        return stk2.top();
    }

private:
    stack<int> stk1, stk2;

    void minstack(int val)
    {
        if (stk2.empty() || val <= stk2.top())
        {
            stk2.push(val);
        }
    }
};

int main()
{
    // 测试用例
    // ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
    // ["PSH3","MIN","PSH4","MIN","PSH2","MIN","PSH3","MIN","POP","MIN","POP","MIN","POP","MIN","PSH0","MIN"]
    Solution sol;
    sol.push(-1);
    sol.push(2);
    cout << sol.min() << endl;
    cout << sol.top() << endl;
    sol.pop();
    sol.push(1);
    cout << sol.top() << endl;
    cout << sol.min() << endl;

    // 测试用例
    // ["PSH3","MIN","PSH4","MIN","PSH2","MIN","PSH3","MIN","POP","MIN","POP","MIN","POP","MIN","PSH0","MIN"]
    // Solution sol;
    // sol.push(3);
    // cout << sol.min() << endl;
    // sol.push(4);
    // cout << sol.min() << endl;
    // sol.push(2);
    // cout << sol.min() << endl;
    // sol.push(3);
    // cout << sol.min() << endl;
    // sol.pop();
    // cout << sol.min() << endl;
    // sol.pop();
    // cout << sol.min() << endl;
    // sol.pop();
    // cout << sol.min() << endl;
    // sol.push(0);
    // cout << sol.min() << endl;

    return 0;
}
