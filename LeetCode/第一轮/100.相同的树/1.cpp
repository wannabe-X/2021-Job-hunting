#include <iostream>
#include <unordered_map>
using namespace std;

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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    int i = 3, a[i] = {1, 2, 3};
    TreeNode *p;
    CreateTree(p, a, i, 0);

    int j = 3, b[j] = {1, 2, 3};
    TreeNode *q;
    CreateTree(q, b, j, 0);
    // print(root);
    // cout << endl;
    bool ans = isSameTree(p, q);
    cout << ans << endl;

    return 0;
}
