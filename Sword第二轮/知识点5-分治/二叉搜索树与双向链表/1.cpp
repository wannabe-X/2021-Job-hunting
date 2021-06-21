/*
 * @Description: 二叉搜索树与双向链表。分治算法
 * @Author: Mr. Lee
 * @Date: 2021-06-17 17:10:57
 * @LastEditTime: 2021-06-18 17:48:15
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

TreeNode *insertion(TreeNode *root, int x)
{
    TreeNode *p = new TreeNode(x);

    if (root == nullptr)
    {
        root = p;
    }
    else if (x > root->val)
    {
        root->right = insertion(root->right, x);
    }
    else if (x < root->val)
    {
        root->left = insertion(root->left, x);
    }

    return root;
}

TreeNode *creatBinarySearchTree(vector<int> &ptr)
{
    // 此处的p是个根节点
    TreeNode *p = new TreeNode(ptr[0]);

    for (int i = 1; i < ptr.size(); i++)
    {
        // 每次插入都从根节点出发
        insertion(p, ptr[i]);
    }

    return p;
}

void print(TreeNode *root)
{
    if (root != nullptr)
    {
        // 前序遍历
        cout << root->val << endl;

        if (root->left)
            print(root->left);
        if (root->right)
            print(root->right);
    }
    else if (root == nullptr)
    {
        return;
    }
}

TreeNode *head = NULL;
TreeNode *last = NULL;

void BuildDequeue(TreeNode *node)
{
    if (node == NULL)
        return;

    // 中序遍历，访左->访中(处理)->访右
    BuildDequeue(node->left);
    if (head == nullptr)
    {
        head = node;
        last = node;
    }
    else
    {
        last->right = node;
        node->left = last;
        last = node;
    }
    BuildDequeue(node->right);
}

TreeNode *Convert(TreeNode *pRootOfTree)
{
    BuildDequeue(pRootOfTree);
    return head;
}

int main()
{
    // 测试用例
    // int arr[7] = {10, 6, 14, 4, 8, 12, 16};
    // TreeNode *p = creatBinarySearchTree( arr);
    // print(p);
    // TreeNode *h = Convert(p);

    int size, idx = 0;
    cin >> size;
    vector<int> nums(size);
    while (cin >> nums[idx++] && idx < size)
        ;
    TreeNode *p = creatBinarySearchTree(nums);
    print(p);
    TreeNode *h = Convert(p);

    for (auto tmp = h; tmp; tmp = tmp->right)
        cout << tmp->val << " ";

    return 0;
}
