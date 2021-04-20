#include <iostream>
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

// 参考代码
// 注意何时返回的条件
bool isContain(TreeNode *A, TreeNode *B)
{
    if (B == NULL)
        return true;
    if (A == NULL || A->val != B->val)
        return false;

    return isContain(A->left, B->left) && isContain(A->right, B->right);
}

bool isSubStructure(TreeNode *A, TreeNode *B)
{
    if (A == NULL || B == NULL)
        return false;
    return isContain(A, B) || isContain(A->left, B) || isContain(A->right, B);
}

int main()
{
    int i = 5, a[i] = {3, 4, 5, 1, 2};
    TreeNode *p;
    CreateTree(p, a, i, 0);

    int j = 2, b[j] = {4, 1};
    TreeNode *q;
    CreateTree(q, b, j, 0);

    bool ans = isSubStructure(p, q);
    cout << boolalpha << ans << endl;

    return 0;
}
