/*
 * @Description: 剑指 Offer 62. 圆圈中最后剩下的数字。模拟法
 * @Author: Mr. Lee
 * @Date: 2021-06-24 15:35:32
 * @LastEditTime: 2021-06-26 15:46:54
 * @LastEditors: Mr. Lee
 */

/*
    按照题目要求，使用数组进行模拟
*/

#include <iostream>
#include <vector>

using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if (n <= 0)
        return -1;

    vector<int> num(n);
    int idx = 0;
    for (int i = 0; i < n; num[i] = i, i++)
        ;

    while (num.size() > 1)
    {
        //每次删除第 m 个,从当前 idx 的基础上，加上m-1
        idx = (idx + m - 1) % n;
        num.erase(num.begin() + idx);
        n--;
    }

    return num.front();
}

int main()
{
    // 测试用例
    // int n = 5;
    // int m = 3;

    int n;
    int m;
    cin >> n >> m;
    int ans = LastRemaining_Solution(n, m);
    cout << ans << endl;

    return 0;
}