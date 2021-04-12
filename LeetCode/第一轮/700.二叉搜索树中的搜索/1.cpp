#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

void CreateTree(TreeNode *&T, int *a, int len, int loc)
{
    if (loc >= len)
    {
        T = NULL;
        return;
    }

    T = new TreeNode();
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

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->val == val)
        return root;
    if (root->val < val)
        return searchBST(root->right, val);
    else
        return searchBST(root->left, val);
}

int main()
{
    int i = 3, null = 0, target = 3;
    int a[i] = {1, 2, 3};
    TreeNode *root;
    CreateTree(root, a, i, 0);
    // print(root);
    // cout << endl;
    bool ans = searchBST(root, target);
    cout << ans << endl;

    return 0;
}
