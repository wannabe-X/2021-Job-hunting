/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-27 11:27:13
 * @LastEditTime: 2021-08-27 11:42:05
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <queue>
using namespace std;

struct BiTNode //二叉树的结点数据结构
{
    int data;
    BiTNode *lchild, *rchild;
};

BiTNode *CreateBiTree(vector<int> &a, int n, int start) //按层序输入，结点为空时，输入'#'
{
    if (a[start] == '#')
        return NULL;

    BiTNode *root = new BiTNode; //新建一个根结点
    root->data = a[start];       //给根结点 root 的 成员变量 data、lchild、rchild 赋初值
    root->lchild = NULL;
    root->rchild = NULL;

    int lnode = 2 * start + 1;
    int rnode = 2 * start + 2;

    if (lnode > n - 1)
        root->lchild = NULL;
    else
        root->lchild = CreateBiTree(a, n, lnode);

    if (rnode > n - 1)
        root->rchild = NULL;
    else
        root->rchild = CreateBiTree(a, n, rnode);

    return root;
}

int TreeDepth(BiTNode *pRoot)
{
    int height = 0;

    if (pRoot != nullptr)
    {
        height++;
        int max_left = TreeDepth(pRoot->lchild);
        int max_right = TreeDepth(pRoot->rchild);
        height += max(max_left, max_right);
    }
    return height;
}

int treeMaxWidthNoMap(BiTNode *head)
{
    int maxWidth = 0;
    if (head == nullptr)
    {
        return maxWidth;
    }

    // 用队列实现
    queue<BiTNode *> q;
    q.push(head);
    BiTNode *curEnd = head;     //记录当前层的尾巴
    BiTNode *nextEnd = nullptr; //记录下一层的尾巴
    int curWidth = 0;

    while (!q.empty())
    {
        BiTNode *node = q.front();
        q.pop();

        // 更新下一层尾巴
        if (node->lchild != nullptr)
        {
            q.push(node->lchild);
            nextEnd = node->lchild;
        }
        if (node->rchild != nullptr)
        {
            q.push(node->rchild);
            nextEnd = node->rchild;
        }
        curWidth++;

        // 如果当前结点是该层的尾巴
        if (node == curEnd)
        {
            maxWidth = max(maxWidth, curWidth);
            curWidth = 0;
            curEnd = nextEnd;
        }
    }
    return maxWidth;
}

int main()
{
    BiTNode *t;
    vector<int> data = {1, 1, 1, 1, 1, 1, 1};
    t = CreateBiTree(data, data.size(), 0);
    cout << "深度：" << TreeDepth(t) << endl;
    cout << "宽度：" << treeMaxWidthNoMap(t) << endl;
}
