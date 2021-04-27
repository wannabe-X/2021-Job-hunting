#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// 参考代码
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void CreateTree(TreeNode *&T, int *a, int len, int loc)
{
    if (loc >= len)
    {
        T = NULL;
        return;
    }

    T = new TreeNode(a[loc]);
    // T->val = a[loc];
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

// 递归法
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    // 后序遍历
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    return root;
}

int main()
{
    int n = 9, null = 0;
    int a[n] = {6, 2, 8, 0, 4, 7, 9, null, null, 3, 5};
    int p = 2, q = 8;
    TreeNode *head;
    CreateTree(head, a, n, 0);
    // TreeNode *ans = lowestCommonAncestor(head, p, q);
    // cout << ans << endl;

    return 0;
}
