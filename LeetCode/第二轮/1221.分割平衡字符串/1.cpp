/*
 * @Description: 1221. 分割平衡字符串
 * @Author: Mr. Lee
 * @Date: 2021-09-07 00:02:14
 * @LastEditTime: 2021-09-07 00:06:31
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 贪心算法
int balancedStringSplit(string s)
{
    int res = 0, d = 0;
    for (auto &c : s)
    {
        c == 'L' ? ++d : --d;
        if (d == 0)
            res++;
    }

    return res;
}

int main(void)
{
    string s = "RLRRLLRLRL";
    int ans = balancedStringSplit(s);
    cout << ans << endl;

    return 0;
}
