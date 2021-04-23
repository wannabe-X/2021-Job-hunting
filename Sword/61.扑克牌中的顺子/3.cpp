#include <iostream>
#include <vector>
#include <algorithm>

// 参考代码
using namespace std;

bool isStraight(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int numberOfZreo = 0, numberOfGap = 0;
    // 找到排序后的数组中0的个数
    for (int i = 0; i < nums.size() && nums[i] == 0; numberOfZreo++, i++)
        ;
    
    // 从numberOfZero开始查找数字之间的间隔有多大
    // 如果间隔数小于等于0的个数，那么是可以组成顺子的
    // 注意：如果五张牌中出现非零元素重复，则无法构成顺子，直接返回false
    for (int i = numberOfZreo; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            return false;
        numberOfGap += (nums[i + 1] - nums[i] - 1);
    }

    return numberOfGap <= numberOfZreo;
}

int main(void)
{
    vector<int> nums = {0, 0, 2, 3, 5};
    bool ans = isStraight(nums);
    cout << boolalpha << ans << endl;
    return 0;
}