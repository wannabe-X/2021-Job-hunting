/*
 * @Description: 剑指 Offer II 069. 山峰数组的顶部
 * @Author: Mr. Lee
 * @Date: 2021-10-14 10:29:36
 * @LastEditTime: 2021-10-14 10:33:44
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > arr[res])
        {
            res = i;
        }
    }

    return res;
}

int main(void)
{
    vector<int> arr = {1, 3, 5, 4, 2};
    int ans = peakIndexInMountainArray(arr);
    cout << ans << endl;
    
    return 0;
}