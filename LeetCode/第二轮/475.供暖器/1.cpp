/*
 * @Description: 475. 供暖器
 * @Author: Mr. Lee
 * @Date: 2021-12-20 00:03:24
 * @LastEditTime: 2021-12-20 00:30:54
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findRadius(vector<int> &houses, vector<int> &heaters)
{
    int ans = 0;
    sort(heaters.begin(), heaters.end()); // 排序
    for (int house : houses)
    {
        int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin(); // 大于house的元素下标
        int i = j - 1;
        int rightDistance = j >= heaters.size() ? INT_MAX : heaters[j] - house; // 右边界 覆盖半径
        int leftDistance = i < 0 ? INT_MAX : house - heaters[i]; // 左边界 覆盖半径
        int curDistance = min(leftDistance, rightDistance); // 取最小
        ans = max(ans, curDistance); // 取最大
    }
    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> houses = {1, 2, 3, 4}, heaters = {1, 4};
    int ans = findRadius(houses, heaters);
    cout << ans << endl;

    return 0;
}