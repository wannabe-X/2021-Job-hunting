/*
 * @Description: 869. 重新排序得到 2 的幂
 * @Author: Mr. Lee
 * @Date: 2021-10-28 23:31:14
 * @LastEditTime: 2021-10-28 23:53:21
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string trans(int x)
{ // 将数字x转字符串 然后排序
    auto t = to_string(x);
    sort(t.begin(), t.end());
    return t;
}
bool reorderedPowerOf2(int n)
{
    int x = 1;
    unordered_map<string, bool> mp;
    while (x <= 1e9)
        mp[trans(x)] = true, x <<= 1; //打表2的幂
    return mp[trans(n)];
}

int main(void)
{
    int n = 16;
    bool ans = reorderedPowerOf2(n);
    cout << boolalpha << ans << endl;

    return 0;
}