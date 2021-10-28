/*
 * @Description: 240. 搜索二维矩阵 II
 * @Author: Mr. Lee
 * @Date: 2021-10-25 00:12:29
 * @LastEditTime: 2021-10-25 00:27:32
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &nums, int target)
{
    int left = 0, right = nums.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid;
        else if (nums[mid] == target)
            return true;
    }

    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (target >= matrix[i][0] && target <= matrix[i][matrix[0].size() - 1])
        {
            if (check(matrix[i], target))
                return true;
        }
    }
    return false;
}

int main(void)
{
    vector<vector<int>> nums =
        {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    bool ans = searchMatrix(nums, target);
    cout << boolalpha << ans << endl;

    return 0;
}