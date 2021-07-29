/*
 * @Description: 1104. 二叉树寻路
 * @Author: Mr. Lee
 * @Date: 2021-07-29 11:00:59
 * @LastEditTime: 2021-07-29 11:55:21
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> pathInZigZagTree(int label)
{
    vector<int> res;
    res.push_back(label);

    int real;
    while (label > 1)
    {
        int layer = log2(label) + 1;
        if ((layer - 1) % 2 == 0)
        {
            // 还原二叉树中的真实位置，根据真实位置寻找上一层的节点
            real = pow(2, layer) - 1 - label + pow(2, layer - 1);
            label = real / 2;
        }
        else
        {
            label = label / 2;
        }

        res.push_back(label);
        
        layer = log2(label) + 1;
        if (layer % 2 == 0)
            label = pow(2, layer) - 1 - label + pow(2, layer - 1);
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    int label = 26;
    vector<int> ans = pathInZigZagTree(label);
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
