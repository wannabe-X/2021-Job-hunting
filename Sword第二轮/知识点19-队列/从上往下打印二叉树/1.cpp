/*
 * @Description: 从上往下打印二叉树
 * @Author: Mr. Lee
 * @Date: 2021-07-05 00:58:16
 * @LastEditTime: 2021-07-05 01:07:02
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

vector<int> PrintFromTopToBottom(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        for (int i = q.size(); i > 0; i--)
        {
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return res;
}

int main()
{
    int null = 0;
    vector<int> nums = {5, 4, null, 3, null, 2, null, 1};
    TreeNode *pRoot;
    createTree(pRoot, nums, 0);
    // 先序遍历二叉树
    cout << "前序遍历二叉树: ";
    printTree(pRoot);
    cout << endl;

    vector<int> ans = PrintFromTopToBottom(pRoot);
    cout << "从上往下打印二叉树:";
    for (int num : ans)
        cout << num << " ";

    return 0;
}
