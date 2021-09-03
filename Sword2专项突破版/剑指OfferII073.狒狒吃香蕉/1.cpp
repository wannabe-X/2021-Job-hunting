/*
 * @Description: 剑指 Offer II 073. 狒狒吃香蕉
 * @Author: Mr. Lee
 * @Date: 2021-09-03 10:09:11
 * @LastEditTime: 2021-09-03 10:37:39
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eat_bananas(vector<int> &piles, int speed)
{
    int hour = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        hour += piles[i] / speed;
        if (piles[i] % speed)
            hour += 1;
    }

    return hour;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int hour = eat_bananas(piles, mid);
        if (hour > h)
            left = mid + 1;
        else if (hour == h)
            right = mid - 1;
        else
            right = mid - 1;
    }

    return left;
}

int main(void)
{
    vector<int> piles = {30, 11, 23, 4, 20};
    int H = 6;

    int ans = minEatingSpeed(piles, H);
    cout << ans << endl;

    return 0;
}