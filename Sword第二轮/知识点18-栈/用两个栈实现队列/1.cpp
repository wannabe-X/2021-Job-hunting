/*
 * @Description: 用两个栈实现队列
 * @Author: Mr. Lee
 * @Date: 2021-07-04 14:50:29
 * @LastEditTime: 2021-07-04 15:13:14
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        stack1ToStack2();
        int tmp = stack2.top();
        stack2.pop();
        stack2ToStack1();

        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;

    void stack1ToStack2()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    void stack2ToStack1()
    {
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
};

int main()
{
    // ["PSH1","PSH2","POP","POP"]
    Solution sol;
    sol.push(1);
    sol.push(2);
    cout << sol.pop() << endl;
    cout << sol.pop() << endl;

    return 0;
}
