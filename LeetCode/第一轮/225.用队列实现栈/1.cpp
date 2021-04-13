#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int r = q.front();
        q.pop();
        return r;
    }

    /** Get the top element. */
    int top()
    {
        int r = q.front();
        return r;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }
};

int main(void)
{
    MyStack mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    cout << "栈顶元素为:" << mystack.top() << endl;
    cout << "出栈顺序为:" << endl;
    cout << mystack.pop() << endl;
    cout << mystack.pop() << endl;
    cout << mystack.pop() << endl;
    cout << "栈为空:" << endl;
    cout << mystack.empty() << endl;
}