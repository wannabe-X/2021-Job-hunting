#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class MedianFinder
{
public:
    // 1 2 3 4 x 5 6 7 8
    // 1 2 3 4 是大顶堆，也就是顶部是最大值
    // 5 6 7 8 是小顶堆，也就是顶部是最小值
    // 这样可以保证大顶堆的最大值小于小顶堆的最小值
    // 大顶堆是中位数前半部分 小顶堆是数据的后半部分
    // 优先队列每次有元素进入都会进行排序
    priority_queue<int, vector<int>, less<int>> big_top;      // 大顶堆 左
    priority_queue<int, vector<int>, greater<int>> small_top; // 小顶堆 右

    // 构造函数 初始化
    MedianFinder()
    {
    }

    // 保证左右两边数据平衡
    // 如果两边数据长度相等，则把数据先存放到大顶堆里面，然后再将大顶堆顶部元素存入小顶堆
    void addNum(int num)
    {
        if (big_top.size() == small_top.size())
        {
            big_top.push(num);
            small_top.push(big_top.top());
            big_top.pop();
        }
        // 如果两边数据长度相等，则把数据先存放到小顶堆里面，然后再将小顶堆顶部元素存入大顶堆
        // 如此操作，总是可以保证数据总长度为偶数的情况下，中位数为大小顶堆元素相加除以2
        // 数据总长度为奇数的情况下，可以保证数据中位数为小顶堆的堆顶元素
        else
        {
            small_top.push(num);
            big_top.push(small_top.top());
            small_top.pop();
        }
    }

    // 如果数据总长度为偶数，那么大顶堆和小顶堆的数据长度应该相等，此时中位数应该是大小顶堆的元素值相加除以2
    // 如果数据总长度为奇数，那么小顶堆的长度应该比大顶堆的长度大1，此时中位数应该是小顶堆的顶部元素
    double findMedian()
    {
        if (small_top.size() == big_top.size())
            return (small_top.top() + big_top.top() + 0.0) / 2;
        else
            return (small_top.top() + 0.0);
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