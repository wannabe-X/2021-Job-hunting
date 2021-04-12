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

bool findInBST(TreeNode *root, int target)
{
    if (root == NULL)
        return false;
    if (root->val == target)
        return true;
    if (root->val < target)
        return findInBST(root->right, target);
    else
        return findInBST(root->left, target);
}

int main()
{
    int i = 3, null = 0, target = 3;
    int a[i] = {1, 2, 3};
    TreeNode *root;
    CreateTree(root, a, i, 0);
    // print(root);
    // cout << endl;
    bool ans = findInBST(root, target);
    cout << ans << endl;

    return 0;
}
