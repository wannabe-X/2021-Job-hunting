/*
 * @Description: 1713. 得到子序列的最少操作次数
 * @Author: Mr. Lee
 * @Date: 2021-07-26 00:09:22
 * @LastEditTime: 2021-07-26 01:11:45
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minOperations(vector<int> &target, vector<int> &arr)
{
    unordered_map<int, int> m;
    for (int i = 0; i < target.size(); i++)
    {
        m[target[i]] = i;
    }

    vector<int> tmp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (m.count(arr[i]))
        {
            int idx = m[arr[i]];
            // 如果在tmp中，则返回第一个大于等于idx的元素的下标，否则返回tmp.end()
            // 如果返回tmp.end()，则说明target中arr[i]这个元素之前的元素没有出现过
            // 将idx插入到tmp中，之后如果arr中出现target中在arr[i]之前的元素，则是添加不进来的
            // 以此来保证先后顺序
            auto it = lower_bound(tmp.begin(), tmp.end(), idx);
            if (it == tmp.end())
                tmp.push_back(idx);
            else
                *it = idx;
        }
    }

    return target.size() - tmp.size();
}

int main()
{
    vector<int> target = {6,4,8,1,3,2}, arr = {4,7,6,2,3,8,6,1,4};
    int ans = minOperations(target, arr);
    cout << ans << endl;

    return 0;
}
