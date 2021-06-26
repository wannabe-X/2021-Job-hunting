/*
 * @Description: 求1+2+3+...+n。先使用递归，改进递归机制
 * @Author: Mr. Lee
 * @Date: 2021-06-26 10:19:24
 * @LastEditTime: 2021-06-26 10:40:58
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

// 利用短路运算符终止递归，以替代递归中的if条件判断
using namespace std;

int res = 0;

int Sum_Solution(int n)
{
    bool x = n > 1 && Sum_Solution(n - 1);
    res += n;
    return res;
}

int main()
{
    // 测试用例
    // int n = 10;

    //
    int n;
    cin >> n;
    int ans = Sum_Solution(n);
    cout << ans << endl;

    return 0;
}
