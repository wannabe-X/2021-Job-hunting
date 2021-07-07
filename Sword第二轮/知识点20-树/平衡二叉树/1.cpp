/*
 * @Description: 平衡二叉树
 * @Author: Mr. Lee
 * @Date: 2021-07-06 21:18:47
 * @LastEditTime: 2021-07-06 21:54:51
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

void createTree(TreeNode *&T, vector<int> &nums, int loc)
{
    if (loc >= nums.size())
    {
        T = nullptr;
        return;
    }

    T = new TreeNode(nums[loc]);

    createTree(T->left, nums, 2 * loc + 1);
    createTree(T->right, nums, 2 * (loc + 1));
}

void printTree(TreeNode *&T)
{
    if (T == nullptr)
        return;

    cout << T->val << " ";
    printTree(T->left);
    printTree(T->right);
}

int TreeDepth(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return 0;

    return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}

bool IsBalanced_Solution(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return true;

    if (abs(TreeDepth(pRoot->left) - TreeDepth(pRoot->right)) > 1)
        return false;

    return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

int main()
{
    int null = 0;
    vector<int> nums = {8, 6, 10, 5, 7, 9, 11};
    TreeNode *pRoot;
    createTree(pRoot, nums, 0);
    // 先序遍历二叉树
    cout << "前序遍历二叉树: ";
    printTree(pRoot);
    cout << endl;

    bool ans = IsBalanced_Solution(pRoot);
    cout << boolalpha << ans << endl;

    return 0;
}
