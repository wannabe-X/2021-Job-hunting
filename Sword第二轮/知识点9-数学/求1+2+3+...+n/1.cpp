/*
 * @Description: 求1+2+3+...+n。先使用递归，然后再改进
 * @Author: Mr. Lee
 * @Date: 2021-06-26 10:19:24
 * @LastEditTime: 2021-06-26 10:25:32
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int Sum_Solution(int n)
{
    if (n == 0)
        return 0;
    return n + Sum_Solution(n - 1);
}

int main()
{
    int n = 10;
    int ans = Sum_Solution(n);
    cout << ans << endl;

    return 0;
}
