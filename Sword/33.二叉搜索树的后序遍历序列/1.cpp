#include <iostream>
#include <vector>

using namespace std;

bool verifyPostorder(vector<int> &postorder)
{
    if (postorder.empty())
        return true;

    int root = postorder[postorder.size() - 1];

    // 找到划分左右子树的的分界，i指向右子树的第一个结点
    int i = 0;
    for (; i < postorder.size() - 1; i++)
    {
        if (postorder[i] > root)
            break;
    }

    // 如果右子树违反二叉搜索树的定义
    // 则直接返回false
    for (int j = i; j < postorder.size() - 1; j++)
    {
        if (postorder[j] < root)
            return false;
    }

    bool left = true;
    if (i > 0)
    {
        // vecotr截取操作是左闭右开的
        vector<int> subLeftTree(postorder.begin(), postorder.begin() + i);
        left = verifyPostorder(subLeftTree);
    }

    bool right = true;
    if (i < postorder.size() - 1)
    {
        vector<int> subRightTree(postorder.begin() + i, postorder.end() - 1);
        right = verifyPostorder(subRightTree);
    }

    return (left && right);
}

int main(void)
{
    vector<int> postorder = {1, 3, 2, 6, 5};
    bool ans = verifyPostorder(postorder);
    cout << boolalpha;
    cout << ans << endl;
    return 0;
}