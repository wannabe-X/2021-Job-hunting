/*
 * @Description: 295. 数据流的中位数
 * @Author: Mr. Lee
 * @Date: 2021-08-27 00:32:40
 * @LastEditTime: 2021-08-27 00:45:43
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (minHeap.size() == maxHeap.size())
        {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else
        {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian()
    {
        if ((minHeap.size() + maxHeap.size()) & 1)
        {
            return (maxHeap.top() + 0.0);
        }

        return (minHeap.top() + maxHeap.top() + 0.0) / 2;
    }

private:
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小根堆
    priority_queue<int, vector<int>, less<int>> maxHeap; // 大根堆
};

int main(int argc, char *argv[])
{
    MedianFinder *mf = new MedianFinder();
    mf->addNum(1);
    mf->addNum(2);
    cout << mf->findMedian() << endl;
    mf->addNum(3);
    cout << mf->findMedian() << endl;

    return 0;
}
