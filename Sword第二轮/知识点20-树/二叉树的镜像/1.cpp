/*
 * @Description: 二叉树的镜像
 * @Author: Mr. Lee
 * @Date: 2021-07-05 11:27:45
 * @LastEditTime: 2021-07-05 11:52:36
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

TreeNode *Mirror(TreeNode *pRoot)
{
    if (!pRoot)
        return nullptr;

    TreeNode *left = Mirror(pRoot->left);
    TreeNode *right = Mirror(pRoot->right);
    
    pRoot->left = right;
    pRoot->right = left;

    return pRoot;
}


int main()
{
    int null = 0;
    vector<int> nums = {8, 6, 10, 5, 7, 9, 11};
    TreeNode *pRoot,*ans;
    createTree(pRoot, nums, 0);
    // 先序遍历二叉树
    cout << "前序遍历二叉树: ";
    printTree(pRoot);
    cout << endl;

    ans = Mirror(pRoot);
    cout << "镜像二叉树: ";
    printTree(ans);

    return 0;
}
