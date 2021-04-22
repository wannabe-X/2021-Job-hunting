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

void midWalk(TreeNode *root, vector<int> &nums)
{
    if (root == NULL)
    {
        return;
    }

    midWalk(root->left, nums);
    nums.push_back(root->val);
    midWalk(root->right, nums);
}

int kthLargest(TreeNode *root, int k)
{
    vector<int> nums;
    midWalk(root, nums);
    return nums[nums.size() - k];
}

int main()
{
    int n = 1, null = 0;
    int k = 1;
    int a[n] = {5};
    TreeNode *head;
    CreateTree(head, a, n, 0);
    int ans = kthLargest(head, k);
    cout << ans << endl;

    return 0;
}
