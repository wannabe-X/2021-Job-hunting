#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
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

// TreeNode *getMin(TreeNode *node)
// {
//     while (node->left != NULL)
//         node = node->left;
//     return node;
// }

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->val == key)
    {
        // case 1: �ýڵ�û�������Һ���
        // if (root->left == NULL && root->right == NULL)
        //     return NULL;
        // case 2: �ýڵ�Ҫô������ Ҫô���Һ���
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;
        // case 3���ýڵ�������������к���
        if (root->left != NULL && root->right != NULL)
        {
            // �����ҵ�����������Сֵ�Ľ���ַ
            // TreeNode *minNode = getMin(root);
            TreeNode *minNode = root->right;
            while (minNode->left != NULL)
                minNode = minNode->left;
            // ���ýڵ��ֵ����Сֵ�滻
            root->val = minNode->val;
            // Ȼ�����Ըýڵ���Һ���Ϊ��㣬�ݹ�ɾ����Сֵ
            root->right = deleteNode(root->right, minNode->val);
        }
    }
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val > key)
        root->left = deleteNode(root->left, key);

    return root;
}

int main()
{
    int i = 7, null = 0, target = 3;
    int a[i] = {5,3,6,2,4,null,7};
    TreeNode *root;
    CreateTree(root, a, i, 0);
    bool ans = deleteNode(root, target);
    print(root);
    cout << endl;
    cout << ans << endl;

    return 0;
}
