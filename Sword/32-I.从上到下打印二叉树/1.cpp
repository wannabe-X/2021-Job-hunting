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

vector<int> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<int> res;
    res.push_back(root->val);
    queue<TreeNode *> myQue;
    myQue.push(root->left);
    myQue.push(root->right);
    while (!myQue.empty())
    {
        TreeNode *leftNode = myQue.front();
        myQue.pop();
        TreeNode *rightNode = myQue.front();
        myQue.pop();

        if (leftNode != nullptr)
        {
            res.push_back(leftNode->val);
            myQue.push(leftNode->left);
            myQue.push(leftNode->right);
        }

        if (rightNode != nullptr)
        {
            res.push_back(rightNode->val);
            myQue.push(rightNode->left);
            myQue.push(rightNode->right);
        }
    }
    return res;
}

int main()
{
    int n = 2;
    int a[n] = {1};
    TreeNode *head;
    CreateTree(head, a, n, 0);
    vector<int> ans = levelOrder(head);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ' << endl;

    return 0;
}
