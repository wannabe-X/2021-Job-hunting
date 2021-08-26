/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-24 09:58:17
 * @LastEditTime: 2021-08-24 12:38:26
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool func(int num)
{
    unordered_map<int, int> m;
    while (num)
    {
        int tmp = num % 10;
        m[tmp]++;
        if (m[tmp] > 1)
            return false;
        num /= 10;
    }

    return true;
}

int uniqueNum(int n)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (func(i))
            res++;
    }

    return res;
}

int main()
{
    int n;
    while (1)
    {
        cout << "输入：";
        cin >> n;
        if (n == 0)
            break;
        int ans = uniqueNum(n);
        cout << "输出：" << ans << endl;
    }

    return 0;
}
