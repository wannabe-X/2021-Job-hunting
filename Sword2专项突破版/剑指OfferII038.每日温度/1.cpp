/*
 * @Description: 剑指 Offer II 038. 每日温度
 * @Author: Mr. Lee
 * @Date: 2021-08-25 15:10:59
 * @LastEditTime: 2021-08-25 15:49:44
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 会超时的解法，不采用
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> res;
    int flag = 0;
    for (int i = 0; i < temperatures.size(); i++)
    {
        flag = 0;
        for (int j = i + 1; j < temperatures.size(); j++)
        {
            if (temperatures[j] > temperatures[i])
            {
                res.push_back(j - i);
                flag = 1;
                break;
            }
        }
        if (!flag)
            res.push_back(0);
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(temperatures);
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}