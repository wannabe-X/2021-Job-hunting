#include <iostream>
#include <algorithm>
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

bool recur(TreeNode *L, TreeNode *R)
{
    if (L == NULL && R == NULL)
        return true;
    if (L == NULL || R == NULL || L->val != R->val)
        return false;

    return recur(L->left, R->right) && recur(L->right, R->left);
}

bool isSymmetric(TreeNode *root)
{
    return root == NULL ? true : recur(root->left, root->right);
}

int main()
{
    int i = 7, a[i] = {1, 2, 2, 3, 4, 4, 3};
    TreeNode *p;
    CreateTree(p, a, i, 0);
    cout << boolalpha << isSymmetric(p) << endl;

    return 0;
}
