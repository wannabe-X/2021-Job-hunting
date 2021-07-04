/*
 * @Description: 二叉搜索树的后序遍历序列
 * @Author: Mr. Lee
 * @Date: 2021-07-05 00:50:33
 * @LastEditTime: 2021-07-05 00:55:39
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

TreeNode *insertion(TreeNode *root, int x)
{
    TreeNode *p = new TreeNode(x);

    if (root == nullptr)
    {
        root = p;
    }
    else if (x > root->val)
    {
        root->right = insertion(root->right, x);
    }
    else if (x < root->val)
    {
        root->left = insertion(root->left, x);
    }

    return root;
}

TreeNode *creatBinarySearchTree(vector<int> &ptr)
{
    // 此处的p是个根节点
    TreeNode *p = new TreeNode(ptr[0]);

    for (int i = 1; i < ptr.size(); i++)
    {
        // 每次插入都从根节点出发
        insertion(p, ptr[i]);
    }

    return p;
}

void print(TreeNode *root)
{
    if (root != nullptr)
    {
        // 前序遍历
        cout << root->val << " ";

        if (root->left)
            print(root->left);
        if (root->right)
            print(root->right);
    }
    else if (root == nullptr)
    {
        return;
    }
}

bool VerifySquenceOfBST(vector<int> sequence)
{
}

int main()
{
    // 测试用例
    vector<int> nums = {4, 8, 6, 12, 16, 14, 10};
    TreeNode *p = creatBinarySearchTree(nums);
    print(p);
    // TreeNode *h = Convert(p);

    // int size, idx = 0;
    // cin >> size;
    // vector<int> nums(size);
    // while (cin >> nums[idx++] && idx < size)
    //     ;
    // TreeNode *p = creatBinarySearchTree(nums);
    // print(p);

    return 0;
}
