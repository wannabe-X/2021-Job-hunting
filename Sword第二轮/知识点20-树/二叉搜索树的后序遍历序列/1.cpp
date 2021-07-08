/*
 * @Description: 二叉搜索树的后序遍历序列
 * @Author: Mr. Lee
 * @Date: 2021-07-07 23:22:42
 * @LastEditTime: 2021-07-07 23:49:39
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <stack>

// 使用单调栈
using namespace std;

bool VerifySquenceOfBST(vector<int> &seq)
{
    if (seq.size() < 1)
        return false;
        
    int root = INT_MAX;
    stack<int> roots;

    for (int i = seq.size() - 1; i > -1; i--)
    {
        if (seq[i] > root)
            return false;

        while (!roots.empty() && seq[i] < roots.top())
        {
            root = roots.top();
            roots.pop();
        }

        roots.push(seq[i]);
    }

    return true;
}

int main()
{
    vector<int> seq = {4, 8, 6, 12, 16, 14, 10};
    bool ans = VerifySquenceOfBST(seq);
    cout << boolalpha << ans << endl;

    return 0;
}
