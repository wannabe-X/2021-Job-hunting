#include <iostream>
#include <stack>
using namespace std;

// 参考代码
// 使用两个栈 一个辅助栈 一个数据栈
class MinStack
{
private:
    stack<int> m_data;
    stack<int> m_min;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        m_data.push(x);
        if (m_min.size() == 0 || m_min.top() >= x)
            m_min.push(x);
    }

    void pop()
    {
        if (m_data.top() == m_min.top())
            m_min.pop();
        m_data.pop();
    }

    int top()
    {
        return m_data.top();
    }

    int min()
    {
        return m_min.top();
    }
};

int main(void)
{
    MinStack minstk;
    minstk.push(-2);
    minstk.push(0);
    minstk.push(-3);
    cout << minstk.min() << endl;
    minstk.pop();
    minstk.top();
    cout << minstk.min() << endl;

    return 0;
}