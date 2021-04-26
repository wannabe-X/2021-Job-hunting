#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

class MaxQueue
{
private:
    queue<int> myQue; // 普通队列
    deque<int> myDqe; // 双端队列，用于存放当前队列的最大值

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (myDqe.empty())
            return -1;
        return myDqe.front();
    }

    void push_back(int value)
    {
        // 双端队列的队头元素存放的是当前入普通队列所有的最大值
        // 如果普通队列发生pop或者push操作，依然可以保证双端队列的队头元素存放的是当前入普通队列所有的最大值
        // 而且，myDqe.back() < value 一定是小于号，不能是小于等于；
        // 否则弹出的时候就会出现myQue不为空而myDue为空的情形，导致无法计算最大值
        for (; !myDqe.empty() && myDqe.back() < value; myDqe.pop_back())
            ;
        myDqe.push_back(value);
        myQue.push(value);
    }

    int pop_front()
    {
        // 如果普通队列为空，则返回-1
        if (myQue.empty())
            return -1;

        // 如果普通队列的队头元素为当前所有元素的最大值
        // 那么普通队列元素弹出的时候，双端队列的队头元素也应该弹出，否则会影响下一轮的结果
        int ans = myQue.front();
        if (ans == myDqe.front())
            myDqe.pop_front();
        myQue.pop();
        return ans;
    }
};

int main(void)
{
    MaxQueue mqe;
    mqe.push_back(1);
    mqe.push_back(2);
    cout << mqe.max_value() << endl;
    cout << mqe.pop_front() << endl;
    cout << mqe.max_value() << endl;
    return 0;
}