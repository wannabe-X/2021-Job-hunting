/*
 * @Description:  对称的二叉树
 * @Author: Mr. Lee
 * @Date: 2021-07-06 20:59:17
 * @LastEditTime: 2021-07-06 21:17:21
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

bool func(TreeNode *L, TreeNode *R)
{
    if (L == nullptr && R == nullptr)
    {
        return true;
    }
    if (L == nullptr || R == nullptr || (L->val != R->val))
    {
        return false;
    }

    return func(L->left, R->right) && func(L->right, R->left);
}

bool isSymmetrical(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return false;

    return func(pRoot->left, pRoot->right);
}

int main()
{
    int null = 0;
    vector<int> nums = {8, 6, 9, 5, 7, 7, 5};
    TreeNode *pRoot;
    createTree(pRoot, nums, 0);

    bool ans = isSymmetrical(pRoot);
    cout << boolalpha << ans << endl;

    return 0;
}
