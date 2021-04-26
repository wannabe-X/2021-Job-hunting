#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class MonotonicQueue
{
private:
    deque<int> myQue; // 双端队列

public:
    void push(int n)
    {
        // 能者居之
        // 如果即将入队列的元素大于队尾元素，那么就将最后一个元素弹出，直到遇到一个大于n的元素止步
        // 这样就能保证入队的元素都是按照从大到小的顺序排列的
        while (!myQue.empty() && myQue.back() < n)
            myQue.pop_back();
        myQue.push_back(n);
    }

    int max()
    {
        return myQue.front();
    }

    void pop(int n)
    {
        // 消除前一个滑动窗口的第一个值的影响
        // 例如 3 2 1 2
        // 第一个滑动窗口的最大值为3
        // 如果3不消除，那么滑动到下一个窗口的时候，最大值依然是3，而实际结果应该是2
        // 保证上一个窗口第一个元素产生的影响不会累积到下一个窗口
        if (!myQue.empty() && myQue.front() == n)
            myQue.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> res;
    MonotonicQueue window;
    for (int i = 0; i < nums.size(); i++)
    {
        // 先将前k-1个个元素填满window
        if (i < k - 1)
            window.push(nums[i]);
        else
        {
            window.push(nums[i]);
            res.push_back(window.max());
            // 消除上一个窗口第一个元素产生的影响
            // 如果上一个窗口的第一个元素不会影响到下一个窗口，就不需要消除
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
    cout << "[";
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ",";
    cout << ans[ans.size() - 1] << "]" << endl;

    return 0;
}