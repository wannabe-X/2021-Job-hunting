#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():left(NULL), right(NULL) {}
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

// 参考代码
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); i++)
            dic[inorder[i]] = i;
        return recur(0, 0, inorder.size() - 1);
    }

private:
    vector<int> preorder;
    unordered_map<int, int> dic;
    TreeNode *recur(int root, int left, int right)
    {
        if (left > right)
            return nullptr;                                     // 递归终止
        TreeNode *node = new TreeNode(preorder[root]);          // 建立根节点
        int i = dic[preorder[root]];                            // 划分根节点、左子树、右子树
        node->left = recur(root + 1, left, i - 1);              // 开启左子树递归
        node->right = recur(root + i - left + 1, i + 1, right); // 开启右子树递归
        return node;                                            // 回溯返回根节点
    }
};

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    Solution sol;
    TreeNode * ans = sol.buildTree(preorder, inorder);
    print(ans);
    return 0;
}
