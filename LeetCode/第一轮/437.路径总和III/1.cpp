class Solution
{
public:
    int count(TreeNode *node, int sum)
    {
        if (node == NULL)
            return 0;
        return (node->val == sum) + count(node->left, sum - node->val) + count(node->right, sum - node->val);
    }

    int pathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;
        return count(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};