#include <iostream>
#include <vector>
// 双端队列
#include <deque>
using namespace std;

// 双端队列的API
// class deque {
//     // 在队头插入元素 n
//     void push_front(int n);
//     // 在队尾插入元素 n
//     void push_back(int n);
//     // 在队头删除元素
//     void pop_front();
//     // 在队尾删除元素
//     void pop_back();
//     // 返回队头元素
//     int front();
//     // 返回队尾元素
//     int back();
// };

class MonotonicQueue
{
private:
    deque<int> data;

public:
    // 每次往队列里加元素，都要保证队列是从队头到队尾是单调递减的
    // 也就是说，每新加进来一个元素，都要将其往队头移动
    // 移动的过程中，如果发现前面的元素小于等于当前值，则pop队尾元素，指针前移
    void push(int val)
    {
        while (!data.empty() && data.back() < val)
            data.pop_back();
        data.push_back(val);
    }

    // 从push的过程可以看出，队头的元素永远是保持最大的
    int max()
    {
        return data.front();
    }

    // 如果队列的元素个数为k个并且队头的元素值等于当前值，删除队头元素
    // 例如，nums={3,2,1} 则队列元素为{3,2,1},此时应该删除3这个元素，进入下一个滑动窗口
    void pop(int val)
    {
        if (!data.empty() && data.front() == val)
            data.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    MonotonicQueue window;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
        // k-1个元素先填满
        if (i < k - 1)
        {
            window.push(nums[i]);
        }
        else
        {
            // 从队尾添加元素
            window.push(nums[i]);                                                                                                   
            // 获取最大值，加入到res中
            res.push_back(window.max());
            // 删除队尾元素
            window.pop(nums[i - k + 1]);
        }
    }
    return res;
}

int main(void)
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}