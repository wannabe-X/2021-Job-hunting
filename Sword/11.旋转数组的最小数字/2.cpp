#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 参考解法
// 精妙的算法 二分查找
int minArray(vector<int> &numbers)
{
    int i = 0, j = numbers.size() - 1;
    while (i < j)
    {
        int mid = (i + j) / 2;
        if (numbers[mid] > numbers[j])
            i = mid + 1;
        else if (numbers[mid] < numbers[j])
            j = mid;
        else
            j--;
    }
    return numbers[i];
}

int main(void)
{
    vector<int> nums = {2, 2, 2, 0, 1};
    int ans = minArray(nums);
    cout << ans << endl;
    return 0;
}
