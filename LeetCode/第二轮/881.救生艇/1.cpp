/*
 * @Description: 881. 救生艇
 * @Author: Mr. Lee
 * @Date: 2021-08-26 09:43:44
 * @LastEditTime: 2021-08-26 10:21:56
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 排序 + 双指针
int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int left = 0, right = people.size() - 1, res = 0;
    while (left < right)
    {
        if (people[left] + people[right] <= limit)
            left++;

        res++;
        right--;
    }

    if (right == left)
        res++;

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> people = {3, 5, 3, 4, 5, 5, 5, 5, 5};
    int limit = 5;
    int ans = numRescueBoats(people, limit);
    cout << ans;

    return 0;
}