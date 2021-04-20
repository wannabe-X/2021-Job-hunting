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
    vector<int> res;
    if (root == nullptr)
        return res;
    queue<TreeNode *> myQue;
    myQue.push(root);
    while (!myQue.empty())
    {
        TreeNode *temp = myQue.front();
        res.push_back(temp->val);
        myQue.pop();

        if (temp->left != nullptr)
            myQue.push(temp->left);
        if (temp->right != nullptr)
            myQue.push(temp->right);
    }
    return res;
}

int main()
{
    int null = 0;
    int a[] = {3, 9, 20, null, null, 15, 7};
    TreeNode *head;
    CreateTree(head, a,sizeof(a)/sizeof(a) , 0);
    vector<int> ans = levelOrder(head);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ' << endl;

    return 0;
}
