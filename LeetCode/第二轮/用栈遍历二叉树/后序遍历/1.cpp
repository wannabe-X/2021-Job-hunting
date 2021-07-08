/*
 * @Description: 后序遍历二叉树。
 * @Author: Mr. Lee
 * @Date: 2021-07-08 15:38:58
 * @LastEditTime: 2021-07-08 17:51:49
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void createTree(TreeNode *&T, vector<int> nums, int loc)
{
    if (loc >= nums.size())
        return;

    T = new TreeNode(nums[loc]);
    createTree(T->left, nums, 2 * loc + 1);
    createTree(T->right, nums, 2 * (loc + 1));
}

void printBiTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    printBiTree(root->left);
    printBiTree(root->right);
}

// 后序遍历二叉树。递归法
void postOrder_recursion(TreeNode *root)
{
    if (root == nullptr)
        return;

    postOrder_recursion(root->left);
    postOrder_recursion(root->right);
    cout << root->val << " ";
}

// 后序遍历二叉树。非递归法
// void postOrder_not_recursion(TreeNode *root)
// {
//     stack<pair<TreeNode *, bool>> s;
//     s.push(make_pair(root, false));
//     bool visited;

//     while (!s.empty())
//     {
//         root = s.top().first;
//         visited = s.top().second;
//         s.pop();

//         if (root)
//         {
//             if (visited)
//             {
//                 cout << root->val << " ";
//             }
//             else
//             {
//                 s.push(make_pair(root, true));
//                 s.push(make_pair(root->right, false));
//                 s.push(make_pair(root->left, false));
//             }
//         }
//     }
// }

void postOrder_not_recursion(TreeNode *root)
{
    if (root == nullptr)
        cout << "空树。" << endl;
    stack<TreeNode *> s;
    TreeNode *p = root;
    TreeNode *prev = nullptr;

    while (!s.empty() || p)
    {
        while (p)
        {
            s.push(p);
            p = p->left;
        }
        if (!s.empty())
        {
            auto node = s.top();
            s.pop();
            if (!node->right || node->right == prev)
            {
                cout << node->val << " ";
                prev = node;
            }
            else
            {
                s.push(node);
                p = node->right;
            }
        }
    }
}

int main()
{
    TreeNode *pRoot = nullptr;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    createTree(pRoot, nums, 0);
    // printBiTree(pRoot);
    // cout << endl;

    cout << "后序遍历二叉树(递归): " << endl;
    postOrder_recursion(pRoot);
    cout << endl;

    cout << "后序遍历二叉树(非递归): " << endl;
    postOrder_not_recursion(pRoot);
    cout << endl;

    return 0;
}
