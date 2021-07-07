/*
 * @Description: 重建二叉树
 * @Author: Mr. Lee
 * @Date: 2021-07-05 14:14:15
 * @LastEditTime: 2021-07-05 15:33:26
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

// 详细代码注释篇，使用分治递归的思路
// class Solution
// {
// public:
//     unordered_map<int, int> map;
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
//     {
//         // 将中序序列用哈希表存储，便于查找根节点
//         for (int i = 0; i < inorder.size(); i++)
//             map[inorder[i]] = i;
//         // 传入参数：前序,中序，前序序列根节点，中序序列左边界，中序序列右边界
//         return build(preorder, inorder, 0, 0, inorder.size() - 1);
//     }
//     TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pre_root, int in_left, int in_right)
//     {
//         if (in_left > in_right)
//             return NULL;
//         TreeNode *root = new TreeNode(preorder[pre_root]);
//         // 根节点在中序序列中的位置，用于划分左右子树的边界
//         int in_root = map[preorder[pre_root]];
//         // 左子树在前序中的根节点位于：pre_root+1,左子树在中序中的边界：[in_left,in_root-1]
//         root->left = build(preorder, inorder, pre_root + 1, in_left, in_root - 1);
//         // 右子树在前序中的根节点位于：根节点+左子树长度+1 = pre_root+in_root-in_left+1
//         // 右子树在中序中的边界：[in_root+1,in_right]
//         root->right = build(preorder, inorder, pre_root + in_root - in_left + 1, in_root + 1, in_right);
//         return root;
//     }
// };

unordered_map<int, int> dict;

TreeNode *build(vector<int> &pre, vector<int> &vin, int preRootIdx, int vinLeft, int vinRight)
{
    if (vinLeft > vinRight)
        return nullptr;

    auto root = new TreeNode(pre[preRootIdx]);
    int idx = dict[pre[preRootIdx]];

    root->left = build(pre, vin, preRootIdx + 1, vinLeft, idx - 1);
    root->right = build(pre, vin, preRootIdx + 1 + idx - vinLeft, idx + 1, vinRight);

    return root;
}

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    for (int i = 0; i < vin.size(); i++)
    {
        dict[vin[i]] = i;
    }

    return build(pre, vin, 0, 0, vin.size() - 1);
}

int main()
{
    vector<int> pre = {3, 9, 2, 1, 7},
                vin = {9, 3, 1, 2, 7};
    TreeNode *ans = reConstructBinaryTree(pre, vin);
    printTree(ans);

    return 0;
}
