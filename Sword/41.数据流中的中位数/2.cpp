#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class MedianFinder
{
public:
    priority_queue<int, vector<int>, less<int>> big_top;      // 大顶堆 左
    priority_queue<int, vector<int>, greater<int>> small_top; // 小顶堆 右

    // 构造函数 初始化
    MedianFinder()
    {
    }

    // 保证左右两边数据平衡
    void addNum(int num)
    {
        if (big_top.size() == small_top.size())
        {
            small_top.push(num);
            big_top.push(small_top.top());
            small_top.pop();
        }
        else
        {
            big_top.push(num);
            small_top.push(big_top.top());
            big_top.pop();
        }
    }

    double findMedian()
    {
        if (small_top.size() == big_top.size())
            return (small_top.top() + big_top.top() + 0.0) / 2;
        else
            return (big_top.top() + 0.0);
    }
};

int main(void)
{
    MedianFinder med;
    med.addNum(1);
    med.addNum(2);
    cout << med.findMedian() << endl;
    med.addNum(3);
    cout << med.findMedian() << endl;
    return 0;
}