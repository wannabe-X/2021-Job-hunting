#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

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

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int nLeft = maxDepth(root->left);
    int nRight = maxDepth(root->right);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

int main()
{
    int n = 13, null = 0;
    int a[n] = {5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1};
    TreeNode *head;
    CreateTree(head, a, n, 0);
    int ans = maxDepth(head);
    cout << ans << endl;

    return 0;
}
