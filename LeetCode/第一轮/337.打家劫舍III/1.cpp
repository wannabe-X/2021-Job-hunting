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

unordered_map<TreeNode *, int> map;

int rob(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (map[root])
        return map[root];
    if (root->left == NULL && root->right == NULL)
        return root->val;
    int do_it = root->val;
    if (root->left)
        do_it += rob(root->left->left) + rob(root->left->right);
    if (root->right)
        do_it += rob(root->right->left) + rob(root->right->right);

    int not_do = rob(root->left) + rob(root->right);
    map[root] = max(do_it, not_do);

    return max(do_it, not_do);
}

int main()
{
    int i = 7;
    int a[i] = {3, 2, 3, 0, 3, 0, 1};
    TreeNode *root;
    CreateTree(root, a, i, 0);
    // print(root);
    // cout << endl;
    int ans = rob(root);
    cout << ans << endl;

    return 0;
}
