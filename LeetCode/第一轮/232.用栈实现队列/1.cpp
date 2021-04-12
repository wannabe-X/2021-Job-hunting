#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class MyQueue
{
private:
    stack<int> s1, s2;

    void in2out()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (s2.empty())
        {
            in2out();
        }

        int x = s2.top();
        s2.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        if (s2.empty())
            in2out();
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main(void)
{
    MyQueue myqueue;
    myqueue.push(1);
    myqueue.push(2);
    myqueue.push(3);
    cout << "队头元素为:" << myqueue.peek() << endl;
    cout << "出队顺序为:" << endl;
    cout << myqueue.pop() << endl;
    cout << myqueue.pop() << endl;
    cout << myqueue.pop() << endl;
    cout << "队列为空:" << endl;
    cout << myqueue.empty() << endl;
}