#include <iostream>
#include <vector>

using namespace std;
int mergeSort(int l, int r, vector<int> &nums, vector<int> &tmp);

int reversePairs(vector<int> &nums)
{
    vector<int> tmp(nums.size());
    return mergeSort(0, nums.size() - 1, nums, tmp);
}

int mergeSort(int l, int r, vector<int> &nums, vector<int> &tmp)
{
    // 终止条件
    if (l >= r)
        return 0;
    // 递归划分
    int m = (l + r) / 2;
    int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
    // 合并阶段
    int i = l, j = m + 1;
    for (int k = l; k <= r; k++)
        tmp[k] = nums[k];
    for (int k = l; k <= r; k++)
    {
        if (i == m + 1)
            nums[k] = tmp[j++];
        else if (j == r + 1 || tmp[i] <= tmp[j])
            nums[k] = tmp[i++];
        else
        {
            nums[k] = tmp[j++];
            res += m - i + 1; // 统计逆序对
        }
    }
    return res;
}

int main(void)
{
    vector<int> nums = {7, 5, 6, 4};
    int ans = reversePairs(nums);
    cout << ans << endl;
    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

