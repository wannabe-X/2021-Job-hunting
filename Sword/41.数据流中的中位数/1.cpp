#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MedianFinder
{
private:
    vector<int> nums;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        nums.push_back(num);
        sort(nums.begin(), nums.end());
    }

    double findMedian()
    {
        if (nums.size() % 2 == 1)
        {
            return nums[nums.size() / 2];
        }
        else
            return (nums[nums.size() / 2 - 1] + nums[nums.size() / 2] + 0.0) / 2;
    }
};

int main(void)
{
    MedianFinder med;
    med.addNum(1);
    med.addNum(2);
    cout << med.findMedian() << endl;
    // med.addNum(3);
    // cout << med.findMedian()<<endl;
    return 0;
}