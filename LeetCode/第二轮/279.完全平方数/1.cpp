/*
 * @Description: leetcode 279. 完全平方数。动态规划法
 * @Author: Mr. Lee
 * @Date: 2021-06-11 10:11:28
 * @LastEditTime: 2021-06-11 10:56:15
 * @LastEditors: Mr. Lee
 */

/*
    解题思路：动态规划，转换成01背包问题
        f[i] 表示最少需要多少个数的平方来表示整数 i。
        对于每一个数n，都从[1,sqrt(n)]遍历，如果背包能装下，则取最小，且操作数加1。
*/
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int numSquares(int n)
{
    int count = 0;
    vector<int> res(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        int tmp = (int)sqrt(i);
        res[i]  =INT_MAX;
        for (int j = 1; j <= tmp; j++)
        {
            res[i] = min(res[i], res[i - j * j] + 1);
        }
    }
    
    return res[n];
}

int main()
{
    // 测试用例
    // int n = 13;
    // int ans = numSquares(n);
    
    int n;
    cin >> n;
    int ans = numSquares(n);

    cout << ans << endl;
    return 0;
}
