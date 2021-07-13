/*
 * @Description: 275. H 指数 II
 * @Author: Mr. Lee
 * @Date: 2021-07-09 14:20:44
 * @LastEditTime: 2021-07-09 15:25:22
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

// int left_bound(vector<int> &citations, int cite)
// {
//     int i = 0, j = citations.size();
//     int tmp = 0;
//     while (i < j)
//     {
//         int mid = i + (j - i) / 2;
//         if (citations[mid] < cite)
//             i = mid + 1;
//         else
//             j = mid;
//     }

//     return (citations.size() - i <= cite) ? citations.size() - i : 0;
// }

// int hIndex(vector<int> &citations)
// {
//     int ans = 0;
//     for (int cite : citations)
//     {
//         ans = max(ans, left_bound(citations, cite));
//     }
//     return ans;
// }

int hIndex(vector<int> &citations)
{
    int ans = 0;
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] >= citations.size() - i)
            ans = max(ans, int(citations.size() - i));
    }
    return ans;
}

int main()
{
    vector<int> citations = {0,1,3,5,6,7,8};
    int ans = hIndex(citations);
    cout << ans << endl;

    return 0;
}
