/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-09 18:59:22
 * @LastEditTime: 2021-10-09 21:22:06
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> func(vector<int> nums)
{
    unordered_map<int, int> myMap;
    for (auto num : nums)
    {
        myMap[num]++;
    }

    int yzcd = -1;

    for (auto it = myMap.begin(); it != myMap.end(); it++)
    {
        yzcd = max(yzcd, (*it).second);
    }

    vector<int> v;
    for (auto it = myMap.begin(); it != myMap.end(); it++)
    {
        if ((*it).second == yzcd)
        {
            v.push_back((*it).first);
        }
    }

    int start = 0, end = 0, len = INT8_MAX;

    for (int vtmp : v)
    {
        int i = 0;
        for (; i < nums.size() && nums[i] != vtmp; i++)
            ;
        int j = nums.size() - 1;
        for (; j > i && nums[j] != vtmp; j--)
            ;

        if (j - i < len)
        {
            len = j - i;
            start = i + 1;
            end = j + 1;
        }
    }

    return {start, end};
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> ans = func(nums);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}