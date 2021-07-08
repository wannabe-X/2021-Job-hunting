/*
 * @Description: 前序遍历二叉树。
 * @Author: Mr. Lee
 * @Date: 2021-07-08 15:38:58
 * @LastEditTime: 2021-07-08 17:51:10
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

// 前序遍历二叉树。递归法
void preorder_recursion(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preorder_recursion(root->left);
    preorder_recursion(root->right);
}

// 前序遍历二叉树。非递归法
// void preorder_not_recursion(TreeNode *root)
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
//                 s.push(make_pair(root->right, false));
//                 s.push(make_pair(root->left, false));
//                 s.push(make_pair(root, true));
//             }
//         }
//     }
// }

// 前序遍历二叉树。非递归法，改进版本
void preorder_not_recursion(TreeNode *root)
{
    if (root == nullptr)
        cout << "空树。" << endl;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (!s.empty() || p)
    {
        for (; p; p = p->left)
        {
            cout << p->val << " ";
            s.push(p);
        }

        if(!s.empty()){
            p = s.top()->right;
            s.pop();
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

    cout << "前序遍历二叉树(递归): " << endl;
    preorder_recursion(pRoot);
    cout << endl;

    cout << "前序遍历二叉树(非递归): " << endl;
    preorder_not_recursion(pRoot);
    cout << endl;

    return 0;
}
