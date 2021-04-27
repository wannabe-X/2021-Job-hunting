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

// 迭代法
// TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
// {
//     // 保证p->val是最小的
//     if (p->val > q->val)
//     {
//         TreeNode *temp = p;
//         p = q;
//         q = temp;
//     }

//     while (root != nullptr)
//     {
//         // 最小的p->val 大于 根节点的值
//         // 那么root向右走，说明公共根节点一定在右侧
//         if (p->val > root->val)
//             root = root->right;
//         // 最大的q->val 小于 根节点的值
//         // 那么root向左走，说明公共根节点一定在左侧
//         else if (q->val < root->val)
//             root = root->left;
//         // 当二者的出现分歧的时候，也就是说p->val < root->val < q->val的时候，此时root就是他们的公共祖先
//         else
//             break;
//     }

//     return root;
// }

// 递归法
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    return root;
}

int main()
{
    int n = 9, null = 0;
    int a[n] = {6, 2, 8, 0, 4, 7, 9, null, null, 3, 5};
    int p = 2, q = 8;
    TreeNode *head;
    CreateTree(head, a, n, 0);
    // TreeNode *ans = lowestCommonAncestor(head, p, q);
    // cout << ans << endl;

    return 0;
}
