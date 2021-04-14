#include <iostream>
#include <stack>

using namespace std;

class CQueue
{
private:
    stack<int> p, q;
    void Push()
    {
        while (!p.empty())
        {
            q.push(p.top());
            p.pop();
        }
    }

public:
    CQueue()
    {
        while (!p.empty())
            p.pop();
        while (!q.empty())
            q.empty();
    }

    void appendTail(int value)
    {
        p.push(value);
    }

    int deleteHead()
    {
        int temp;
        if (q.empty())
            Push();

        if (q.empty())
            temp = -1;
        else
        {
            temp = q.top();
            q.pop();
        }
        return temp;
    }
};

int main(void)
{
    CQueue cq;
    cout << cq.deleteHead() << endl;
    cq.appendTail(5);
    cq.appendTail(2);
    cout << cq.deleteHead() << endl;
    cout << cq.deleteHead() << endl;
    return 0;
}