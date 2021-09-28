/*
 * @Description: 二叉树中两个结点的最短距离
 * @Author: Mr. Lee
 * @Date: 2021-09-27 09:56:52
 * @LastEditTime: 2021-09-27 11:01:07
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode *left, *right;
    BinaryTreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void createBinaryTree(BinaryTreeNode **pRoot, vector<char> &nums, int index)
{
    *pRoot = nullptr;

    if (index < nums.size() && nums[index] != '#')
    {
        *pRoot = new BinaryTreeNode(nums[index] - '0');
        createBinaryTree(&((*pRoot)->left), nums, 2 * index + 1);
        createBinaryTree(&((*pRoot)->right), nums, 2 * (index + 1));
    }
}

bool GetNodePath(BinaryTreeNode *pRoot, int pNode, vector<BinaryTreeNode *> &path)
{
    bool found = false;

    path.push_back(pRoot);

    if (pRoot->val == pNode)
        return true;

    if (!found && pRoot->left)
        found = GetNodePath(pRoot->left, pNode, path);

    if (!found && pRoot->right)
        found = GetNodePath(pRoot->right, pNode, path);

    if (!found)
        path.pop_back();

    return found;
}

int GetLastCommonNode(vector<BinaryTreeNode *> &path1, vector<BinaryTreeNode *> &path2)
{
    vector<BinaryTreeNode *>::iterator it1 = path1.begin();
    vector<BinaryTreeNode *>::iterator it2 = path2.begin();
    BinaryTreeNode *pLast;

    while (it1 != path1.end() && it2 != path2.end())
    {
        if (*it1 == *it2)
            pLast = *it1;
        it1++, it2++;
    }

    return pLast->val;
}

void print(vector<BinaryTreeNode *> &path)
{
    for (auto it = path.begin(); it != path.end(); it++)
        cout << (*it)->val << " ";
    cout << endl;
}

int main(void)
{
    BinaryTreeNode *pRoot;
    vector<char> nums;
    while (1)
    {
        char tmp;
        cin >> tmp;
        nums.push_back(tmp);
        if (cin.get() == '\n')
            break;
    }
    createBinaryTree(&pRoot, nums, 0);

    vector<BinaryTreeNode *> path1, path2, path3;

    cout << "请输入结点字符：" << endl;
    int src, dst;
    cin >> src >> dst;
    GetNodePath(pRoot, src, path1);
    GetNodePath(pRoot, dst, path2);

    int common = GetLastCommonNode(path1, path2);
    GetNodePath(pRoot, common, path3);

    cout << "pRoot->src 路径：" << endl;
    print(path1);
    cout << "pRoot->dst 路径：" << endl;
    print(path2);
    cout << "pRoot->common 路径：" << endl;
    print(path3);

    int distance = path1.size() + path2.size() - 2 * path3.size();

    cout << src << " with " << dst << " distance is " << distance << endl;

    return 0;
}