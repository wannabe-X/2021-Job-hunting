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

bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if (root == NULL)
        return true;
    if (min != NULL && root->val <= min->val)
        return false;
    if (max != NULL && root->val >= max->val)
        return false;

    // root->left->val <= root->val <= root->right->val
    return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
}

bool isValidBST(TreeNode *root)
{
    return isValidBST(root, NULL, NULL);
}

int main()
{
    int i = 3, null = 0;
    int a[i] = {1, 2, 3};
    TreeNode *root;
    CreateTree(root, a, i, 0);
    // print(root);
    // cout << endl;
    bool ans = isValidBST(root);
    cout << ans << endl;

    return 0;
}
