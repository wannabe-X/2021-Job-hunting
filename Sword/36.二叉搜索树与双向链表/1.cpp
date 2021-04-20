#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

void CreateTree(Node *&T, int *a, int len, int loc)
{
    if (loc >= len)
    {
        T = NULL;
        return;
    }

    T = new Node(a[loc]);
    CreateTree(T->left, a, len, 2 * loc + 1);
    CreateTree(T->right, a, len, 2 * (loc + 1));
}

void print(Node *T)
{
    for (; T->val < T->right->val; T = T->right)
        cout << T->val << ' ';
    cout << T->val << endl;
}

// 二叉搜索树 结果要从小到大排序
// 所以使用中序遍历
Node *pre=nullptr, *head;
void dfs(Node *cur)
{
    if (cur == nullptr)
        return;
    dfs(cur->left);
    if (pre != nullptr)
        pre->right = cur; // pre指向cur
    else
        head = cur; // 第一次 让head指向头结点，也就是中序遍历的第一个元素
    cur->left = pre; // cur指向pre
    pre = cur; // pre移动到cur的位置
    dfs(cur->right);
}

Node *treeToDoublyList(Node *root)
{
    if (root == nullptr)
        return nullptr;
    dfs(root);
    head->left = pre;
    pre->right = head;
    return head;
}

int main()
{
    int n = 5, null = 0;
    int a[n] = {4, 2, 5, 1, 3};
    Node *head;
    CreateTree(head, a, n, 0);
    Node *ans = treeToDoublyList(head);
    print(ans);
    // print(head);

    return 0;
}
