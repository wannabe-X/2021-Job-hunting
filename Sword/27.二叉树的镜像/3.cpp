#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

// 参考代码
struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

// 采用传引用的方式创建一棵树
void CreateTree(TreeNode *&T, int *a, int len, int loc)
{
    if (loc >= len)
    {
        T = NULL;
        return;
    }

    T = (TreeNode *)malloc(sizeof(TreeNode));
    T->val = a[loc];
    CreateTree(T->left, a, len, 2 * loc + 1);
    CreateTree(T->right, a, len, 2 * (loc + 1));
}

void print(TreeNode *T)
{
    if (T == NULL)
    {
        return;
    }
    cout << T->val << " ";
    print(T->left);
    print(T->right);
    return;
}

// 解法3 非迭代 参考代码 
// 使用栈
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    stack<TreeNode *> myStk;
    // 将左子树加入队列
    myStk.push(root->left);
    // 将右子树加入队列
    myStk.push(root->right);
    while (!myStk.empty())
    {
        // 判断这这两个树是否相互翻转
        TreeNode *leftNode = myStk.top();
        myStk.pop();
        TreeNode *rightNode = myStk.top();
        myStk.pop();
        // 左节点为空、右节点为空，此时说明是对称的
        if (leftNode == nullptr && rightNode == nullptr)
            continue;
        
        // 左右一个节点不为空，或者都不为空但数值不相同，返回false
        if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val)
            return false;

        myStk.push(leftNode->left);
        myStk.push(rightNode->right);
        myStk.push(leftNode->right);
        myStk.push(rightNode->left);
    }
    return true;
}

int main()
{
    int i = 7, a[i] = {1, 2, 2, 3, 4, 4, 3};
    TreeNode *p;
    CreateTree(p, a, i, 0);
    cout << boolalpha << isSymmetric(p) << endl;

    return 0;
}
