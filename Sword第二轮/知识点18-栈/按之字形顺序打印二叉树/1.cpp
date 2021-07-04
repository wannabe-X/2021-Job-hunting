/*
 * @Description: 按之字形顺序打印二叉树
 * @Author: Mr. Lee
 * @Date: 2021-07-04 23:38:37
 * @LastEditTime: 2021-07-04 23:50:55
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

vector<vector<int>> Print(TreeNode *pRoot)
{
    vector<vector<int>> v;
    if (pRoot == nullptr)
        return v;
    vector<int> tmp;
    queue<TreeNode *> q;
    q.push(pRoot);
    int flag = 0;

    while (!q.empty())
    {
        for (int i = q.size(); i > 0; i--)
        {
            auto node = q.front();
            q.pop();
            tmp.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        if (flag & 1)
            reverse(tmp.begin(), tmp.end());
        v.push_back(tmp);
        tmp.clear();
        flag++;
    }

    return v;
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

    // 层序打印二叉树
    // cout << "层序打印二叉树的结果:" << endl;
    vector<vector<int>> ans = Print(pRoot);

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
