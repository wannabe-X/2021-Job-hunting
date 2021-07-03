/*
 * @Description: 把二叉树打印成多行
 * @Author: Mr. Lee
 * @Date: 2021-07-03 20:11:34
 * @LastEditTime: 2021-07-03 20:53:58
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> tmpv;
    queue<TreeNode *> q;
    q.push(pRoot);

    while (!q.empty())
    {
        for (int i = q.size(); i > 0; i--)
        {
            auto tmp = q.front();
            tmpv.push_back(tmp->val);
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }

        v.push_back(tmpv);
        tmpv.clear();
    }

    return v;
}

int main()
{
    int null = 0;
    vector<int> nums = {8, 6, null, 10, 5, 7, 9, 11};
    TreeNode *pRoot;
    createTree(pRoot, nums, 0);
    // 先序遍历二叉树
    cout << "前序遍历二叉树: ";
    printTree(pRoot);
    cout << endl;

    // 层序打印二叉树
    cout << "层序打印二叉树的结果:" << endl;
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
