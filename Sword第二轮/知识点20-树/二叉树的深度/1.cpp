/*
 * @Description: 二叉树的深度
 * @Author: Mr. Lee
 * @Date: 2021-07-06 00:00:48
 * @LastEditTime: 2021-07-06 21:00:56
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void createBiTree(TreeNode *&T, vector<int> nums, int loc)
{
    if (loc >= nums.size())
    {
        T = nullptr;
        return;
    }

    T = new TreeNode(nums[loc]);
    createBiTree(T->left, nums, 2 * loc + 1);
    createBiTree(T->right, nums, 2 * (loc + 1));
}

void prinTree(TreeNode *T)
{
    if (T == nullptr)
        return;
    cout << T->val << " ";
    prinTree(T->left);
    prinTree(T->right);
}

int TreeDepth(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return 0;

    return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *pRoot = nullptr;
    createBiTree(pRoot, nums, 0);
    prinTree(pRoot);
    cout << endl;

    int ans = TreeDepth(pRoot);
    cout << ans << endl;

    return 0;
}
