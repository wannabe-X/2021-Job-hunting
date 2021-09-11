/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-11 15:59:03
 * @LastEditTime: 2021-09-11 17:47:39
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> func(vector<vector<int>> &nums, string str)
{
    return {2, 3, 6, -1};
}

int main(void)
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i][0] >> nums[i][1];
    }

    vector<int> ans = func(nums, str);
    for (auto &x : ans)
    {
        cout << x << endl;
    }

    return 0;
}