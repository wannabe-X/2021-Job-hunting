/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2022-03-19 18:58:21
 * @LastEditTime: 2022-03-19 19:37:58
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> func(vector<int> nums)
{
    vector<int> res(nums.size());
    int idx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] & 1 == 0)
            res[idx++] = nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] & 1 == 1)
            res[idx++] = nums[i];
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