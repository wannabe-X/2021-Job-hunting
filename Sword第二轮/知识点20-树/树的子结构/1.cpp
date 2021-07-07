/*
 * @Description: 树的子结构
 * @Author: Mr. Lee
 * @Date: 2021-07-07 16:55:35
 * @LastEditTime: 2021-07-07 17:51:55
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

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
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

bool func(TreeNode *A, TreeNode *B)
{
    if (B == nullptr)
        return true;
    if (A == nullptr || A->val != B->val)
        return false;

    return func(A->left, B->left) && func(A->right, B->right);
}

bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (pRoot1 == nullptr || pRoot2 == nullptr)
    {
        return false;
    }

    return func(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

int main()
{
    int null = 0;
    vector<int> nums1 = {8, 8, null, 9, null, 2, null, 5}, nums2 = {8, 9, null, 2};
    TreeNode *pRoot1;
    createTree(pRoot1, nums1, 0);
    TreeNode *pRoot2;
    createTree(pRoot2, nums2, 0);
    // 先序遍历二叉树
    cout << "前序遍历二叉树1: ";
    printTree(pRoot1);
    cout << endl;
    cout << "前序遍历二叉树2: ";
    printTree(pRoot2);
    cout << endl;

    bool ans = HasSubtree(pRoot1, pRoot2);
    cout << boolalpha << ans << endl;

    return 0;
}
