/*
 * @Description: 825. 适龄的朋友
 * @Author: Mr. Lee
 * @Date: 2021-12-27 11:23:14
 * @LastEditTime: 2021-12-27 11:46:02
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numFriendRequests(vector<int> &ages)
{
    int n = ages.size();
    sort(ages.begin(), ages.end());
    int left = 0, right = 0, ans = 0;
    for (int age : ages)
    {
        if (age < 15)
        {
            continue;
        }
        while (ages[left] <= 0.5 * age + 7)
        {
            ++left;
        }
        while (right + 1 < n && ages[right + 1] <= age)
        {
            ++right;
        }
        ans += right - left;
    }
    return ans;
}

int main(int argc, char *argv[])
{
    return 0;
}