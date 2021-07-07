/*
 * @Description: 二叉树中和为某一值的路径
 * @Author: Mr. Lee
 * @Date: 2021-07-06 23:54:32
 * @LastEditTime: 2021-07-07 00:03:46
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

vector<vector<int>> res;
vector<int> tmp;

void boardtrack(TreeNode *root, int expectNumber)
{
    if (root == nullptr)
    {
        // if()
    }
}

vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
{
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

    return 0;
}
