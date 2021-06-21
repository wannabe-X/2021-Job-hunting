/*
 * @Description: 和为S的连续正数序列
 * @Author: Mr. Lee
 * @Date: 2021-06-21 10:55:53
 * @LastEditTime: 2021-06-21 11:23:34
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> FindContinuousSequence(int sum)
{
    vector<vector<int>> res;
    vector<int> tmp;
    int tmpsum = 0;

    for (int i = 1; i <= sum / 2 + 1; i++)
    {
        tmpsum += i;
        tmp.push_back(i);

        while (tmpsum > sum)
        {
            auto it = tmp.begin();
            tmpsum -= *it;
            tmp.erase(it);
        }

        if (tmpsum == sum && tmp.size() > 1)
            res.push_back(tmp);
    }

    return res;
}

int main()
{
    // 测试用例
    // int sum = 10;

    int sum;
    cin >> sum;
    vector<vector<int>> ans = FindContinuousSequence(sum);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int num : ans[i])
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
