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

// 参考解法 利用队列先进先出的性质
vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;
    q.push(root);

    while (!q.empty())
    {
        vector<int> temp;
        // int len = q.size();
        // for (int i = 0; i < len; i++)
        // for 循环的定义， 第一项是初始化，第二项是判断。初始化只执行一次
        // 尽管循环过程中q.size()是变化的，但是int i=q.size()用于初始化
        // 写成for (int i = 0; i < q.size(); i++)是不对的，因为在循环过程中，q.size()是变化的
        // 保证每打印完一层的值，该层的结点在队列都已清空，队列中保留的是下一层结点的地址
        for (int i = q.size(); i > 0; i--)
        {
            TreeNode *node = q.front();
            q.pop();
            temp.push_back(node->val);

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n = 5;
    int a[n] = {1, 2, 3, 4, 5};
    TreeNode *head;
    CreateTree(head, a, n, 0);
    vector<vector<int>> ans = levelOrder(head);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
