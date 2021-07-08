/*
 * @Description: 中序遍历二叉树。
 * @Author: Mr. Lee
 * @Date: 2021-07-08 15:38:58
 * @LastEditTime: 2021-07-08 17:41:15
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

// 中序遍历二叉树。递归法
void inOrder_recursion(TreeNode *root)
{
    if (root == nullptr)
        return;

    inOrder_recursion(root->left);
    cout << root->val << " ";
    inOrder_recursion(root->right);
}

// 中序遍历二叉树。非递归法
// void inOrder_not_recursion(TreeNode *root)
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
//                 s.push(make_pair(root, true));
//                 s.push(make_pair(root->left, false));
//             }
//         }
//     }
// }

void inOrder_not_recursion(TreeNode *root)
{
    if (root == nullptr)
        cout << "空树。" << endl;
    stack<TreeNode *> s;
    TreeNode *p = root;

    while (!s.empty() || p)
    {
        for (; p; p = p->left)
        {
            s.push(p);
        }

        if (!s.empty())
        {
            cout << s.top()->val << " "; // 中序遍历
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

    cout << "中序遍历二叉树(递归): " << endl;
    inOrder_recursion(pRoot);
    cout << endl;

    cout << "中序遍历二叉树(非递归): " << endl;
    inOrder_not_recursion(pRoot);
    cout << endl;

    return 0;
}
