/*
 * @Description: 二叉树中和为某一值的路径
 * @Author: Mr. Lee
 * @Date: 2021-07-06 23:54:32
 * @LastEditTime: 2021-07-07 16:27:36
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

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
        return;
    }

    tmp.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr)
    {
        if (accumulate(tmp.begin(), tmp.end(), 0) == expectNumber)
        {
            res.push_back(tmp);
        }
    }

    boardtrack(root->left, expectNumber);
    boardtrack(root->right, expectNumber);
    tmp.pop_back();
}

vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
{
    if (root == nullptr)
        return res;
    boardtrack(root, expectNumber);
    return res;
}

int main()
{
    int null = 0;
    vector<int> nums = {10, 5, 12, 4, 7};
    TreeNode *pRoot;
    createTree(pRoot, nums, 0);
    // 先序遍历二叉树
    cout << "前序遍历二叉树: ";
    printTree(pRoot);
    cout << endl;

    int expectNumber = 22;
    vector<vector<int>> ans = FindPath(pRoot, expectNumber);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
