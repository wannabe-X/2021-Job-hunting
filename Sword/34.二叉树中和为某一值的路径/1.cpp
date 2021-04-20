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

// 回溯算法
vector<vector<int>> res;
void backtrack(TreeNode *root, vector<int> &path, int tar)
{
    if (root == nullptr)
        return;
    path.push_back(root->val);
    tar -= root->val;

    // 从根节点一直到叶节点
    if (tar == 0 && root->left == nullptr && root->right == nullptr)
        res.push_back(path);
    

    backtrack(root->left, path, tar);
    backtrack(root->right, path, tar);

    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int target)
{
    vector<int> path;
    backtrack(root, path, target);
    return res;
}

int main()
{
    int n = 13, null = 0;
    int a[n] = {5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1};
    TreeNode *head;
    CreateTree(head, a, n, 0);
    int target = 22;
    vector<vector<int>> ans = pathSum(head, target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
