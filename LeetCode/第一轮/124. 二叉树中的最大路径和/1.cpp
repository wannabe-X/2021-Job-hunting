/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <limits.h>
#include <algorithm>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        oneSideMax(root);
        return ans;
    }

    int oneSideMax(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = max(0, oneSideMax(root->left));
        int right = max(0, oneSideMax(root->right));
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
};