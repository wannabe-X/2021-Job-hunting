/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2022-03-19 18:58:21
 * @LastEditTime: 2022-03-19 19:44:45
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> func(vector<int> nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
            res.push_back(nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 1)
            res.push_back(nums[i]);
    }

    return res;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int tmp;
    string str;
    cin >> str;
    replace(str.begin(), str.end(), ',', ' ');

    vector<int> nums;
    stringstream ss;
    ss << str;
    while (ss >> tmp)
    {
        nums.push_back(tmp);
    }

    vector<int> ans = func(nums);
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << ",";
    cout << ans[n - 1];

    return 0;
}