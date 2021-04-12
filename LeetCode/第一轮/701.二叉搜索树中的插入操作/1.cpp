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

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        TreeNode *temp = new TreeNode();
        temp->val = val;
        return temp;
    }
    if (root->val < val)
        root->right = insertIntoBST(root->right, val);
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);

    return root;
}

int main()
{
    int i = 5, null = 0, target = 5;
    int a[i] = {4,2,7,1,3};
    TreeNode *root;
    CreateTree(root, a, i, 0);
    // print(root);
    // cout << endl;
    TreeNode * ans = insertIntoBST(root, target);
    print(root);
    cout << ans << endl;

    return 0;
}
