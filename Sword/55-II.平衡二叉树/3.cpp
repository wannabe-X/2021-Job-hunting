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

int depth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    int n = 9, null = 0;
    int a[n] = {1, 2, 2, 3, 3, null, null, 4, 4};
    TreeNode *head;
    CreateTree(head, a, n, 0);
    int ans = isBalanced(head);
    cout << ans << endl;

    return 0;
}
